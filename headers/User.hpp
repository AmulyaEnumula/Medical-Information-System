#ifndef USER_HPP
   #define USER_HPP

class User
{
   public:
        virtual void home(std::string &username)=0;
        virtual ~User(){}
};

#endif