//
//  Gettime.h
//  System
//
//  Created by Seven on 14-4-5.
//  Copyright (c) 2014年 A.D.A.I. All rights reserved.
//

#ifndef __System__Gettime__
#define __System__Gettime__

#include <iostream>
using namespace std;
class Gettime
{
private:
    string a;
public:
    string printtime();
    void rightnow();
    int hour();
    int day();
    int month();
};

#endif //* defined(__System__Gettime__) *//
