#include<iostream>
#include "../headers/factory/factory.hpp"
#include "../headers/factory/user.hpp"
int main()
{
    User *ptr =  userType("ADMINISTRATOR");
    ptr->whoAmI();
    return 0;
}