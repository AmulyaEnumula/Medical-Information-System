#ifndef USER_HPP
   #define USER_HPP

class User
{
   public:
        virtual void home(std::string &userid)=0;
        virtual ~User(){}
};

#endif