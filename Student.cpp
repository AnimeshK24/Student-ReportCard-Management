#include <iostream>
#include <iomanip>
#include "Student.h"

void student::calculate()
{
    per = (p_marks + c_marks + m_marks + e_marks + cs_marks) / 5.0;
    if (per >= 60)
        grade = 'A';
    else if (per >= 50)
        grade = 'B';
    else if (per >= 33)
        grade = 'C';
    else
        grade = 'F';
}

void student::getdata()
{
    std::cout << "\nEnter The roll number of student ";
    std::cin >> rollno;
    std::cout << "\n\nEnter The Name of student ";
    std::cin.ignore();
    std::cin.getline(name, 50);
    std::cout << "\nEnter The marks in physics out of 100 : ";
    std::cin >> p_marks;
    std::cout << "\nEnter The marks in chemistry out of 100 : ";
    std::cin >> c_marks;
    std::cout << "\nEnter The marks in maths out of 100 : ";
    std::cin >> m_marks;
    std::cout << "\nEnter The marks in english out of 100 : ";
    std::cin >> e_marks;
    std::cout << "\nEnter The marks in computer science out of 100 : ";
    std::cin >> cs_marks;
    calculate();
}

void student::showdata() const
{
    std::cout << "\nRoll number of student : " << rollno;
    std::cout << "\nName of student : " << name;
    std::cout << "\nMarks in Physics : " << p_marks;
    std::cout << "\nMarks in Chemistry : " << c_marks;
    std::cout << "\nMarks in Maths : " << m_marks;
    std::cout << "\nMarks in English : " << e_marks;
    std::cout << "\nMarks in Computer Science :" << cs_marks;
    std::cout << "\nPercentage of student is  :" << per;
    std::cout << "\nGrade of student is :" << grade;
}

void student::show_tabular() const
{
    std::cout << rollno << "\t" << name << "\t" << p_marks << "\t" << c_marks << "\t" << m_marks << "\t"
         << e_marks << "\t" << cs_marks << "\t" << per << "\t" << grade << std::endl;
}

int student::retrollno() const
{
    return rollno;
}
