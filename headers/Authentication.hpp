#include<fstream>
#include<sstream>
#include<iostream>
using std::string;
using std::cout;

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
    string authenticate(string &username,string &password)
    {
        ifstream file("../data/login.csv");
        if(file.is_open())
        {
            string line;
            while(getline(file,line))
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
    void signUp(string &username,string &password,string &accessLevel)
    {
        password=HashPassword(password);
        ofstream file("../data/login.csv",ios::app);
        if(file.is_open())
        {
            file<<username<<','<<password<<','<<accessLevel<<'\n';
            file.close();
        }
        else
        {
            cout<<"File opening failed\n";
        }
    }
};