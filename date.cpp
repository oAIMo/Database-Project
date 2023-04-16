#include "date.h"
#include <sstream>

Date::Date(string date){
    this->date = updateFormat(date);
    
}

string Date::updateFormat(string date){
    string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    stringstream ss(date);
    int month, day, year;
    char delimiter;
    ss >> month >> delimiter >> day >> delimiter >> year;

    string formattedDate = monthNames[month - 1] + " " + to_string(day) + ", " + to_string(year);
    return formattedDate;
    
}
void Date::set_date(){
    string temp;
    cout << "Enter date ";
    cin >> temp;
    this->date = updateFormat(temp);
}
string Date::get_date(){
    return this->date;
}
void Date::print_date(){
    cout << this->date << endl;
}
bool Date::operator==(const Date& rhs) {
    if(this->date == rhs.date)
        return true;
    else
        return false;
}
bool Date::operator!=(const Date& rhs) {
    if(this->date != rhs.date)
        return true;
    else
        return false;
}
