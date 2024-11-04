#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QCryptographicHash>
#include <QDebug>
#include "qaesencryption.h"

class Encryption : public QObject
{
    Q_OBJECT

public:
    explicit Encryption(QObject *parent = nullptr);

    void setFilePath(const QString &filePath);

    bool addOrUpdateEntry(const QJsonObject &entry);

    bool removeEntry(const QString &uid);

    bool createUserEntry(const QString &username, const QString &password);

    bool verifyUser(const QString &password);

    QString getUsername();

    QJsonArray loadEntries() const;

private:
    QString m_filePath;
    QByteArray m_key;
    QByteArray m_iv;

    QByteArray encrypt(const QByteArray &data) const;

    QByteArray decrypt(const QByteArray &data) const;
};

#endif // ENCRYPTION_H
