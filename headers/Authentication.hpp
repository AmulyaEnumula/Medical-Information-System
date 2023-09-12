#include<fstream>
#include<sstream>
#include<iostream>
#include<conio.h>
using namespace std;
class Login
{
    public:
    fstream loginFile;
    string password()
    {
        string pwd="";
        char ch;
        while(true)
        {
            ch=_getch();
            if(ch==13)
            break;
            else if(ch==8)
            {
                if(!pwd.empty())
                {
                    pwd.pop_back();
                    cout<<"\b \b";
                }
            }
            else
            {
                pwd+=ch;
                cout<<'*';
            }
        }
        cout<<"\n";
        return pwd;
    }
    string HashPassword(string &password)
    {
        int hashedPassword=0;
        int size=password.length();
        for(int i=0;i<size;i++)
        {
            srand(size*password[i]);
            hashedPassword+=33+rand()%92;
        }
        return to_string(hashedPassword);
    }
    string authenticate(string &username,string &password)
    {
        loginFile.open("../data/login.csv");
        if(loginFile.is_open())
        {
            string line;
            while(getline(loginFile,line))
            {
                string name,pwd,accessLevel;
                stringstream s(line);
                getline(s,name,',');
                getline(s,pwd,',');
                getline(s,accessLevel,',');
                if(username==name)
                {
                    string hashedPassword=HashPassword(password);
                    if(hashedPassword==pwd)
                        return accessLevel;
                    else 
                        return "Invalid Password";
                }
            }
            loginFile.close();
        }
        else
        {
            cout<<"File opening failed\n";
        }
        return "User Not Found";
    }
};