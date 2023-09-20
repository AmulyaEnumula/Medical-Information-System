#include<iostream>
#include "../headers/Admin.hpp"
#include "../headers/Doctor.hpp"
#include "../headers/Patient.hpp"

User* userType(std::string accessLevel)
{
    if(accessLevel=="ADMINISTRATOR")
    {
        return new Admin();
    }
    if(accessLevel=="PATIENT")
    {
        return new Patient();
    }
    if(accessLevel=="DOCTOR")
    {
        return new Doctor();
    }
    return NULL;
}