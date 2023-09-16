#include "user.hpp"
#include<iostream>

class Admin: public User {
    public:
        void whoAmI()
        {
            std::cout<<"i Am Admin";
        }
};