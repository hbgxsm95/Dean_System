

#include "FrameWork.h"
#include <direct.h>
#include <stdlib.h>
#include "Teachers.h"
#include "Students.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Gettime.h"
#include "Mkdir.h"
#include "Access.h"
void Framework::welcome()
{
    Gettime rightnow;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Welcome To The Teacher-Student Interaction Application"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Created By A.D.A.I 14-4-6"<<endl
    <<"Copyright (c) 2014年 A.D.A.I. All rights reserved."
    <<endl;
    cout<<"------------------------------------------------------"<<endl;
    int hour=rightnow.hour();
    if(hour>=8&&hour<=12)
        cout<<"Good Morning"<<endl;
    else if(hour>=12&&hour<=18)
        cout<<"Good Afternoon"<<endl;
    else cout<<"Good Evening"<<endl;
    cout<<"Local Time: ";
    rightnow.rightnow();
 }

void Framework::welcome2()
{
    cout<<"Please Enter The Number According To The Menu"<<endl;
    cout<<"1)创建老师; 2)创建学生;3)登陆; 4)退出"<<endl;

}
void Framework::NewTeacher()
{
    string Name;
    int Id;
    string Password;
    string Coursename;
    int birth;
    int mistake=0;
    cout<<"Please Enter Your Name"<<endl;

    while(cin>>Name)
    {
        Access first(Name);
        if(first.Checkname()==true)
            break;
        else
        {
            mistake++;
            if(mistake>=3)
            {
                cout<<"You Make Mistakes For Too Many Times!  Applications Ends!"<<endl;
                exit(1);
            }
            continue;
        }
        
    }
    cout<<"Please Set Your Coursename"<<endl;
    cin>>Coursename;
    cout<<"Please Set Your Id"<<endl;
    while(cin>>Id)
    {
        Access first(Id);
        if(first.Checkid()==true)
            break;
        else
        {
            mistake++;
            if(mistake>=3)
            {
                cout<<"You Make Mistakes For Too Many Times!  Applications Ends!"<<endl;
                exit(1);
            }
            continue;
        }
        
    }

    cout<<"Please Set Your Password"<<endl;
    cin>>Password;
    cout<<"Please Set Your Birhday.  Such As 19950404"<<endl;
    cin>>birth;
    Teachers newteacher(Name,Id,Password,Coursename,birth);
    newteacher.TeachersSet();
    cout<<"New Accounts Is Created Successfully! Please Login!"<<endl;
}

void Framework::NewStudent()
{
    string Name;
    int Id;
    string Password;
    int birth;
    int mistake=0;
    cout<<"Please Enter Your Name"<<endl;
    
    while(cin>>Name)
    {
        Access first(Name);
        if(first.Checkname()==true)
            break;
        else
        {
            mistake++;
            if(mistake>=3)
            {
                cout<<"You Make Mistakes For Too Many Times!  Applications Ends!"<<endl;
                exit(1);
            }
            continue;
        }
        
    }
    cout<<"Please Set Your Id"<<endl;
    while(cin>>Id)
    {
        Access first(Id);
        if(first.Checkid()==true)
            break;
        else
        {
            mistake++;
            if(mistake>=3)
            {
                cout<<"You Make Mistakes For Too Many Times!  Applications Ends!"<<endl;
                exit(1);
            }
            continue;
        }
        
    }
    
    cout<<"Please Set Your Password"<<endl;
    cin>>Password;
    cout<<"Please Set Your Birhday.  Such As 19950404"<<endl;
    cin>>birth;
    Students newstudent(Name,Id,Password,birth);
    newstudent.StudentsSet();
    cout<<"New Accounts Is Created Successfully! Please Login!"<<endl;
}

Framework::~Framework()
{
    cout<<"Thank U For Using Our Application.  To Get Further Information,Please Contact +86 18588670610"<<endl;
}





