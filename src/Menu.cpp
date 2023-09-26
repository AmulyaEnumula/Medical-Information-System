//#include "../headers/Menu.hpp"
#include<iostream>
using namespace std;
void entry_Menu()
{
    cout<<"1. Log In\n";
    cout<<"2. Sign Up\n";
    cout<<"3. EXIT\n";
}
void admin_Menu()
{ 
    cout<<"\n";
    cout<<"Here is what you can do-\n"; 
    cout<<"----------------------------------------\n"; 
    cout<<"1. Access Doctor details\n"; 
    cout<<"2. Access Patient details\n"; 
    cout<<"3. Filter Patient Records\n"; 
    cout<<"4. Logout\n"; 
}
void doctor_Menu()
{
    cout<<"\n";
    cout<<"Here is what you can do-\n";
    cout<<"1. Schedule an Appointment\n";
    cout<<"2. View my Appointments\n";
    cout<<"3. Logout\n";
}
void patient_Menu()
{
    cout<<"\n";
    cout<<"Here is what you can do-\n";
    cout<<"1. Book an Appointment\n";
    cout<<"2. View my Appointments\n";
    cout<<"3. Logout\n";
}