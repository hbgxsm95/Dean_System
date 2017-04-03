
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
using namespace std;
bool All();
int main()
{
    while(1)
    {
        if(All()==1)
          continue;
        else
            break;
    }
    
}
bool All()
{
    Mkdir Beginning;
    Beginning.beginapp();
    Framework Menu;
    Menu.welcome();
    while(1)
    {
        Menu.welcome2();
        int m;
        cin>>m;
        if(m==1)
        {
            Access Initialcheck("ADAI");
            if(Initialcheck.check()==false)
                return 0;
            
            string end;
            Menu.NewTeacher();
            cout<<"If U Wanna Return To The Previous Menu,Please Input 1,Or Any Other Character To End!"<<endl;
            cin>>end;
            if(end=="1")
               continue;
            else
                exit(1);
        }
        else if(m==2)
        {
            string end;
            Menu.NewStudent();
            cout<<"If U Wanna Return To The Previous Menu,Please Input 1,Or Any Other Character To End!"<<endl;
            cin>>end;
            if(end=="1")
                continue;
            else
                exit(1);

        }
        else if(m==3)
        {
            int login1,mistake=0;
            string login2;
            while(1)
            {
                cout<<"Please Input Your ID"<<endl;
                cin>>login1;
                Access idlogin(login1);
                if(idlogin.loginid()==false)
                {
                    cout<<"No Such Accounts Exsit!  Please Retry!"<<endl;
                     mistake++;
                    if(mistake>=3)
                     {
                       cout<<"Sorry For Access Failure. System Closed Right Now!"<<endl;
                         exit(1);
                     }
                   cout<<"You Still Have "<<3-mistake<<" Chances Left! Please ReInput."<<endl;
                   continue;
                
               }
                mistake=0;
                while(1)
               {
                   cout<<"Please Input Your Password"<<endl;
                   cin>>login2;
                   if(idlogin.whetherteacher(login1)==true)
                     {
                        string position="Private\\Teachers\\ID2.dat";
                        ifstream infile(position.c_str(),ios::in);
                        int a,bir;
                        string b,c,les;
                        while(infile>>a>>b>>c>>les>>bir)
                         
                           if(a==login1)
                            {
                                infile.close();
                                position="Private\\Teachers\\"+c+"\\"+c+".dat";
                                infile.open(position.c_str(),ios::in);
                                infile>>a>>b;
                            if(b==login2)
                              {
                                  AfterLogin LoginTeacher(login1,login2,c,les,bir,true);
                                  LoginTeacher.Start();
                                  return 1;
                              }
                            }
                        
                        cout<<"Access Failure!  Wrong Password!"<<endl;
                         mistake++;
                         if(mistake>=3)
                         {
                             cout<<"Sorry For Access Failure. The System Will Close."<<endl;
                             infile.close();
                             return 1;
                         }
                         cout<<"You Still Have "<<3-mistake<<" Chances Left! Please ReInput."<<endl;
                         infile.close();
                         continue;

                     }
                   else
                  {
                      string position="Private\\Students\\ID2.dat";
                      ifstream infile(position.c_str(),ios::in);
                      int a,bir;
                      string b,c;
                      while(infile>>a>>b>>c>>bir)
                      {
                          if(a==login1)
                          {
                              infile.close();
                              position="Private\\Students\\"+c+"\\"+c+".dat";
                              infile.open(position.c_str(),ios::in);
                              infile>>a>>b;
                              if(b==login2)
                              {
                                AfterLogin LoginStudents(login1,login2,c,bir,false);
                                LoginStudents.Start();
                                return 1;
                              }
                              
                          }
                      }
                      cout<<"Access Failure!  Wrong Password!"<<endl;
                      mistake++;
                      if(mistake>=3)
                      {
                          cout<<"Sorry For Access Failure. The System Will Close."<<endl;
                          infile.close();
                          return 1;
                      }
                      cout<<"You Still Have "<<3-mistake<<" Chances Left! Please ReInput."<<endl;
                      infile.close();
                      continue;
 
                  }
            
        }
    }
        }
        else if(m==4)
            return 0;
    }
}

