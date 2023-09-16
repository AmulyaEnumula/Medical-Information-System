#include "user.hpp"
#include<iostream>

class Patient: public User {
    public:
        void whoAmI()
        {
            std::cout<<"i Am Patient";
        }
        
};