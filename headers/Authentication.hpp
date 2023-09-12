#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;
char _getch()
{
    char c;
    std::cin>>c;
    return c;
}
class Login
{
    public:
    fstream loginFile;
    
    string HashPassword(string &password)
    {

        return password;
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
                    string hashedPassword= password ; //HashPassword(password);
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