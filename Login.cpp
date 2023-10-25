#include <iostream>
#include <fstream>
#include "Login.h"
 
 void Login::setData()
    {
        std::cout << "\n\n\n\t\tENTER DETAILS TO LOG IN." << std::endl;

        std::cout << "\n\n\t\tUSERNAME: ";
        std::cin >> username;

        std::cout << "\n\n\t\tPASSWORD: ";
        std::cin >> password;
    }

bool Login::validateUsername()
    {
        std::string temp;
        int flag = 0;

        std::ifstream read;
        read.open("Username Info.txt");
        while (read.eof() == 0)
        {
            getline(read, temp);
            flag += 1; // 1     2       3
            if (temp == username)
                return true;
        }
        return false;
    }

bool Login::validatePassword()
    {
        std::string temp;
        std::ifstream read;

        read.open("Password Info.txt");
        while (read.eof() == 0)
        {
            getline(read, temp);
            if (temp == password)
                return true;
        }
        return false;
    }

    