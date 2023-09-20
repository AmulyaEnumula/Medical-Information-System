#include "../headers/User.hpp"
#include<iostream>
using std::string;
using std::cout;

class Doctor: public User
{
    public:
        void home(string &);
};

void Doctor::home(string &username)
{
    cout<<"\t\t*** Welcome "<<username<<" ***"<<std::endl;
}