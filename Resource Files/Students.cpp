

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
Students::Students(string name,int id,string password,int birthday)
{
    this->name=name;
    this->id=id;
    this->password=password;
    this->birthday=birthday;
}

void Students::StudentsSet()
{
    string a="Data\\Students\\"+name;
    if(opendir(a.c_str())==NULL)
    {
        a="mkdir "+a;
        system(a.c_str());
    }
    string b="Data\\Students\\"+name+"\\Message";
    if(opendir(b.c_str())==NULL)
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    b="Private\\Students\\"+name;
    string PrivateInfo=b+"\\"+name+"Info.dat";
    string Privateid=b+"\\"+name+".dat";
    if(opendir(b.c_str())==NULL)
        
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    ofstream outfile(Privateid.c_str(),ios::app);
    outfile<<id<<' '<<password;
    outfile.close();
    ofstream outfile2(PrivateInfo.c_str(),ios::app);
    outfile2<<name<<' '<<id<<' '<<birthday;
    outfile2.close();
    b="Private\\Students\\ID.dat";
    outfile.open(b.c_str(),ios::app);
    outfile<<id<<' ';
    outfile.close();
    b="Private\\Students\\ID2.dat";
    outfile.open(b.c_str(),ios::app);
    outfile<<id<<' '<<password<<' '<<name<<' '<<birthday<<' '<<endl;
    outfile.close();
    b="Private\\Students\\"+name+"\\Logintime.dat";
    outfile.open(b.c_str(),ios::out);
    Gettime now;
    outfile<<now.printtime()<<endl;
    outfile.close();
    b="Private\\Students\\"+name+"\\Remind";
    if(opendir(b.c_str())==NULL)
    {
        b="mkdir "+b;
        system(b.c_str());
    }
    b="Private\\Students\\"+name+"\\Remind\\remind.dat";
    outfile.open(b.c_str(),ios::out);
    outfile.close();
    b="Data\\Students\\"+name+"\\Message\\Message.dat";
    outfile.open(b.c_str(),ios::out);
    outfile.close();
    b="Data\\Students\\"+name+"\\Message\\Message2.dat";
    outfile.open(b.c_str(),ios::out);
    outfile.close();


 }

bool Students::ResultsEnquiry()
{
    string a,b,d;
    string number,text;
    
    while(1)
    {
        cout<<"Please Enter The Name Of Your Teacher"<<endl;
        cin>>b;
        d="Data\\Teachers\\"+b;
        if(opendir(d.c_str())==NULL)
        {
            cout<<"There Is No Such A Teacher!Please Retry!"<<endl;
            cout<<"If You Wanna Return The Previous Menu,Please Input 1 Or 0 To Continue it"<<endl;
            int subchoice;
            cin>>subchoice;
            if(subchoice==1)
                return 1;
            else
               continue;
        }
             while(1)
       {
           cout<<"Please Enter The Name Of The Test!"<<endl;
           cin>>a;
            a=d+"\\Tests\\"+a;
           if(opendir(a.c_str())==NULL)
           {
               cout<<"No Such A Test"<<endl;
               cout<<"Please Retry!"<<endl;
               cout<<"If You Wanna Return The Previous Menu,Please Input 1 Or 0 To Continue it"<<endl;
               int subchoice;
               cin>>subchoice;
               if(subchoice==1)
                   return 1;
               else
                  continue;
           }
           else break;
       }
  
        while(1)
        {
            cout<<"Please Input Your ID"<<endl;
            cin>>d;
            d=a+"\\"+d+".dat";
            ifstream infile(d.c_str(),ios::in);
            if(!infile)
            {
                cerr<<"There Is No Exam Result Of You!"<<endl;
                cout<<"If U Wanna ReInput Your ID,Please Input 1,Or Any Other Character To The Previous Menu"<<endl;
                cin>>number;
                if(number=="1")
                    continue;
                else
                    return 1;
            }
            else
            {
                infile>>text;
                cout<<"Dear "<<text<<" ,Your Score Is: ";
                infile>>text;
                cout<<text<<endl;
            }
            infile.close();
            return 0;
        }
    }
    return 0;
}
bool Students::messages()
{
    string message="Data\\Students\\"+name+"\\"+"Message\\Message.dat";
    ifstream infile,infile2;
    infile.open(message.c_str(),ios::in);
    infile2.open(message.c_str(),ios::in);
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
            return false;
    }
    else
    {
        cout<<"No New Message!"<<endl;
        infile2.close();
        return false;
    }
}

void Students::leavemessage()
{
    while(1)
    {
        string teachername;
        cout<<"Please Input The Teacher's Name You Wanna Leave Messages!"<<endl;
        cin>>teachername;
        string position="Data\\Teachers\\"+teachername+"\\Message";
        string position2=position;
        if(opendir(position.c_str())==NULL)
        {
            cout<<"No Such A Teacher!"<<endl
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
        cout<<"If U Wanna Leave Messages To Another Teacher,Please Input 1,Or Any Other Character To The Previous Menu."<<endl;
        string choice2;
        cin>>choice2;
        if(choice2=="1")
            continue;
        else
            break;
    }
}

void Students::answermessages()
{
    while(1)
    {
        string teachername;
        cout<<"Please Input The Teacher's Name You Wanna Answer!"<<endl;
        cin>>teachername;
        string position="Data\\Teachers\\"+teachername+"\\Message";
        string position2=position;
        if(opendir(position.c_str())==NULL)
        {
            cout<<"No Such A Teacher!"<<endl
            <<"If You Wanna Retry, Please Input 1,Or Any Other Character To The Previous Menu!"<<endl;
            string choice;
            cin>>choice;
            if(choice=="1")
                break;
            else
                continue;
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
            outfile<<endl;
            outfile.close();
            outfile2.close();
        }
        cout<<"If U Wanna Answer Another Teacher,Please Input 1,Or Any Other Character To Continue."<<endl;
        string choice2;
        cin>>choice2;
        if(choice2=="1")
            continue;
        else
            break;
    }

}

void Students::Annoucements()
{
    while(1)
    {
    cout<<"Welcome To The Part Of Announcements!"
    <<endl;
    string a;
    ifstream infile("Data\\Announcements\\Lessons.dat",ios::in);
    if(!infile)
    {
        cerr<<"No Files!"<<endl;
        break;
    }

    while(infile>>a)
    {
        string b="Data\\Announcements\\"+a+"\\Announcements.dat";
        ifstream infile2(b.c_str(),ios::in);
        if(!infile2)
        {
            cerr<<"No Announcements!"<<endl;
        }

    while(getline(infile2,b))
    {
        
        cout<<b;
        cout<<endl;
    }
        infile2.close();
    }
    infile.close();
        break;
    
}
}

bool Students::Checkhe()
{
    string teachername;
    while(1)
   {
    cout<<"Please Enter the Teacher's Name U Wanna Check!"<<endl;
    cin>>teachername;
    string b="Private\\Teachers\\"+teachername;
    if(opendir(b.c_str())==NULL)
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
       
    else
    {
        string a;
        b=b+"\\"+teachername+"Info.dat";
        ifstream infile(b.c_str(),ios::in);
        cout<<"His Name: ";
        infile>>a;
        cout<<a<<endl;
        cout<<"His ID: ";
        infile>>a;
        cout<<a<<endl;
        cout<<"His Lessonname: ";
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

void Students::Checkme()
{

        string a;
        string PrivateInfo="Private\\Students\\"+name+"\\"+name+"Info.dat";
        ifstream infile(PrivateInfo.c_str(),ios::in);
        cout<<"Your Name: ";
        infile>>a;
        cout<<a<<endl;
        cout<<"Your ID: ";
        infile>>a;
        cout<<a<<endl;
        cout<<"Your Birthday: ";
        infile>>a;
        cout<<a<<endl;
        infile.close();

}

void Students::ChangePassword()
{
    
    string PrivateCode1="Private\\Students\\"+name+"\\"+name+".dat";
    cout<<"Please Enter Your New Password: ";
    while(1)
    {
        string a,c;
        cin>>a;
        cout<<"Please ReInput Your New Password: ";
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

void Students::remind()
{
    string month,day;
    cout<<"Please Set Your Reminding Month"<<endl;
    cin>>month;
    cout<<"Please Set Your Reminding Day"<<endl;
    cin>>day;
    ofstream outfile;
    string position="Private\\Students\\"+name+"\\Remind\\"+month+day+".dat";
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




void Students::whetherhomework()
{
    ifstream infile;
    string a="Data\\Teachers\\Homework\\Homework.dat";
    string bname,cindex;
    infile.open(a.c_str(),ios::in);
    while(1)
    {
        if(infile>>bname>>cindex)
        {
            ifstream infile2;
            string b="Data\\Teachers\\Homework\\"+bname+cindex+".dat";
            infile2.open(b.c_str(),ios::in);
            char ch;
            while(infile2.get(ch))
                cout<<ch;
            cout<<endl<<"The Homework Is Assigned By "<<bname<<endl;
            infile2.close();
        }
        else
            break;
    }
    infile.close();
     cout<<"That's All The Homework You Need To Do!"<<endl;
}



void Students::deletemessage2()
{
    string a="Data\\Students\\"+name+"\\Message\\Message2.dat";
    ofstream outfile;
    outfile.open(a.c_str(),ios::out);
    outfile.close();
}

void Students::historymessage()
{
    string a="Data\\Students\\"+name+"\\Message\\Message2.dat";
    ifstream infile(a.c_str(),ios::in);
    char ch;
    while(infile.get(ch))
        cout<<ch;
    infile.close();
}

bool Students::handinhomework()
{
	int homeworkid2=id;
	string position="Data\\Teachers\\Homework\\Trash.dat",homeworkid;
    ofstream outfile3(position.c_str(),ios::out);
    outfile3<<homeworkid2;
    outfile3.close();
    ifstream infile3(position.c_str(),ios::in);
    infile3>>homeworkid;
    infile3.close();
    cout<<"Please Drag Your Homework From The Screen Into The Cmd Window And Press Return"<<endl;
    cout<<"Attention!  The Name Of The Homework You Hand In Should'nt Include Any Blanks!"<<endl;
    string SourceFile;
    string NewFile;
    string homeworkindex;
    
    while(1)
    {
        cout<<"Please Input Your Teacher's Name!"<<endl;
        cin>>SourceFile;
        string b="Data\\Teachers\\"+SourceFile;
        if(opendir(b.c_str())==NULL)
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
       
        else
         {
             
             while(1)
             {
                 cout<<"Please Input The Index Of Homework"<<endl;
                 cin>>homeworkindex;
                 b=b+"\\Homework\\"+homeworkindex;
                 if(opendir(b.c_str())==NULL)
                 {
                    cout<<"No Such Homework Assignments! Please Reinput The Index Of Your Homework"<<endl;
                     cout<<"If You Wanna Return The Previous Menu,Please Input 1 Or 0 To Continue it"<<endl;
                     int subchoice;
                     cin>>subchoice;
                     if(subchoice==1)
                         return 1;
                     else
                         continue;
                 }
                 else break;
                 
                 
             }
             while(1)
             {
                 NewFile="Data\\Teachers\\"+SourceFile+"\\Homework\\"+homeworkindex+"\\"+homeworkid+".dat";
                 cout<<"Please Drag Your Homework From The Screen To The Cmd Window. (If You're A Mac User,Please Drag To The Bash Window)"<<endl;
                 cin>>SourceFile;
                 ifstream in;
                 ofstream out;
                 in.open(SourceFile.c_str(),ios::binary);
                 if(in.fail())
                 {
                     cout<<"Error 1: Fail to open the source file."<<endl;
                     in.close();
                     out.close();
                     cout<<"If You Wanna Return The Previous Menu,Please Input 1 Or 0 To Continue it"<<endl;
                     int subchoice;
                     cin>>subchoice;
                     if(subchoice==1)
                         return 1;
                     else
                         continue;
                 }
                 out.open(NewFile.c_str(),ios::binary);////创建目标文件
                 if(out.fail())////创建文件失败
                 {
                     cout<<"Error 2: Fail to create the new file.Now Return To The Previous Menu!"<<endl;
                     out.close();
                     in.close();
                     return 1;
                 }
                 else////复制文件
                 {
                     out<<in.rdbuf();
                     out.close();
                     in.close();
                     cout<<"Congradulations!  Your Homework Has Been Handed In Successfully!"<<endl
                     <<"Now Return To The Previous Menu!"<<endl;
                     return 1;
                 }
             }

         }
}
}
