#include "../headers/Authentication.hpp"
#include "../headers/Menu.hpp"
#include "../headers/AppointmentScheduling.hpp"
#include<algorithm>

int main()
{
    Login login;
    string username,password,capitalName;
    cout<<"Enter Login credentials:-\n";
    cout<<"Username:";
    getline(cin,username);
    cout<<"Password:";
    cin>>password;
    string accessType=login.authenticate(username,password);
    transform(username.begin(),username.end(),capitalName.begin(),::toupper);
    if(accessType=="ADMINISTRATOR")
    {
        cout<<"Welcome "<<capitalName<<endl;
    }
    else if(accessType=="DOCTOR")
    {
        cout<<"Welcome "<<capitalName<<endl;
    }
    else if(accessType=="PATIENT")
    {
        cout<<"\t\t*** Welcome "<<capitalName<<" ***"<<endl;
        patient_Menu();
        Appointment appointment;
        int choice;
        do
        {
            cout<<"Input your choice:";
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
        }while(choice!=3);
    }
    else
    {
        cout<<accessType;
    }
    return 0;
}