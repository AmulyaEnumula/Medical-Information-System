#ifndef PATIENT_HPP
#define PATIENT_HPP
#include "../headers/User.hpp"
#include "../headers/AppointmentScheduling.hpp"
#include "../headers/Menu.hpp"
#include<iostream>
using std::string;
using std::cout;
using std::cin;

class Patient:public User
{
    public:
    string patientID,patientName,gender,medical_history,allergies,medication,mobileNo;
    int age;
    Patient(){}
    ~Patient(){}
    Patient(string patientID,string patientName,string gender,int age,string medical_history,string allergies,string medication,string mobileNo):
    patientID(patientID),patientName(patientName),gender(gender),age(age),medical_history(medical_history),allergies(allergies),medication(medication),mobileNo(mobileNo){}
    void home(string &);
};
void Patient::home(string &userId)
{
    cout<<"\t\t*** Welcome "<<userId<<" ***"<<std::endl;
    Appointment appointment;
    int choice;
    try
    {
        do
        {
            patient_Menu();
            cout<<"-------------------------------------------------------------------------------------------------\n";
            cout<<"Input your choice:";
            cin>>choice;
            cout<<"\n";
            switch(choice)
            {
                case 1: appointment.bookingAppointment(userId);
                        break;
                case 2: appointment.viewAppointment(userId,"patient");
                        break;
                case 3: cout<<"Logging out...\nLogout Successful!!!\n";
                        break;
                default: 
                        cout<<"Invalid choice....Enter any option from 1-3 given in drop down Menu\n";
            }
        }while(choice!=3);
    }
    catch(std::exception &e)
    {
        cout<<e.what()<<"\n";
    }
}
#endif