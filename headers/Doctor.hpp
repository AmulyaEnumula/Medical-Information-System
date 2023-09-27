#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include "../headers/User.hpp"
#include "../headers/Menu.hpp"
#include "../headers/AppointmentScheduling.hpp"
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
void Doctor::home(string &userId)
{
    cout<<"\t\t*** Welcome "<<userId<<" ***"<<std::endl;
    Appointment appointment;
    char input;
    do
    {
        doctor_Menu();
        cout<<"-------------------------------------------------------------------------------------------------\n";
        cout<<"Select your option from menu: ";
        try
        {
            cin>>input;
            cout<<"\n";
            if(!isdigit(input))
            {
                throw input;
            }
            int option=input-'0'; //converts char '1' to int 1
            switch(option)
            {
                case 1: {
                            appointment.scheduleAppointment(userId);
                            break;
                        }
                case 2: 
                        {
                            appointment.viewAppointment(userId,"doctor");
                            break;
                        }
                case 3: 
                        {
                            cout<<"***** Successfully Logged Out *****\n";
                            break;
                        }
                default:
                        cout<<"Invalid choice....Enter any option from 1-3 given in Menu\n";
            }
        }
        catch(std::exception &e)
        {
            cout<<e.what()<<"\n";
        }
    }while(input!='3');
}
#endif