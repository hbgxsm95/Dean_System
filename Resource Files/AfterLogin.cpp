
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
#include <iomanip>
#include "FrameWork.h"
#include "AfterLogin.h"
#include "Remind.h"
#include "CopyFile.h"
AfterLogin::AfterLogin(int id,string password,string name,string lessonname,int birthday,bool Authority)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->Authority=Authority;
    this->lessonname=lessonname;
    this->birthday=birthday;
}

AfterLogin::AfterLogin(int id,string password,string name,int birthday,bool Authority)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->Authority=Authority;
    this->birthday=birthday;
}
void AfterLogin::Start()
{
   if(Authority==1)
   {
       Teachers loginteacher(name,id,password,lessonname,birthday);
       string b;
       char ch;
       ifstream infile;
       b="Private\\Teachers\\"+name+"\\Logintime.dat";
       infile.open(b.c_str(),ios::in);
       if(!infile)
           cout<<"Failure"<<endl;
       cout<<"Last Login Time:   ";
       while(infile.get(ch))
           cout<<ch;
       infile.close();
       Gettime now;
       ofstream outfile(b.c_str(),ios::out);
       outfile<<now.printtime();
       outfile.close();
       int choice;
       Welcome();
            {
           string month,day,nowmonth,nowday;
           string position2="Private\\Teachers\\"+name+"\\Remind\\remindnow.dat";
           ofstream outfile2(position2.c_str(),ios::out);
           outfile2<<now.month()<<' '<<now.day()<<' ';
           outfile2.close();
           ifstream infile;
           infile.open(position2.c_str(),ios::in);
           infile>>nowmonth>>nowday;
           infile.close();
           string position="Private\\Teachers\\"+name+"\\Remind\\"+nowmonth+nowday+".dat";
           infile.open(position.c_str(),ios::in);
           if(!infile)
           {
               cout<<"No Reminds Today!"<<endl;
               infile.close();
           }
           else{
               char ch;
               cout<<"Today's Reminds!"<<endl;
               while(infile.get(ch))
                   cout<<ch;
               cout<<endl;
               infile.close();
           }
           
           
                loginteacher.Messages();
  
       }
       while(1)
       {
           cout<<"1)回复留言 ;2)查询或修改信息 3)成绩录入;4);5)公布课程公告;6)设置日期提醒;7)布置作业;8)查看未交作业名单;9)留言箱操作;10)返回初始菜单"<<endl;
           cin>>choice;
           if(choice==1)
               loginteacher.AnswerMessages();
           else if(choice==2)
           {
               
               int choice2;
               while(1)
               {
                cout<<"1)查询学生信息;2)查询自身信息;3)修改密码;4)返回上级菜单"<<endl;
                   cin>>choice2;
               if(choice2==1)
                   {
                       if(loginteacher.CheckInfo2()==1)
                           continue;
                   }
               else if (choice2==2)
               {
                   if(loginteacher.CheckInfo1()==1)
                       continue;
               }
               else if (choice2==3)
                   loginteacher.ChangePassword();
               else if(choice2==4)
                   break;
               }
           }
           else if(choice==3)
               loginteacher.ResultEntry();
           else if(choice==4)
               cout<<"It's To Be Finished"<<endl;
           else if(choice==5)
               loginteacher.Announcements();
           else if(choice==6)
               loginteacher.remind();
           else if(choice==7)
               loginteacher.HomeworkAssignment();
           else if(choice==8)
               loginteacher.CheckAssignment();
           else if(choice==9)
             {
                 int choicein;
                 cout<<"1)查看历史记录;2)删除历史记录"<<endl;
                 cin>>choicein;
                 if(choicein==2)
               loginteacher.deletemessage2();
                 else
                     loginteacher.historymessage();
             }
           else if(choice==10)
               break;
           
       }
   }
    else if(Authority==0)
    {
        Students loginstudent(name,id,password,birthday);
        string b;
        char ch;
        ifstream infile;
        b="Private\\Students\\"+name+"\\Logintime.dat";
        infile.open(b.c_str(),ios::in);
        if(!infile)
            cout<<"Failure"<<endl;
        cout<<"Last Login Time:   ";
        while(infile.get(ch))
            cout<<ch;
        infile.close();
        Gettime now;
        ofstream outfile(b.c_str(),ios::out);
        outfile<<now.printtime()<<endl;
        outfile.close();
        int choice;
        Welcome();
        loginstudent.Annoucements();
        
        {
            string month,day,nowmonth,nowday;
            string position2="Private\\Students\\"+name+"\\Remind\\remindnow.dat";
            ofstream outfile2(position2.c_str(),ios::out);
            outfile2<<now.month()<<' '<<now.day()<<' ';
            outfile2.close();
            ifstream infile;
            infile.open(position2.c_str(),ios::in);
            infile>>nowmonth>>nowday;
            infile.close();
            string position="Private\\Students\\"+name+"\\Remind\\"+nowmonth+nowday+".dat";
            infile.open(position.c_str(),ios::in);
            if(!infile)
            {
                cout<<"No Reminds Today!"<<endl;
                infile.close();
            }
            else{
                char ch;
                cout<<"Today's Reminds!"<<endl;
                while(infile.get(ch))
                    cout<<ch;
                cout<<endl;
                infile.close();
            }
            
            

        }

        while(1)
        {
             if(loginstudent.messages()==true)
             {
                 cout<<"If U Wanna Answer The Message, Please Input 1 Or 0 To Skip Them."<<endl;
                 cin>>choice3;
                 if(choice3==1)
                   loginstudent.answermessages();
                 else
                   break;
             }
            else
                break;
            
        }

        while(1)
        {
            cout<<"1)留言老师;2)查询修改信息3)成绩查询;4)处理中;5)设置日期提醒;6)检查作业布置情况;7)提交作业;8)留言箱操作;9)回到初始菜单;"<<endl;
            cin>>choice;
            if(choice==1)
                loginstudent.leavemessage();
            else if(choice==2)
            {
                
                int choice2;
                while(1)
                {
                    cout<<"1)查询老师信息;2)查询学生信息;3)回到上级菜单"<<endl;
                    cin>>choice2;
                    if(choice2==1)
                    {
                        if(loginstudent.Checkhe()==1)
                            continue;
                    }
                    else if (choice2==2)
                        loginstudent.Checkme();
                    else if (choice2==3)
                        break;
                }
            }
            else if(choice==3)
            {
               if(loginstudent.ResultsEnquiry()==1)
                   continue;
            }
            else if(choice==4)
                cout<<"It's To Be Finished"<<endl;
            else if(choice==5)
                loginstudent.remind();
            else if(choice==6)
                loginstudent.whetherhomework();
            else if(choice==7)
                {
                	loginstudent.handinhomework();
                }
            else if(choice==8)
            {
                int choicein;
            cout<<"1)查看历史记录;2)删除历史记录"<<endl;
            cin>>choicein;
            if(choicein==2)
                loginstudent.deletemessage2();
            else
                loginstudent.historymessage();
            }
            else if(choice==9)
                break;
        }
        
    }
}


void AfterLogin::Welcome()
{
    cout<<"Login Successfully!"<<endl<<"------------------------------------------------------"<<endl<<"Dear "<<name<<", "<<"Welcome To The Interaction System."<<endl;
    
}
