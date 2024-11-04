#include "encryption.h"

// Define static constants for key, IV, and file path
static const QByteArray KEY = QCryptographicHash::hash("9OlafWojda160203", QCryptographicHash::Sha256); // 256-bit key
static const QByteArray IV = QCryptographicHash::hash("160203OlafWojda9", QCryptographicHash::Md5); // 128-bit IV
static const QString FILE_PATH = "passwords.json.enc";

Encryption::Encryption(QObject *parent)
    : QObject(parent), m_filePath(FILE_PATH), m_key(KEY), m_iv(IV)
{
}

void Encryption::setFilePath(const QString &filePath)
{
    m_filePath = filePath;
}

bool Encryption::addOrUpdateEntry(const QJsonObject &entry) {
    QJsonArray dataArray = loadEntries();
    bool entryFound = false;

    for (int i = 0; i < dataArray.size(); i++) {
        QJsonObject currentEntry = dataArray[i].toObject();

        if (currentEntry["uid"].toString() == entry["uid"].toString()) {
            dataArray[i] = entry;
            entryFound = true;
            break;
        }
    }

    if (!entryFound) {
        dataArray.append(entry);
    }

    QJsonDocument doc(dataArray);
    QByteArray encryptedData = encrypt(doc.toJson());

    QFile file(m_filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(encryptedData.toBase64());
        file.close();
        return true;
    } else {
        return false;
    }
}

bool Encryption::removeEntry(const QString &uid) {
    QJsonArray dataArray = loadEntries();
    bool entryFound = false;

    for (int i = 0; i < dataArray.size(); i++) {
        QJsonObject currentEntry = dataArray[i].toObject();

        if (currentEntry["uid"].toString() == uid) {
            dataArray.removeAt(i);
            entryFound = true;
            break;
        }
    }

    if (!entryFound) {
        return false;
    }

    QJsonDocument doc(dataArray);
    QByteArray encryptedData = encrypt(doc.toJson());

    QFile file(m_filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(encryptedData.toBase64());
        file.close();
        return true;
    } else {
        return false;
    }
}

QJsonArray Encryption::loadEntries() const
{
    QJsonArray dataArray;

    QFile file(m_filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray encryptedData = file.readAll();

        QByteArray decryptedData = decrypt(QByteArray::fromBase64(encryptedData));
        decryptedData = QAESEncryption::RemovePadding(decryptedData);
        QJsonDocument existingDoc = QJsonDocument::fromJson(decryptedData);
        dataArray = existingDoc.array();
        file.close();
    }

    return dataArray;
}


QByteArray Encryption::encrypt(const QByteArray &data) const
{
    return QAESEncryption::Crypt(QAESEncryption::AES_256,
                                 QAESEncryption::CBC,
                                 data,
                                 m_key,
                                 m_iv,
                                 QAESEncryption::ISO);
}

QByteArray Encryption::decrypt(const QByteArray &data) const
{
    return QAESEncryption::Decrypt(QAESEncryption::AES_256,
                                   QAESEncryption::CBC,
                                   data,
                                   m_key,
                                   m_iv,
                                   QAESEncryption::ISO);
}

bool Encryption::createUserEntry(const QString &username, const QString &password)
{
    QString uid = QUuid::createUuid().toString();

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    QJsonObject entry;
    entry["uid"] = uid;
    entry["username"] = username;
    entry["password"] = QString(hashedPassword.toHex());

    QString userFilePath = "user.enc";

    Encryption encryption;
    encryption.setFilePath(userFilePath);

    if(encryption.addOrUpdateEntry(entry)){
        return true;
    }
    else {
        return false;
    }
}

bool Encryption::verifyUser(const QString &password)
{
    QString userFilePath = "user.enc";
    Encryption encryption;
    encryption.setFilePath(userFilePath);
    QJsonArray dataArray = encryption.loadEntries();

    if (dataArray.isEmpty()) {
        qDebug() << "No user data found.";
        return false;
    }

    QJsonObject userEntry = dataArray[0].toObject();

    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    if (userEntry["password"].toString() == QString(hashedPassword.toHex())) {
        return true;
    } else {
        return false;
    }
}

QString Encryption::getUsername()
{
    QString userFilePath = "user.enc";
    setFilePath(userFilePath);

    QJsonArray dataArray = loadEntries();

    if (dataArray.isEmpty()) {
        return QString();
    }

    QJsonObject userEntry = dataArray[0].toObject();
    return userEntry["username"].toString();
}

