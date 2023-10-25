#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class student
{
    int rollno;
    char name[50];
    int p_marks, c_marks, m_marks, e_marks, cs_marks;
    double per;
    char grade;
    void calculate(); // function to calculate grade
public:
    void getdata();        // function to accept data from user
    void showdata() const; // function to show data on screen
    void show_tabular() const;
    int retrollno() const;
};

#endif // STUDENT_H
