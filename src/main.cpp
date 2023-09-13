#include "../headers/Authentication.hpp"
#include "../headers/Menu.hpp"
#include "../headers/AppointmentScheduling.hpp"
#include<algorithm>

int main()
{
    Login login;
    string username,password;
    cout<<"Enter Login credentials:-\n";
    cout<<"Username:";
    getline(cin,username);
    cout<<"Password:";
    cin>>password;
    string accessType=login.authenticate(username,password);
    transform(username.begin(),username.end(),username.begin(),::toupper);
    if(accessType=="ADMINISTRATOR")
    {
        cout<<"Welcome "<<username<<endl;
    }
    else if(accessType=="DOCTOR")
    {
        cout<<"Welcome "<<username<<endl;
    }
    else if(accessType=="PATIENT")
    {
        cout<<"\t\t*** Welcome "<<username<<" ***"<<endl;
        patient_Menu();
        Appointment appointment;
        cout<<"Input your choice:";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1: appointment.bookingAppointment(username);
                    break;
            case 2: appointment.viewAppointment(username);
                    break;
            case 3: cout<<"Logging out...\nLogout Successful!!!\n";
                    break;
            default: 
                    cout<<"Enter option from drop down Menu\n";
        }
    }
    else
    {
        cout<<accessType;
    }
    return 0;
}