#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>

class Register
{
 private:
    std::string username;
    std::string emailId;
    std::string password;
    std::string conPassword;

public:
    bool setData();
    bool checkPasswordAndConPassword();
    int saveRegisterInfo();
};
   

#endif // REGISTER_H
