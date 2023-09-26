#include "../headers/User.hpp"
#include "../headers/Menu.hpp"
#include<iostream>
using std::string;
using std::cout;

class Doctor: public User
{
    public:
        void home(string &);
};

void Doctor::home(string &userid)
{
    cout<<"\t\t*** Welcome "<<userid<<" ***"<<std::endl;
    doctor_Menu();
}