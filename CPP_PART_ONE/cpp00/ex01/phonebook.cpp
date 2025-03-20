#include "phoneBook.hpp"

Phonebook::Phonebook()
{
    index = 0;
}


int contact::isprintable(std::string str)
{
    for (std::string::size_type i = 0; i < str.length(); i++)
    {
        if (!isprint(str[i]))
        {
            return 0;
        }
    }
    return 1;
}



int contact::add_f(std::string first_name)
{
    if(first_name.empty() || !isprintable(first_name))
    {
        std::cout << "First name cannot be empty! or contain non printable characters" << std::endl;
        return 0;
    }
    this->first_name = first_name;
    return 1;
}

int contact::add_l(std::string last_name)
{
    this->last_name = last_name;
    if(last_name.empty() || !isprintable(last_name))
    {
        std::cout << "Last name cannot be empty! or contain non printable characters" << std::endl;
        return 0;
    }

    return 1;
}

int contact::add_n(std::string nickname)
{
    this->nickname = nickname;
    if(nickname.empty() || !isprintable(nickname))
    {
        std::cout << "Nickname cannot be empty! or contain non printable characters" << std::endl;
        return 0;
    }
    return 1;
}

int contact::add_p(std::string phone_number)
{
    this->phone_number = phone_number;
    if(phone_number.empty() || !isprintable(phone_number))
    {
        std::cout << "Phone number cannot be empty! or contain non printable characters" << std::endl;
        return 0;
    }
    if(phone_number.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Phone number can only contain digits!" << std::endl;
        return 0;
    }
    return 1;
}

int contact::add_d(std::string darkest)
{
    this->darkest = darkest;
    if(darkest.empty()  || !isprintable(darkest))
    {
        std::cout << "Darkest secret cannot be empty! or contain non printable characters" << std::endl;
        return 0;
    }
    return 1;
}

std::string contact::g_add_f()
{
     return first_name;
}

std::string contact::g_add_l()
{
     return last_name;
}

std::string contact::g_add_n()
{
     return nickname;
}

std::string contact::g_add_p()
{
     return phone_number;
}

std::string contact::g_add_d()
{
     return darkest;
}

int Phonebook::add_contact()
{ 
     std::string first_name, last_name, nickname, darkest , phone_number;


    int contact_index = index % MAX_CONTACTS;
    if(index > MAX_CONTACTS)
    {
        contact_index = index % MAX_CONTACTS; ;
        if(contact_index == 0)
        {
            contact_index = MAX_CONTACTS;
        }
    }
    int all_inputs = 0 ;

  while(all_inputs < 5)
  {
        if( all_inputs == 0)
        {
            std::cout << "Enter first name: \n";
            if (!std::getline(std::cin, first_name))
            {
                std::cout << "Exiting phonebook.\n";
                return 0;
            }
            if(!(contacts[contact_index].add_f(first_name)))
                {
                    continue;
                }
            all_inputs++;
        }

        if( all_inputs == 1)
        {
            std::cout << "Enter last name: \n";
            if (!std::getline(std::cin, last_name))
            {
                std::cout << "Exiting phonebook.\n";
                return 0;
            }
                if(!(contacts[contact_index].add_l(last_name)))
                {
                    continue;
                }
            all_inputs++;
        }

        if( all_inputs == 2)
        {
            std::cout << "Enter nickname: \n";
            if (!std::getline(std::cin, nickname) )
            {
                std::cout << "Exiting phonebook.\n";
                return 0;
            }
                if(!(contacts[contact_index].add_n(nickname)))
                {
                    continue;
                }
            all_inputs++;
        }

        if( all_inputs == 3)
        {
            std::cout << "Enter phone number: \n";
            if (!std::getline(std::cin, phone_number))
            {
                std::cout << "Exiting phonebook.\n";
                return 0;
            }
            if(!(contacts[contact_index].add_p(phone_number)))
                {
                    continue;
                }
            all_inputs++;
        }

        if( all_inputs == 4)    
        { 
            std::cout << "Enter darkest secret: \n";
            if (!std::getline(std::cin, darkest))
            {
                std::cout << "Exiting phonebook.\n";
                return 0;
            }
                    if(!(contacts[contact_index].add_d(darkest)))
                {
                    continue;
                }
            all_inputs++;
        }

    

        index++;  
  }        
    return index;

}

int Phonebook::display_contact(int contact_num)
{
    if (contact_num < 1 || contact_num > index || contact_num == 0 || contact_num > MAX_CONTACTS)
    {
        std::cout << "Invalid contact number!" << std::endl;
        return 0;
    }
    std::cout << "Contact number: " << contact_num << std::endl;
    std::cout << "First Name: " << contacts[contact_num - 1].g_add_f() << std::endl;
    std::cout << "Last Name: " << contacts[contact_num - 1].g_add_l() << std::endl;
    std::cout << "Nickname: " << contacts[contact_num - 1].g_add_n() << std::endl;
    std::cout << "Phone Number: " << contacts[contact_num - 1].g_add_p() << std::endl;
    std::cout << "Darkest Secret: " << contacts[contact_num - 1].g_add_d() << std::endl;
    return 1;
}
#include <iomanip>
void Phonebook::display_all_contacts()
{
    if (index == 0)
    {
        std::cout << "\033[1;31mPhonebook is empty!\033[0m" << std::endl;
        return;
    }
    
    std::cout << "\033[1;36m+----------+----------+----------+----------+\033[0m" << std::endl;
    std::cout << "\033[1;36m|\033[1;33m     Index\033[1;36m|\033[1;33mFirst Name\033[1;36m|\033[1;33m Last Name\033[1;36m|\033[1;33m  Nickname\033[1;36m|\033[0m" << std::endl;
    std::cout << "\033[1;36m+----------+----------+----------+----------+\033[0m" << std::endl;
    
    int displayCount;
    if (index > MAX_CONTACTS) {
        displayCount = MAX_CONTACTS;
    } else {
        displayCount = index;
    }
    
    for (int i = 0; i < displayCount; i++)
    {
        std::string first = contacts[i].g_add_f();
        std::string last = contacts[i].g_add_l();
        std::string nick = contacts[i].g_add_n();
        
        if (first.length() > 10) first = first.substr(0, 9) + ".";
        if (last.length() > 10) last = last.substr(0, 9) + ".";
        if (nick.length() > 10) nick = nick.substr(0, 9) + ".";
        
        std::string rowColor;
        if (i % 2 == 0) {
            rowColor = "\033[1;37m";
        } else {
            rowColor = "\033[1;34m";
        }
        
        std::cout << "\033[1;36m|\033[0m" << rowColor << std::setw(10) << i + 1;
        std::cout << "\033[1;36m|\033[0m" << rowColor << std::setw(10) << first;
        std::cout << "\033[1;36m|\033[0m" << rowColor << std::setw(10) << last;
        std::cout << "\033[1;36m|\033[0m" << rowColor << std::setw(10) << nick << "\033[1;36m|\033[0m" << std::endl;
    }
    std::cout << "\033[1;36m+----------+----------+----------+----------+\033[0m" << std::endl;
}

void Phonebook::search_contact()
{
    // std::cout << "ssss" << std::endl;
    if (index == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    
    display_all_contacts();
    std::string input;
    int searchfor;

    
    std::cout << "Enter contact number: ";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    
    
    if (!(iss >> searchfor) || iss.rdbuf()->in_avail() > 0|| searchfor < 1 || searchfor > index || searchfor > MAX_CONTACTS)
    {
        std::cout << "Invalid contact number!" << std::endl;
        return;
    }
    
    display_contact(searchfor);
}





int main(int ac , char **av)
 {
    (void)av;
    if(ac == 1)
    {

        Phonebook phonebook;
        std::string input;

        while (true) {

            if(std::cin.eof())
            {
                return 0 ;
            }
            std::cout << "Phonebook Menu:\n";
            std::cout << "1. ADD\n";
            std::cout << "2. SEARCH\n";
            std::cout << "3. EXIT\n";
            std::cout << "Enter your choice: ";
            std::getline(std::cin, input);
            std::cout << input << "\n";
            if(std::cin.eof())
            {
                std::cout << "Exiting phonebook.\n";
                return 0;
            }
        
        if (strcmp(input.c_str(), "ADD") == 0) 
        {
            phonebook.add_contact();
        }
        else if (strcmp(input.c_str(), "SEARCH") == 0) 
        {
            phonebook.search_contact();
        }
        else if (strcmp(input.c_str(), "EXIT") == 0 )
        {
            std::cout << "Exiting phonebook.\n";
            return 0;
        }
            else
            {
                std::cout << "Invalid choice!\n";
            }
        
        }
    }
    else
        return 0;
}


