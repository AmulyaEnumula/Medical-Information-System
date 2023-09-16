#include "user.hpp"
#include<iostream>

class Doctor: public User {
    public:
        void whoAmI()
        {
            std::cout<<"i Am Doctor";
        }
};