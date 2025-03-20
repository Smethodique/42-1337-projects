
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define MAX_CONTACTS 8

#include "contact.hpp"


class Phonebook
{
    private:
        contact contacts[MAX_CONTACTS];
        int  index;

    public:
    Phonebook();
     int     add_contact();
     void    search_contact();
     int     display_contact(int contact_num);
     void    display_all_contacts();
};

#endif

