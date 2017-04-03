
#include "Remind.h"
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

Remind::Remind(int month,int day,int nowmonth,int nowday)
{
    this->month=month;
    this->day=day;
    this->nowday=nowday;
    this->nowmonth=nowmonth;
}

bool Remind::Warning()
{
    if(month==nowmonth&&hour==nowhour&&day==nowday)
        return true;
    else
        return false;
}

