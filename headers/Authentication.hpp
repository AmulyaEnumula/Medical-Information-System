#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

class Login
{
    public:
    fstream loginFile;
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
                    if(password==pwd)
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