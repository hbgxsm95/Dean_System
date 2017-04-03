////
////  Teachers.h
////  System
////
////  Created by Seven on 14-4-4.
////  Copyright (c) 2014年 A.D.A.I. All rights reserved.
////

#ifndef __System__Teachers__
#define __System__Teachers__

#include <iostream>
using namespace std;
class Teachers
{
private:
    string name;
    int id;
    string password;
    int age;
    string lessonname;
    int birthday;
public:
    void TeachersSet();
    void ResultEntry();
    bool Messages();
    void AnswerMessages();
    void Announcements();
    bool CheckInfo2();
    void ChangePassword();
    bool CheckInfo1();
    Teachers(string name,int id,string password,string lessonname,int birthday);
    void remind();
    void HomeworkAssignment();
    void CheckAssignment();
    void deletemessage2();
    void historymessage();
    
};

#endif //* defined(__System__Teachers__) *//
