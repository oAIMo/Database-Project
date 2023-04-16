#include "contact.h"
#include "date.h"

int main()
{
    cout << "hello" << endl;
    
    Email e("work", "armandoi@usc.edu");
    e.print();
    e.set_contact();
    cout << e.get_contact("full")<<endl;

    Phone p("work", "2813232051");
    p.print();
    p.set_contact();
    cout << p.get_contact("full")<<endl;
    
    Date da("1/13/1961");
    da.print_date();
    da.set_date();
    da.print_date();
    
    return 0;
}
