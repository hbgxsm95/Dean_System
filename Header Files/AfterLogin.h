//
///  AfterLogin.h
////  System
////
////  Created by Seven on 14-4-6.
////  Copyright (c) 2014年 A.D.A.I. All rights reserved.
////

#ifndef __System__AfterLogin__
#define __System__AfterLogin__

#include <iostream>
using namespace std;
class AfterLogin
{
private:
    int id;
    string password;
    bool Authority;
    string name;
    string lessonname;
    int birthday;

public:
    AfterLogin(int id,string password,string name,string lessonname,int birthday,bool Authority);
    AfterLogin(int id,string password,string name,int birthday,bool Authority);
    void Start();
    void Welcome();
    int choice3;
};

#endif //* defined(__System__AfterLogin__) *//
