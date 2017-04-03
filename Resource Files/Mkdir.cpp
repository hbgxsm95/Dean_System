

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
#include "Mkdir.h"
void Mkdir::beginapp()
{
    if(opendir("Data")==NULL)
        system("mkdir Data");
    if(opendir("Data\\Teachers")==NULL)
        system("mkdir Data\\Teachers");
    if(opendir("Data\\Students")==NULL)
        system("mkdir Data\\Students");
    if(opendir("Private")==NULL)
        system("mkdir Private");
    if(opendir("Private\\Teachers")==NULL)
        system("mkdir Private\\Teachers");
    if(opendir("Private\\Students")==NULL)
        system("mkdir Private\\Students");
    if(opendir("Data\\Announcements")==NULL)
        system("mkdir Data\\Announcements");
    if(opendir("Data\\Teachers\\Homework")==NULL)
        system("mkdir Data\\Teachers\\Homework");
}
