#include<iostream>
#include "../headers/Factory.hpp"
int main()
{
    User *ptr =  userType("ADMINISTRATOR");
    string name="admin";
    ptr->home(name);
    return 0;
}