#include<iostream>
#include"user.hpp"
#include"doctor.hpp"
#include"admin.hpp"
#include "patient.hpp"
#include <string>

User* userType(std::string type)
{
    if(type=="ADMINISTRATOR")
    {
        return new Admin();
    }
    if(type=="PATIENT")
    {
        return new Patient();
    }
    if(type=="DOCTOR")
    {
        return new Doctor();
    }
    return NULL;
}
