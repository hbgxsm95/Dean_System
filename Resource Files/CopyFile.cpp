
#include "Students.h"
#include <direct.h>
#include <windows.h>
#include <dirent.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include "Gettime.h"
#include "CopyFile.h"
using namespace std;
CopyFile::CopyFile(int homeworkid2)
{
	this->homeworkid2=homeworkid2;
}
bool CopyFile::Homework()
{
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
