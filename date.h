#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
private:
	string date;
public:
	Date(string date);
	string updateFormat(string date);
	void set_date();
    string get_date();
	void print_date();
    bool operator==(const Date& rhs);
    bool operator!=(const Date& rhs);
};

#endif


