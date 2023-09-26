#include "../headers/User.hpp"
#include "../headers/Menu.hpp"
#include<iostream>
using std::string;
using std::cout;

class Admin: public User
{
    public:
        void home(string &);
};

void Admin::home(string &userid)
{
    cout<<"\t\t*** Welcome "<<userid<<" ***"<<std::endl;
    admin_Menu();
}