
#include <direct.h>
#include <stdlib.h>
#include "Teachers.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <io.h>
#include "Gettime.h"
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
using namespace std;
Teachers::Teachers(string name,int id,string password,string lessonname,int birthday)
{
    this->name=name;
    this->id=id;
    this->password=password;
    this->lessonname=lessonname;
    this->birthday=birthday;

}

void Teachers::TeachersSet()
{
    string a="Data\\Teachers\\"+name;
    if(opendir(a.c_str())==NULL)
    {
        a="mkdir "+a;
        system(a.c_str());
    }
    string d="Data\\Teachers\\"+name+"\\"+"Tests";
    if(opendir(d.c_str())==NULL)
    {
        d="mkdir "+d;
        system(d.c_str());
    }
    string b="Data\\Teachers\\"+name+"\\Message";
    if(opendir(b.c_str())==NULL)
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    b="Private\\Teachers\\"+name;
    string Privateid=b+"\\"+name+".dat";
    if(opendir(b.c_str())==NULL)
        
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    ofstream outfile(Privateid.c_str(),ios::out);
    outfile<<id<<' '<<password;
    outfile.close();
    string PrivateInfo="Private\\Teachers\\"+name+"\\"+name+"Info.dat";
    ofstream outfile2(PrivateInfo.c_str(),ios::out);
    outfile2<<name<<' '<<id<<' '<<lessonname<<' '<<birthday<<endl;
    outfile2.close();
    b="Data\\Announcements\\"+lessonname;
    if(opendir(b.c_str())==NULL)
    {
        d="mkdir "+b;
        system(d.c_str());
    }
    b="Data\\Announcements\\Lessons.dat";
    outfile.open(b.c_str(),ios::app);
    outfile<<lessonname<<' ';
    outfile.close();
    b="Private\\Teachers\\ID.dat";
    outfile.open(b.c_str(),ios::app);
    outfile<<id<<' ';
    outfile.close();
    b="Private\\Teachers\\ID2.dat";
    outfile.open(b.c_str(),ios::app);
    outfile<<id<<' '<<password<<' '<<name<<' '<<lessonname<<' '<<birthday<<' '<<endl;
    outfile.close();
    b="Private\\Teachers\\"+name+"\\Logintime.dat";
    outfile.open(b.c_str(),ios::out);
    Gettime now;
    outfile<<now.printtime()<<endl;
    outfile.close();
    b="Private\\Teachers\\"+name+"\\Remind";
    if(opendir(b.c_str())==NULL)
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    b="Private\\Teachers\\"+name+"\\Remind\\remind.dat";
    outfile.open(b.c_str(),ios::out);
    outfile.close();
    b="Data\\Teachers\\"+name+"\\Homework";
    if(opendir(b.c_str())==NULL)
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    b="Data\\Teachers\\"+name+"\\Message\\Message2.dat";
    outfile.open(b.c_str(),ios::out);
    outfile.close();
    b="Data\\Teachers\\"+name+"\\Message\\Message.dat";
    outfile.open(b.c_str(),ios::out);
    outfile.close();


    
}

void Teachers::ResultEntry()
{
    while(1){
    string a,b,test,fileposition,subchoice="Suck",choice;
          while(1)
        {
            cout<<"Please Enter The Name Of The Test!"<<endl;
            cin>>a;
            cout<<"If U Input By Mistake,Please Input 1 Or Any Other Characters To Continue!"<<endl;
            cin>>choice;
            if(choice=="1")
                continue;
            else
                break;
        }
    a="Data\\Teachers\\"+name+"\\Tests\\"+a;
   if(opendir(a.c_str())==NULL)
   {
       b="mkdir "+a;
       system(b.c_str());
   }
    int number;
    while(1)
    {
        cout<<"Please Enter The Number Of Students Of Your Class!"<<endl;
        cin>>number;
        cout<<"If U Input By Mistake,Please Input 1 Or Any Other Characters To Continue!"<<endl;
        cin>>choice;
        if(choice=="1")
            continue;
        else
            break;
    }
    int i;
    for(i=1;i<=number;i++)
    {
        cout<<"Please Input The ID"<<endl;
        cin>>b;
        fileposition=a+"\\"+b+".dat";
        ofstream outfile(fileposition.c_str(),ios::out);
        cout<<"Please Input The Name"<<endl;
        cin>>test;
        outfile<<test<<' ';
        cout<<"Please Input The Score"<<endl;
        cin>>test;
        cout<<"Input Successfully! "<<"You Still Have "<<number-i<<" Records To Input!"<<endl;
       
        cout<<"If U Input By Mistake,Please Input 1,Or Any Other Character To Continue!."<<endl;
        cin>>subchoice;
        if(subchoice=="1")
            break;
        outfile<<test<<endl;
        outfile.close();
    }
     if(subchoice!="1"&&subchoice!="Suck")
     {
         cout<<"All The Statistics Have Been Uploaded!  Now Return To The Previous Menu!"<<endl;
         break;
     }
        else if(subchoice=="Suck")
            break;
        else if(subchoice=="1")
        {
            cout<<"Sorry, You Have To Input The Statistics From The Begining!"<<endl;
            continue;
        }
    }
}

bool Teachers::Messages()
{
   string message="Data\\Teachers\\"+name+"\\"+"Message\\Message.dat";
    ifstream infile,infile2;
    infile.open(message.c_str());
    infile2.open(message.c_str());
    char ch;
    if(infile2>>ch)
    {
        infile2.close();
        cout<<"You Have New Messages!"<<endl;
        int subchoice;
        cout<<"If U Wanna Check New Messages,Please Input 1,Or 0 To Skip Them."<<endl;
        cin>>subchoice;
        if(subchoice==1)
        {
            char ch;
            while(infile.get(ch))
                cout<<ch;
            infile.close();
            ofstream outfile(message.c_str(),ios::out);
            outfile.close();
            return true;
        }
        else
            return true;
    }
    else
    {
        cout<<"No New Message!"<<endl;
        infile2.close();
        return true;
    }
}


void Teachers::AnswerMessages()
{
    while(1)
    {
        string studentname;
        cout<<"Please Input The Student's Name You Wanna Answer!"<<endl;
        cin>>studentname;
        string position="Data\\Students\\"+studentname+"\\Message";
        string position2=position;
        if(opendir(position.c_str())==NULL)
        {
            cout<<"No Such A Student!"<<endl
            <<"If You Wanna Retry, Please Input 1,Or Any Other Character To The Previous Menu!"<<endl;
            string choice;
            cin>>choice;
            if(choice=="1")
                continue;
            else
                break;
        }
        else
        {
            ofstream outfile,outfile2;
            position=position+"\\Message.dat";
            position2=position2+"\\Message2.dat";
            outfile.open(position.c_str(),ios::app);
            outfile2.open(position2.c_str(),ios::app);
            string note;
            Gettime now;
            note="This Message Is Created By "+name+" In "+now.printtime();
            outfile<<note<<endl;
            outfile2<<note<<endl;
            cout<<"Please Enter Your Reply And End It With \"EOF\""<<endl;
            while(cin>>note)
            {
                if(note=="EOF")
                    break;
                else
                {
                    outfile<<note<<' ';
                    outfile2<<note<<' ';
                }
            }
            outfile<<endl;
            outfile2<<endl;
            outfile.close();
            outfile2.close();
        }
        cout<<"If U Wanna Answer Another Student,Please Input 1,Or Any Other Character To The Previous Menu."<<endl;
        string choice2;
        cin>>choice2;
        if(choice2=="1")
            continue;
        else
            break;
    }
}
void Teachers::Announcements()
{
    string a="Data\\Announcements\\"+lessonname+"\\Announcements.dat";
    ofstream outfile(a.c_str(),ios::out);
    string b;
    cout<<"Welcome To The Part Of Annoncements!"
    <<endl<<"Please Enter The Annocements And End It With \"End\""<<endl;
    while(getline(cin,b))
    {
        if(b!="End")
            outfile<<b<<endl;
        else
        {
        outfile<<endl;
            break;
        }
    }
    Gettime t;
    a="Released By "+name+" In "+t.printtime();
    outfile<<a<<endl;
    outfile.close();
    
}
    
bool Teachers::CheckInfo1()
{
    while(1)
    {
    string a;
    string PrivateInfo="Private\\Teachers\\"+name+"\\"+name+"Info.dat";
    ifstream infile(PrivateInfo.c_str(),ios::in);
    if(!infile)
    {
        cout<<"No Such A Teacher!"<<endl;
        cout<<"If You Wanna Return The Previous Menu,Please Input 1 Or 0 To Continue it"<<endl;
        int subchoice;
        cin>>subchoice;
        if(subchoice==1)
            return 1;
        else
            continue;
    }
    cout<<"Your Name: ";
    infile>>a;
    cout<<a<<endl;
    cout<<"Your ID: ";
    infile>>a;
    cout<<a<<endl;
    cout<<"Your Lessonname: ";
    infile>>a;
    cout<<a<<endl;
    cout<<"Your Birthday: ";
    infile>>a;
    cout<<a<<endl;
    infile.close();
        return 0;
    }
}

void Teachers::ChangePassword()
{
   
    string PrivateCode1="Private\\Teachers\\"+name+"\\"+name+".dat";
    cout<<"Please Enter Your New Password: ";
       while(1)
 {
     string a,c;
     cin>>a;
    cout<<"Please ReEnter Your New Password: ";
     cin>>c;
     if(a==c)
     {
         ofstream outfile(PrivateCode1.c_str(),ios::out);
         outfile<<id<<' '<<a<<endl;
         outfile.close();
         cout<<"New Password Set Succeessfully!"<<endl;
         break;
     }
     else
         continue;
    
 }

}

bool Teachers::CheckInfo2()
{
    while(1)
    {
    string studentname;
    cout<<"Please Enter the Student's Name U Wanna Check!"<<endl;
    cin>>studentname;
    string b="Private\\Students\\"+studentname;
    if(opendir(b.c_str())==NULL)
       {
           cout<<"No Such A Student!"<<endl;
           cout<<"If You Wanna Return The Previous Menu,Please Input 1 Or 0 To Continue it"<<endl;
           int subchoice;
           cin>>subchoice;
           if(subchoice==1)
               return 1;
           else
               continue;
       }
           else
       {
           string a;
        b=b+"\\"+studentname+"Info.dat";
           ifstream infile(b.c_str(),ios::in);
           if(!infile)
           {
               cout<<"No Such A Student"<<endl;
           }
           cout<<"His Name: ";
           infile>>a;
           cout<<a<<endl;
           cout<<"His ID: ";
           infile>>a;
           cout<<a<<endl;
           cout<<"His Birthday: ";
           infile>>a;
           cout<<a<<endl;
           infile.close();
       }
        return 0;
    }
    
}


void Teachers::remind()
{
        string month,day;
    cout<<"Please Set Your Reminding Month"<<endl;
    cin>>month;
        cout<<"Please Set Your Reminding Day"<<endl;
        cin>>day;
        ofstream outfile;
        string position="Private\\Teachers\\"+name+"\\Remind\\"+month+day+".dat";
        outfile.open(position.c_str(),ios::out);
        string remind;
        cout<<"Please Input Your Reminding Event,And End It With EOF"<<endl;
        while(cin>>remind)
         {
             if(remind!="EOF")
                 outfile<<remind<<' ';
             else break;
         }
        outfile.close();
    cout<<"Input Successfully!  Now Return To The Initial Menu."<<endl;
        
}


void Teachers::HomeworkAssignment()
{
    cout<<"Please Set Your HomeworkIndex First"<<endl;
    string homeworkindex;
    while(1)
    {
        cin>>homeworkindex;
        string b="Data\\Teachers\\"+name+"\\Homework\\"+homeworkindex;
        if(opendir(b.c_str())==NULL)
        {
            b="mkdir "+b;
            system(b.c_str());
        }
        else
        {
            cout<<"The Index Has Been Set. Please Choose Another One!"<<endl;
            continue;
        }
        break;

    }
    
    string b="Data\\Teachers\\Homework\\Homework.dat";
    ofstream outfile(b.c_str(),ios::app);
    outfile<<name<<' '<<homeworkindex<<' ';
    outfile.close();
    b="Data\\Teachers\\Homework\\"+name+homeworkindex+".dat";
    outfile.open(b.c_str(),ios::out);
    cout<<"Please Input Your HomeWork Requirements! And End It With EOF"<<endl;
    while(cin>>homeworkindex)
    {
        if(homeworkindex=="EOF")
            break;
        else
            outfile<<homeworkindex<<' ';
    }
    outfile.close();
    cout<<"The Homework Has Been Assigned Successfully!"<<endl;
}

 void Teachers::CheckAssignment()
{
    
    string homeworkindex;
    while(1)
    {
        cout<<"Please Input The Index Of Homework You Wanna Check"<<endl;
        cin>>homeworkindex;
        homeworkindex="Data\\Teachers\\"+name+"\\Homework\\"+homeworkindex;
        if(opendir(homeworkindex.c_str())==NULL)
        {
            cout<<"No Such Assignments! Please Input The Index!"<<endl;
            continue;
        }
        else
        {
            ifstream infile("Private\\Students\\ID.dat",ios::in);
            string homeworkid;
            while(infile>>homeworkid)
            {
                string studentid="Data\\Teachers\\"+name+"\\Homework\\"+homeworkindex+"\\"+homeworkid+".dat";
                ifstream infile2(studentid.c_str(),ios::in);
                if(!infile2)
                    
                   {
                       cout<<homeworkid<<" Didn't Handle His Homework!"<<endl;
                       infile2.close();
                   }
                else
                {
                    infile2.close();
                    continue;
                }
            }
            infile.close();
        }
        string choice;
        cout<<"If You Wanna Check Another Index Of Homework,Please Input 1,Or Any Other Character To End."<<endl;
        cin>>choice;
        if(choice=="1")
            continue;
        else
            break;
    }
    
    
}
    
    



void Teachers::deletemessage2()
{
    string a="Data\\Teachers\\"+name+"\\Message\\Message2.dat";
    ofstream outfile;
    outfile.open(a.c_str(),ios::out);
    outfile.close();
    cout<<"Delete Success!  Now Return To The Previous Menu"<<endl;
    
}

void Teachers::historymessage()
{
    string a="Data\\Teachers\\"+name+"\\Message\\Message2.dat";
    ifstream infile(a.c_str(),ios::in);
    char ch;
    if(!infile)
        cout<<"No Messages!"<<endl;
    while(infile.get(ch))
        cout<<ch;
    infile.close();

}

