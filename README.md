# PasMan - Password Manager  

PasMan is a desktop password manager developed as a student project. The application allows users to securely store, organize, and generate passwords. By utilizing encryption, it provides a high level of protection for stored data while remaining intuitive and easy to use.  

## Features  

PasMan offers a wide range of functionalities for password management:  
- **User login and management**: The application supports a single user who, after initial registration, uses a password to access the password manager.  
- **Viewing saved passwords**: Users can browse saved passwords and their details.  
- **Adding new passwords**: Users can add new entries, which may include information such as name, username, password, category, URL, and notes.  
- **Editing and deleting passwords**: Users can modify and delete saved passwords.  
- **Password generation**: The application includes a generator that allows users to create strong passwords.  
- **Password strength check**: A special dialog enables users to check password strength and provides an estimated time required to crack the password using brute-force methods, as well as the encrypted password length in bits.  
- **Secure encryption**: All data is encrypted to ensure user security.  

## Screenshots
![image](https://github.com/user-attachments/assets/c7a5d6fa-9edb-408f-a3dc-f13673c450c6)
![{2E87A728-0028-49F5-BC4F-22902E6D8064}](https://github.com/user-attachments/assets/f289de43-1741-4496-84d9-dfb7b162f310)
![image](https://github.com/user-attachments/assets/578c16fe-b856-4d97-9e21-cb8c989d5f3d)

## Technologies  

PasMan utilizes strong encryption algorithms such as AES-256, ensuring the protection of stored passwords and other sensitive user data. Each entry is hashed and stored in a secure format, preventing unauthorized access to information.  

## Requirements  

The application has been developed with key functional and non-functional requirements in mind.  

### Functional Requirements  
- **FR.001**: User login (high priority)  
- **FR.002**: Password management, including viewing, adding, editing, and deleting passwords  
- **FR.003**: Generation of strong passwords (medium priority)  
- **FR.004**: Password strength evaluation and estimation of brute-force cracking time  
- **FR.005**: Encryption and secure storage of passwords  

### Non-Functional Requirements  
- **NF.001**: Security – use of AES-256 encryption  
- **NF.002**: Performance – smooth operation without delays  
- **NF.003**: Intuitive user interface  

## Installation and Execution  

To run the PasMan project:  

1. Download the `projekt.rar` file and extract all files.  
2. The extracted folder contains all necessary files to run the application, along with documentation.  
3. Launch the application following the instructions provided in the documentation inside `projekt.rar`.  

## Usage  

After launching the application, the user can:  

1. Log in using the previously created password.  
2. Browse saved passwords, add new ones, edit existing entries, and delete unnecessary ones.  
3. Generate strong passwords tailored to their needs.  
4. Analyze the strength of any password and obtain additional security information.  

## Security and Encryption  

All data in PasMan is encrypted using the AES-256 algorithm, ensuring a high level of data protection for users. Each stored password is hashed to prevent unauthorized access. Thanks to this approach, PasMan meets the highest security standards and allows users to conveniently manage their passwords in one place.  

## Author  

The author is Olaf Wojda 160203.  
PasMan was developed as part of a student project.  

## License  

The PasMan project is available exclusively for educational use with the author's consent.  
