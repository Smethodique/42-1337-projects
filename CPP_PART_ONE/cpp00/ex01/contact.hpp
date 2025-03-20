#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <limits>
#include <sstream>  
#include <cstdio>
#include <cstring>



    class contact
    {
        private:
            std::string first_name ;
            std::string last_name;
            std::string nickname;
            std::string darkest;
            std::string phone_number;

        public :
        int  add_f(std::string first_name);
        int  add_l(std::string last_name);
        int  add_n(std::string nickname);
        int  add_p(std::string phone_number);
        int  add_d(std::string darkest);

        std::string g_add_f();
        std::string g_add_l();
        std::string g_add_n();
        std::string g_add_p();
        std::string g_add_d();
        int isprintable(std::string str);

    };
#endif