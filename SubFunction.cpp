#include <iostream>
#include <stdio.h>
#include <limits>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <iomanip>
#include "Student.h"
#include "Register.h"
#include "Login.h"
#include "SubFunction.h"

void welcome()
{
    std::cout << "\n\n\n\t\t  STUDENT";
    std::cout << "\n\n\t\tREPORT CARD";
    std::cout << "\n\n\t\t  PROJECT";
    std::cout << "\n\n\n\t\tBy: "
         << "\n\t\t\t1: Animesh Kudake"
         << "\n\t\t\t2: Aniket Raj";
    std::cout << "\n\n\n\tPlease Enter Any Key To Start!";
    std::cin.get();
}

bool registerScreen()
{

    char choice;

    std::cout << "\n\n\n\t\t1. REGISTER A NEW ACCOUNT." << std::endl
         << "\n\n\n\t\t2. LOGIN TO A EXISTING ACCOUNT." << std::endl
         << "\n\n\n\t\t3. EXIT" << std::endl
         << "\n\n\n\t\tENTER YOUR CHOICE: " << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case '1':
    {
    
        /*Registration for the new user*/

        Register reg;

    set:
        bool tempReg = reg.setData();
        if (!tempReg)
        {
            std::cout << "\n\n\n\n\n\t\tPASSWORD DIDN'T MATCHED WITH CONFIRM PASSWORD." << std::endl
                 << "\n\n\t\tPRESS ENTER TO CONTINUE.." << std::endl;
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto set;
        }
        else
        {
            reg.saveRegisterInfo();
        }
    }

    case '2':
    {
    
    /*Login for the existing user*/
    logi:
        bool checkUsername, checkPassword;
        Login login;
        login.setData();
        checkUsername = login.validateUsername();
        checkPassword = login.validatePassword();

        if (checkUsername)
        {
            if (checkPassword)
            {
            
                std::cout << "\n\n\n\n\n\t\tLOGGED IN SUCCESSFULLY..!!";
                std::cout << "\n\n\n\t\tPRESS ENTER TO CONTINUE.";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else
        {
        
            std::cout << "\n\n\n\n\t\tINVAILD CREDENTIALS..!";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            goto logi;
        }
    }
    break;

    case '3':
        /*Used to terminate the program execution*/
        exit(0);

    default:
        std::cout << "INVAILD CHOICE. PRESS ENTER TO CONTINUE.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
    }
    return true;
}

void operations()
{
    char ch;
    do
    {
      
        std::cout << "\n\n\n\tMAIN MENU";
        std::cout << "\n\n\t01. RESULT MENU";
        std::cout << "\n\n\t02. ENTRY/EDIT MENU";
        std::cout << "\n\n\t03. EXIT";
        std::cout << "\n\n\tPlease Select Your Option (1-3) ";
        std::cin >> ch;
        switch (ch)
        {
        case '1':
            result();
            break;
        case '2':
            entry_menu();
            break;
        case '3':
            break;
        default:
            std::cout << "\a";
        }
    } while (ch != '3');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void result()
{
    char ch;
    int rno;
  
    std::cout << "\n\n\n\tRESULT MENU";
    std::cout << "\n\n\n\t1. CLASS RESULT";
    std::cout << "\n\n\t2. STUDENT REPORT CARD ";
    std::cout << "\n\n\t3. BACK TO MAIN MENU";
    std::cout << "\n\n\n\tEnter Choice (1/2/3)? ";
    std::cin >> ch;
    
    switch (ch)
    {
    case '1':
        class_result();
        break;
    case '2':
        std::cout << "\n\n\tEnter Roll Number Of Student : ";
        std::cin >> rno;
        display_sp(rno);
        break;
    case '3':
        break;
    default:
        std::cout << "\a";
    }
}

void entry_menu()
{
    char ch;
    int num;

    std::cout << "\n\n\n\tENTRY MENU";
    std::cout << "\n\n\t1.CREATE STUDENT RECORD";
    std::cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
    std::cout << "\n\n\t3.SEARCH STUDENT RECORD ";
    std::cout << "\n\n\t4.MODIFY STUDENT RECORD";
    std::cout << "\n\n\t5.DELETE STUDENT RECORD";
    std::cout << "\n\n\t6.BACK TO MAIN MENU";
    std::cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    std::cin >> ch;

    switch (ch)
    {
    case '1':
        write_student();
        break;
    case '2':
        display_all();
        break;
    case '3':
        std::cout << "\n\n\tPlease Enter The roll number ";
        std::cin >> num;
        display_sp(num);
        break;
    case '4':
        std::cout << "\n\n\tPlease Enter The roll number ";
        std::cin >> num;
        modify_student(num);
        break;
    case '5':
        std::cout << "\n\n\tPlease Enter The roll number ";
        std::cin >> num;
        delete_student(num);
        break;
    case '6':
        break;
    default:
        std::cout << "\a";
        entry_menu();
    }
}

void write_student()
{
    student st;
    std::ofstream outFile;
    outFile.open("student.txt", std::ios::binary | std::ios::app);
    st.getdata();
    outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
    outFile.close();
    std::cout << "\n\nStudent record Has Been Created ";
    std::cin.ignore();
    std::cin.get();
}

void class_result()
{
    student st;
    std::ifstream inFile;
    inFile.open("student.txt", std::ios::binary);
    if (!inFile)
    {
        std::cout << "File could not be open !! Press any Key...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
    std::cout << "==========================================================\n";
    std::cout << "R.No       Name        P   C   M   E   CS   %age   Grade" << std::endl;
    std::cout << "==========================================================\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.show_tabular();
    }
    std::cin.ignore();
    std::cin.get();
    inFile.close();
}

void delete_student(int n)
{
    student st;
    std::ifstream inFile;
    inFile.open("student.txt", std::ios::binary);
    if (!inFile)
    {
        std::cout << "File could not be open !! Press any Key...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::ofstream outFile;
    outFile.open("Temp.txt", std::ios::out);
    inFile.seekg(0, std::ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.retrollno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
        }
    }
    outFile.close();
    inFile.close();
    remove("student.txt");
    rename("Temp.txt", "student.txt");
    std::cout << "\n\n\tRecord Deleted ..";
    std::cin.ignore();
    std::cin.get();
}

void display_sp(int n)
{
    student st;
    std::ifstream inFile;
    inFile.open("student.txt", std::ios::binary);
    if (!inFile)
    {
        std::cout << "File could not be open !! Press any Key...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        if (st.retrollno() == n)
        {
            st.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        std::cout << "\n\nrecord not exist";
    std::cin.ignore();
    std::cin.get();
}

void display_all()
{
    student st;
    std::ifstream inFile;
    inFile.open("student.txt", std::ios::binary);
    if (!inFile)
    {
        std::cout << "File could not be open !! Press any Key...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    std::cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
    {
        st.showdata();
        std::cout << "\n\n====================================\n";
    }
    inFile.close();
    std::cin.ignore();
    std::cin.get();
}

void modify_student(int n)
{
    bool found = false;
    student st;
    std::fstream File;
    File.open("student.txt", std::ios::binary | std::ios::in | std::ios::out);
    if (!File)
    {
        std::cout << "File could not be open !! Press any Key...";
        std::cin.ignore();
        std::cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {

        File.read(reinterpret_cast<char *>(&st), sizeof(student));
        if (st.retrollno() == n)
        {
            st.showdata();
            std::cout << "\n\nPlease Enter The New Details of student" << std::endl;
            st.getdata();
            int pos = (-1) * static_cast<int>(sizeof(st));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char *>(&st), sizeof(student));
            std::cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        std::cout << "\n\n Record Not Found ";
    std::cin.ignore();
    std::cin.get();
}