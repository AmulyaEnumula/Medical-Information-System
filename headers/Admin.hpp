#include "../headers/User.hpp"
#include<iostream>
using std::string;
using std::cout;

class Admin: public User
{
    public:
        void home(string &);
};

void Admin::home(string &username)
{
    cout<<"\t\t*** Welcome "<<username<<" ***"<<std::endl;
}