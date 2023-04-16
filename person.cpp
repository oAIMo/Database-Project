#include "person.h"
#include <regex>

Person::Person(){
    // I'm already done!
    set_person();
}


Person::~Person(){
    delete birthdate;
    delete email;
    delete phone;
    // TODO: complete the method!
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name = f_name;
    this->l_name = l_name;
    birthdate = new Date(b_date);
    
    // took inspiration to use regex from www.geeksforgeeks.org/smatch-regex-regular-expressions-in-c/
    string label;
    regex pattern1("\\(([^)]+)\\)\\s*([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,})");
    smatch match1;
    if (regex_search(email, match1, pattern1)) {
        label = match1[1].str();
        string newEmail = match1[2].str();
        this->email = new Email(label, newEmail);
    }
    regex pattern2("\\(([^)]+)\\)\\s*([0-9\\-]+)");
    smatch match2;
    if (regex_search(phone, match2, pattern2)) {
        label = match2[1].str();
        string phoneNumber = match2[2].str();
        this->phone = new Phone(label, phoneNumber);
    }
    
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

    cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp);

    cout << "Type of email address: ";
    cin >> type;
    cout << "Email address: ";
    cin >> temp;
    email = new Email(type, temp);
    cout << "Type of phone number: ";
    cin >> type;
    cout << "Phone number: ";
    cin >> temp;
    phone = new Phone(type, temp);
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.
    // Phone number in files can have '-' or not.
    string str;
    ifstream readfile(filename);
    getline(readfile,str);
    f_name = str;
    getline(readfile,str);
    l_name = str;
    getline(readfile,str);
    birthdate = new Date(str);
    getline(readfile,str);
    string label;
    regex pattern2("\\(([^)]+)\\)\\s*([0-9\\-]+)");
    smatch match2;
    if (regex_search(str, match2, pattern2)) {
        label = match2[1].str();
        string phoneNumber = match2[2].str();
        this->phone = new Phone(label, phoneNumber);
    }
    getline(readfile,str);
    regex pattern1("\\(([^)]+)\\)\\s*([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,})");
    smatch match1;
    if (regex_search(str, match1, pattern1)) {
        label = match1[1].str();
        string newEmail = match1[2].str();
        this->email = new Email(label, newEmail);
    }
        
}


bool Person::operator==(const Person& rhs){
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    
    if(this->f_name == rhs.f_name && this->l_name == rhs.l_name && *(this->birthdate) == *(rhs.birthdate)) //&& phone->get_contact("") == rhs.phone->get_contact("") && email->get_contact("") == rhs.email->get_contact("")
    {
        return true;
    }
    else
        return false;
}

bool Person::operator!=(const Person& rhs){
    if(this->f_name != rhs.f_name || this->l_name != rhs.l_name || *(this->birthdate) != *(rhs.birthdate))
    {
        return true;
    }
    else
        return false;
}


void Person::print_person(){
    // Already implemented for you! Do not change!
    cout << l_name <<", " << f_name << endl;
    birthdate->print_date();
    cout << "Phone "; phone->print();
    cout << "Email "; email->print();
    
    vector<Person*>::iterator it;
    for (it = friends.begin(); it != friends.end(); it++) {
        cout << concatenateUniqueID((*it)->f_name, (*it)->l_name) << endl;
    }
    
}

string Person::write_person(){
    string big;
    big = l_name + ", " + f_name + "\n" + birthdate->get_date() + "\nPhone " + phone->get_contact("full") + "\nEmail " + email->get_contact("full");
    
    vector<Person*>::iterator it;
    for (it = friends.begin(); it != friends.end(); it++) {
        big = big + "\n" + concatenateUniqueID((*it)->f_name, (*it)->l_name);
    }
    return big;
}

void Person::makeFriend(Person* newFriend){
    friends.push_back(newFriend);
    
}
