
#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "misc.h"
#include "fstream"
#include <iostream>
#include <vector>

class Person{
    friend class Network;

private:
    string f_name;
    string l_name;
    Date *birthdate;
    Email *email;
    Phone *phone;
    vector<Person*> friends;
    // the following to attributes are used in the linked list.
    Person* next;
    Person* prev;

public:
    Person();
    ~Person();
    Person(string filename);
    Person(string f_name, string l_name, string b_date, string email, string phone);
    void print_person();
    string write_person();
    void makeFriend(Person* newFriend);
    void set_person();
    void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
};


#endif
