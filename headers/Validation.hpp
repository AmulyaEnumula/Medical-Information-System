#ifndef Validation
    #define Validation
#include<iostream>
#include<ctime>
#include<fstream>
#include<sstream>
#include<regex>
using namespace std;

bool is_Valid_MobileNo(string &number)
{
    const regex pattern("[6-9][0-9]{9}");
    if(regex_match(number,pattern))
    {
        return true;
    }
    cout<<"Phone number Invalid\n";
    return false;
}

bool isleap(int year)
{
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool is_Date(int &d,int &m,int &y)
{
    if(y<0)
    return false;
    if(m<1 || m>12)
    return false;
    if(d<1 || d>31)
    return false;

    if(m==2)
    {
        if(isleap(y))
        return (d<=29);
        else
        return (d<=28);
    }

    if(m==4 || m==6 || m==9 || m==11)
    return (d<=30);

    return true;
}

bool is_Valid_Date(string date)
{
    //Get the current date
    time_t currentTime=time(nullptr);
    tm currentDate=*localtime(&currentTime);

    string Date=date.substr(0,2);
    int d=stoi(Date);
    string month=date.substr(3,2);
    int m=stoi(month);
    string year=date.substr(6,4);
    int y=stoi(year);
    if(is_Date(d,m,y))
    {
        if(y>=currentDate.tm_year)
        {
            if(m>=currentDate.tm_mon)
            {
                if(d>=currentDate.tm_mday)
                    return true;
            }
        }
    }
    else
    {
        cout<<"Invalid date...Enter date in DD-MM-YYYY format\n";
        return false;
    }
    cout<<"The date is in the past. Enter appropriate date\n";
    return false;
}

bool is_Valid_Doctor(string &dName)
{
    fstream file;
    file.open("../data/DoctorInfo.csv",ios::in); 
    if(file.is_open())
    {
        string line; 
        while(getline(file,line))
        {
            string name;
            stringstream s(line); 
            getline(s,name,',');
            if(dName==name)
            {
                return true;
            }
        }
        file.close();
    }
    else
    {
        cout<<"File opening failed\n";
    }
    return false;
}
bool isFound(string &username)
{
    ifstream file("../data/login.csv");
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            string name;
            stringstream s(line);
            getline(s,name,',');
            if(username==name)
            return true;
        }
        file.close();
    }
    else
    {
        cout<<"File opening failed\n";
    }
    return false;
}
#endif