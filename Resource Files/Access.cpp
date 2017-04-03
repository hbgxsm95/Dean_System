
#include "Students.h"
#include <dirent.h>
#include <windows.h>
#include <direct.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include "Gettime.h"
#include "CopyFile.h"
#include "Access.h" 
bool Access::check()
{
while(1)
{
	trytimes=3;
	Accesscode="ADAI";
    cout<<"Please Enter The Access Code"<<endl;
    cin>>inputcode;
    if(inputcode==this->Accesscode)
    {
        cout<<"Access Successfully!"<<endl;
        break;
    }
    else
    {
        
        trytimes++;
        if(trytimes==3)
        {
            cout<<"Sorry For Access Failure. The System Will Close."<<endl;
            return false;
        }
        cout<<"You Still Have "<<3-trytimes<<" Chances Left! Please ReEnter."<<endl;
    }
    
    }
    return true;
}

bool Access::Checkname()
{
    string check="Private\\Teachers\\";
    string check2="Private\\Students\\";
    check=check+checkname;
    check2=check2+checkname;
    if(opendir(check.c_str())!=NULL)
    {
        cout<<"The Name Input Has Already Existed, Please Retry Or Contact Your Teacher!."<<endl;
        return false;
        
    }
    else if (opendir(check2.c_str())!=NULL)
    {
        cout<<"The Name Input Has Already Existed, Please Retry Or Contact Your Teacher!."<<endl;
        return false;
    }
    else return true;
}

bool Access::Checkid()
{
    int tem_id;
    ifstream infile("Private\\Teachers\\ID.dat",ios::in);
    while(infile>>tem_id)
    {
        if(tem_id==checkid)
        {
            return false;
            break;
        }
        else
            continue;
    }
    infile.close();
    infile.open("Private\\Students\\ID.dat",ios::in);
    while(infile>>tem_id)
    {
        if(tem_id==checkid)
        {
            return false;
            break;
        }
        else
            continue;
    }
    infile.close();
    return true;
}

bool Access::loginid()
{
    int tem_id;
    ifstream infile("Private\\Teachers\\ID.dat",ios::in);
    while(infile>>tem_id)
    {
        if(tem_id==checkid)
        {
            return true;
            break;
        }
        else
            continue;
    }
    infile.close();
    infile.open("Private\\Students\\ID.dat",ios::in);
    while(infile>>tem_id)
    {
        if(tem_id==checkid)
        {
            return true;
            break;
        }
        else
            continue;
    }
    infile.close();
    return false;

}
bool Access::whetherteacher(int tem_id)
{
    ifstream infile("Private\\Teachers\\ID.dat",ios::in);
    while(infile>>tem_id)
    {
        if(tem_id==checkid)
        {
            return true;
            break;
        }
        else
            continue;
    }
    return false;
    infile.close();
}
Access::Access(string checkname)
{
    this->checkname=checkname;
}
Access::Access (int checkid)
{
    this->checkid=checkid;
}
