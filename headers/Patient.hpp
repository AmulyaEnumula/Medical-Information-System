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
void Patient::home(string &userid)
{
    cout<<"\t\t*** Welcome "<<userid<<" ***"<<std::endl;
    patient_Menu();
    Appointment appointment;
    int choice;
    do
    {
        cout<<"Input your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: appointment.bookingAppointment(userid);
                    break;
            case 2: appointment.viewAppointment(userid);
                    break;
            case 3: cout<<"Logging out...\nLogout Successful!!!\n";
                    break;
            default: 
                    cout<<"Enter option from drop down Menu\n";
        }
    }while(choice!=3);
}
#endif