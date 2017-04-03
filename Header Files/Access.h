////
////  Access.h
////  System
////
////  Created by Seven on 14-4-6.
////  Copyright (c) 2014年 A.D.A.I. All rights reserved.
////

#ifndef __System__Access__
#define __System__Access__

#include <iostream>
using namespace std;
class Access
{
private:
    int trytimes;
    string checkname;
    int checkid;
    string Accesscode;
public:
    Access(string checkname);
    Access (int checkid);
    bool check();
    bool Checkname();
    bool loginid();
    bool loginpassword();
    bool Checkid();
    bool whetherteacher(int tem_id);
    string inputcode;
};
#endif //* defined(__System__Access__) */
