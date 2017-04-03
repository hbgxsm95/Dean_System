////
////  Remind.h
////  System
////
////  Created by Seven on 14-4-7.
////  Copyright (c) 2014年 A.D.A.I. All rights reserved.
////

#ifndef __System__Remind__
#define __System__Remind__

#include <iostream>
class Remind
{
private:
    int hour;
    int day;
    int month;
    int nowhour;
    int nowday;
    int nowmonth;
public:
    Remind(int month,int day,int nowmonth,int nowday);
    bool Warning();
    
};
#endif //* defined(__System__Remind__) *//
