
#include "Gettime.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>
using namespace std;
#include <ctime>
string Gettime::printtime()
{
    
        time_t ltime;
        
        time(& ltime);
        
        string a=ctime(&ltime);
    
        return a;
    
    
}
void Gettime::rightnow()
{
    tm *year; ////年
    tm *month; ////月
    tm *day; ////日
    tm *hour;////时
    tm *minute;
    tm *second; time_t t;
    t=time(0);  year   = localtime(&t);
    month  = localtime(&t);
    day    = localtime(&t);
    hour   = localtime(&t);
    minute = localtime(&t);
    second = localtime(&t); cout<<(year ->tm_year+1900)<<"��"  ////返回的是今年减1900,所以要加上1900
    <<(month->tm_mon+1)<<"��"     ////因为Month (0 – 11; January = 0),所以要加1
    <<day   ->tm_mday<<"��"
    <<hour  ->tm_hour<<"ʱ"
    <<minute->tm_min<<"��"
    <<second->tm_sec<<"��"
    <<endl;

}
int Gettime::hour()
{
    tm *year; ////年
    tm *month; ////月
    tm *day; ////日
    tm *hour;////时
    tm *minute;
    tm *second; time_t t;
    t=time(0);  year   = localtime(&t);
    month  = localtime(&t);
    day    = localtime(&t);
    hour   = localtime(&t);
    minute = localtime(&t);
    second = localtime(&t);
    return hour->tm_hour;
}
int Gettime::day()
{
    tm *year; ////年
    tm *month; ////月
    tm *day; ////日
    tm *hour;////时
    tm *minute;
    tm *second; time_t t;
    t=time(0);  year   = localtime(&t);
    month  = localtime(&t);
    day    = localtime(&t);
    hour   = localtime(&t);
    minute = localtime(&t);
    second = localtime(&t);
    return day->tm_mday;
}

int Gettime::month()
{
    tm *year; ////年
    tm *month; ////月
    tm *day; ////日
    tm *hour;////时
    tm *minute;
    tm *second; time_t t;
    t=time(0);  year   = localtime(&t);
    month  = localtime(&t);
    day    = localtime(&t);
    hour   = localtime(&t);
    minute = localtime(&t);
    second = localtime(&t);
    return month->tm_mon+1;
}
