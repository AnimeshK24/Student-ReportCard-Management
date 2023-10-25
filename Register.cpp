#include <iostream>
#include <limits>
#include <fstream>
#include "Register.h"


    bool Register::setData()
    {
        
        std::cout << "\nUSERNAME: ";
        std::cin >> username;

        std::cout << "\nEMAIL ID: ";
        std::cin >> emailId;

        std::cout << "\nPASSWORD: ";
        std::cin >> password;

        std::cout << "\nCONFIRM PASSWORD: ";
        std::cin >> conPassword;

        // bool temp = checkPasswordAndConPassword();
        // return temp;

        return checkPasswordAndConPassword();
    }

    bool Register::checkPasswordAndConPassword()
    {
         std::ofstream save,saveUsername, savePassword;

        save.open("Register Info.txt", std::ios::app);
        save << "\nUSERNAME: " << username;
        save << "\nEMAIL ID: " << emailId;
        save << "\nPASSWORD: " << password;
        save.close();

        saveUsername.open("Username Info.txt", std::ios::app);
        saveUsername << username << std::endl;
        saveUsername.close();

        savePassword.open("Password Info.txt", std::ios::app);
        savePassword << password << std::endl;
        savePassword.close();

        std::cout << "\n\n\n\n\t\tINFORMATION HAVE BEEN SAVED SUCCESSFULLY." << std::endl
             << "\n\n\t\tPRESS ENTER TO LOGIN." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }

    int Register::saveRegisterInfo()
    {
         if (password == conPassword)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
