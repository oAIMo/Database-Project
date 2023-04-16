#include "contact.h"

Email::Email(string type, string email_addr){
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    cout << "Enter the type of email address: ";
    cin >> this->type;
    cout << "Enter email address: ";
    cin >> this->email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
        return "(" + type + "): " + email_addr;
    else
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
    cout << get_contact("full") << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    this->type = type;
    if(num.length() != 12)
    {
        num = num.substr(0, 3) + "-" + num.substr(3, 3) + "-" + num.substr(6, 4);
    }
    this->phone_num = num;

}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
    cout <<"Enter the type of phone number: ";
    cin >> this->type;
    cout << "Enter the phone number: ";
    cin >> this->phone_num;
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email
    if (style=="full")
        return "(" + type + "): " + phone_num;
    else
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
    cout << get_contact("full") << endl;
}

