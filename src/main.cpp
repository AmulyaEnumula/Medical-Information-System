#include "../headers/Factory.hpp"
#include "../headers/Authentication.hpp"

int main()
{
    Login login_obj;
    Signup signup_obj;
    string username,password,accessType;
    int option;
    do
    {
        entry_Menu();
        cout<<"Enter your option:";
        try
        {
            cin>>option;
            switch(option)
            {
                case 1: {
                        cout<<"Enter Login credentials:-\n";
                        cout<<"Username:";
                        cin.ignore();
                        getline(cin,username);
                        cout<<"Password:";
                        cin>>password;
                        accessType=login_obj.authenticate(username,password);
                        User *user=userType(accessType);
                        user->home(username);
                        break;
                        }

                case 2: {
                        cout<<"Enter Signup credentials:-\n";
                        cout<<"Username:";
                        cin.ignore();
                        getline(cin,username);
                        cout<<"Password:";
                        cin>>password;
                        accessType="PATIENT";
                        if(!isFound(username))
                        {
                            signup_obj.signUp(username,password,accessType);
                            cout<<"Signup Successful!!!\n";
                        }
                        else
                        {
                            cout<<"Username already exists...Choose a different one\n";
                        }
                        break;
                        }

                case 3: {
                        exit(0);
                        break;
                        }

                default: cout<<"Invalid option. Options are from 1-3\n";
                         break;
            }
        }
        catch(std::exception &e)
        {
            cerr<<e.what()<<"\n";
        }
    }while(option!=3);
    return 0;
}