#include "../headers/Authentication.hpp"

int main()
{
    Login login;
    string username,password;
    cout<<"Enter Login credentials:-\n";
    cout<<"Username:";
    cin>>username;
    cout<<"Password:";
    cin>>password;
    string accessType=login.authenticate(username,password);
    
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
        cout<<"Welcome "<<username<<endl;
    }
    else
        cout<<accessType;
    return 0;
}