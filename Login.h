#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>

class Login
{
    std::string username, password;

public:
    void setData();
    bool validateUsername();
    bool validatePassword();
};


#endif // LOGIN_H
