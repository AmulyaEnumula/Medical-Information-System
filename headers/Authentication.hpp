#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

string generateID(string &username)
{
    char ch='p';
    string alpha=username.substr(0,3);
    srand(time(0));
    int numeric=rand() % 100000;
    string ID=to_string(ch)+alpha+to_string(numeric);
    return ID;
}
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
class Login
{
    public:
    string authenticate(string &userid,string &password)
    {
        ifstream file("../data/login.csv");
        if(file.is_open())
        {
            string line;
            while(getline(file,line))
            {
                string id,name,pwd,accessLevel;
                stringstream s(line);
                getline(s,id,',');
                getline(s,name,',');
                getline(s,pwd,',');
                getline(s,accessLevel,',');
                if(userid==id)
                {
                    string hashedPassword=HashPassword(password);
                    if(hashedPassword==pwd)
                        return accessLevel;
                    else 
                        return "Incorrect Password";
                }
            }
            file.close();
        }
        else
        {
            cout<<"File opening failed\n";
        }
        return "User Not Found";
    }
};
class Signup
{
    public:
    void signUp(string &userid,string &username,string &password,string &accessLevel)
    {
        password=HashPassword(password);
        ofstream file("../data/login.csv",ios::app);
        if(file.is_open())
        {
            file<<userid<<','<<username<<','<<password<<','<<accessLevel<<'\n';
            file.close();
        }
        else
        {
            cout<<"File opening failed\n";
        }
    }
};