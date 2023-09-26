#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include "../headers/User.hpp"
#include "../headers/Menu.hpp"
#include<iostream>
using std::string;
using std::cout;

class Doctor: public User
{
    public:
        string doctorID,doctorName,Specialization;
        Doctor(){}
        ~Doctor(){}
        Doctor(string doctorID,string doctorName,string Specialization):
        doctorID(doctorID),doctorName(doctorName),Specialization(Specialization){}
        void home(string &);
};

void Doctor::home(string &userid)
{
    cout<<"\t\t*** Welcome "<<userid<<" ***"<<std::endl;
    doctor_Menu();
}
#endif