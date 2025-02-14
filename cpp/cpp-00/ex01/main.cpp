#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

string check_ten_char(string s)
{
    string space;
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    else {
        
        
        return string(10 - s.length(), " ") + s.substr(0, s.length());
    }
}

void add_contact_prompt(PhoneBook *phone_book)
{
    Contact new_contact;

    string input;
    cout << "enter first name" << endl;
    getline(cin, input);
    new_contact.set_first_name(input);
    
    cout << "enter last name" << endl;
    getline(cin, input);
    new_contact.set_last_name(input);

    cout << "enter nick name" << endl;
    getline(cin, input);
    new_contact.set_nick_name(input);

    cout << "enter phone number" << endl;
    getline(cin, input);
    new_contact.set_phone_number(input);

    cout << "enter darkest secret" << endl;
    getline(cin, input);
    new_contact.set_darkest_secret(input);

    (*phone_book).add(new_contact);
    cout << "successfully added contact to phone book" << endl;
}

void search_contact_prompt(PhoneBook *phone_book)
{
    Contact* contacts = (*phone_book).get();
    cout << "index | first name | last name | nickname" << endl;
    for (int i = 0; i < (*phone_book).get_contact_index(); i++)
    {
        printf("%d |", contacts[i].get_index());
        cout << check_ten_char(contacts[i].get_first_name()) + "|";
        cout << check_ten_char(contacts[i].get_last_name()) + "|";
        cout << check_ten_char(contacts[i].get_nick_name()) << endl;
    }
}

void enter_prompt()
{
    PhoneBook phone_book;
    string command;

    while (!cin.eof())
    {
        cout << "enter command like 'ADD', 'SEARCH', 'EXIT'" << endl;
        getline(cin, command);

        if (command == "ADD")
            add_contact_prompt(&phone_book);
        else if (command == "SEARCH")
            search_contact_prompt(&phone_book);
        else if (command == "EXIT")
            break;
        else
            continue;
    }
}

int main()
{
    enter_prompt();
    return (0);
}



