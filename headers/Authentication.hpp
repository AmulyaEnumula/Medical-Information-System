#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

class Login
{
    public:
    fstream loginFile;
    
    string HashPassword(string &password)
    {
        int len=password.length();
        string hashedPassword=password;
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(isalpha(password[i]))
            {
                if(isupper(password[i]))
                {
                    hashedPassword[j]=tolower(password[i]);
                    j++;
                }
                else
                {
                    hashedPassword[j]=toupper(password[i]);
                    j++;
                }
            }
            else if(isdigit(password[i]))
            {
                hashedPassword[j]=password[i]+9;
                j++;
            }
            else
            {
                hashedPassword[j]='~';
                j++;
            }
        }
        //cout<<hashedPassword;
        return hashedPassword;
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