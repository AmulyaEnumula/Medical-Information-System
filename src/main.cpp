#include "../headers/Authentication.hpp"

int main()
{
    Login login;
    string username,password;
    cout<<"Enter Login credentials:-\n";
    cout<<"Username:";
    getline(cin,username);
    cout<<"Password:";
    //password =login.password(); // fix later
    std::cin>>password;
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
        cout<<"Press 1 for booking";
        cout<<"Press 2 view booking";
        
        int t;
        cin>>i;
        {
            cout<<"enter doc id";
            cin>>" "
        }
        
    }
    else{
        cout<<accessType;
    }
        
    return 0;
}