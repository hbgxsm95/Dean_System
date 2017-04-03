////
////  Students.h
////  System
////
////  Created by Seven on 14-4-5.
////  Copyright (c) 2014年 A.D.A.I. All rights reserved.
////

#ifndef __System__Students__
#define __System__Students__

#include <iostream>
using namespace std;
class Students
{
private:
    string name;
    int id;
    string password;
    int birthday;
public:
    Students(string name,int id,string password,int birthday);
    void StudentsSet();
    bool messages();
    void Annoucements();
    void answermessages();
    bool ResultsEnquiry();
    void leavemessage();
    void Checkme();
    bool Checkhe();
    void ChangePassword();
    void remind();
    void Homework();
    void whetherhomework();
    void deletemessage2();
    void historymessage();
    bool handinhomework();
};

#endif //* defined(__System__Students__) *//
