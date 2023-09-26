#include "../headers/Factory.hpp"
#include "../headers/Authentication.hpp"

int main()
{
    cout<<"-----------------------------------------------------------------------------------------\n";
    cout<<"|\t\t\tWELCOME TO MEDICAL INFORMATION SYSTEM\t\t\t\t|\n";
    cout<<"-----------------------------------------------------------------------------------------\n";
    Login login_obj;
    Signup signup_obj;
    string userid,username,password,accessType;
    int option;
    do
    {
        cout<<"-----------------------------------------------------------------------------------------\n";
        entry_Menu();
        cout<<"Enter your option:";
        try
        {
            cin>>option;
            cout<<"\n";
            switch(option)
            {
                case 1: {
                            cout<<"Enter Login credentials:-\n";
                            cout<<"User ID:";
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,userid);
                            cout<<"Password:";
                            cin>>password;
                            accessType=login_obj.authenticate(userid,password);
                            User *user=userType(accessType);
                            if(user)
                            {
                                user->home(userid);
                            }
                            else
                            {
                                cout<<accessType<<"\n";
                            }
                            delete user;
                            break;
                        }

                case 2: {
                            cout<<"Enter Signup credentials:-\n";
                            cout<<"Username:";
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            getline(cin,username);
                            cout<<"Password:";
                            cin>>password;
                            accessType="PATIENT";
                            userid=generateID(username);
                            signup_obj.signUp(userid,username,password,accessType);
                            cout<<"Signup Successful!!!\n";
                            cout<<"Your ID for future Login is "<<userid<<"\n";
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