
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){
    Person* current = head;
    while(current != NULL)
    {
        Person* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* current = head;
    while(current != NULL){
        if(*current == *searchEntry)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly.
    Person* current = head;
    while(current != NULL){
        if(current->f_name == fname && current->l_name == lname)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


void Network::search(string lname){
    // New == for Person, only based on lname
    // if found prints all Person's that have lname
    // TODO: Complete this method
    
    Person* current = head;
    while(current != NULL){
        if(current->l_name == lname)
        {
            current->print_person();
        }
        current = current->next;
    }
    
}



void Network::loadDB(string filename){
    
    // TODO: Complete this method
    ifstream filerhandler(filename);
    if (!filerhandler) {
        cout << "Error opening file " << filename << endl;
    }
    string fname;
    string lname;
    string date;
    string email;
    string phone;
    while (!filerhandler.eof())
    {
        getline(filerhandler, fname);
        getline(filerhandler, lname);
        getline(filerhandler, date);
        getline(filerhandler, email);
        getline(filerhandler, phone);
        push_back(new Person(fname,lname,date,email,phone));
        getline(filerhandler, phone);
    }
    filerhandler.close();
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    ofstream filehandler(filename, ios_base::out);
    Person* current = head;
    while(current != NULL){
        filehandler << (current->write_person());
        filehandler << "\n------------------------------\n";
        current = current->next;
    }
    filehandler.close();
}


void Network::printDB(){
    // Leave me alone! I know how to print!
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    newEntry->prev = tail;
    newEntry->next = NULL;
    
    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;
    
    tail = newEntry;
    count++;
    
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    Person* temp = search(fname, lname);
    if(temp == NULL)
        return false;
    else
    {
        if(temp->prev == NULL && temp->next == NULL) // only node
        {
            //cout << "1" << endl;
            delete temp;
            head = NULL;
            count--;
        }
        else if(temp->prev == NULL) // head node
        {
            //cout << "2" << endl;
            temp->next->prev = NULL;
            head = temp->next;
            delete temp;
            count--;
        }
        else if(temp->next == NULL) // tail node
        {
            //cout << "3" << endl;
            temp->prev->next = NULL;
            tail = temp->prev;
            delete temp;
            count--;
        }
        else // middle node
        {
            //cout << "4" << endl;
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            count--;
        }
        return true;
    }
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you,
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "6. Connect \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            saveDB(fileName);
            // Save the network database into the file with the given name,
            // with each person saved in the format the save as printing out the person info,
            // and people are delimited similar to "networkDB.txt" format
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            cout << "networkDB.txt" << endl;
            // This step just shows all the available .txt file to load.
            cout << "Enter the name of the load file: ";
            cin >> fileName;
            ifstream filerhandler(fileName);
            if (!filerhandler)
            {
                cout << "File " << fileName <<  " does not exist!" << endl;
            }
            else
            {
                Person* current = head;
                while(current != NULL)
                {
                    Person* next = current->next;
                    delete current;
                    current = next;
                }
                head = NULL;
                tail = NULL;
                count = 0;
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
            // If file with name FILENAME does not exist:
            // If file is loaded successfully, also print the count of people in it:
            filerhandler.close();
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            Person* a = new Person();
            if(search(a) == NULL)
            {
                push_front(a);
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            getline(cin,fname);
            cout << "Last name: ";
            getline(cin,lname);
            if(remove(fname,lname) == true)
                cout << "Remove Successful! \n";
            else
                cout << "Person not found! \n";
            
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            getline(cin,lname);
            search(lname);
            
        }
        else if (opt==6){
            Person* temp;
            cout << "Make friends:" << endl;
            cout << "Person 1" << endl;
            cout << "First Name: ";
            getline(cin, fname);
            cout << "Last Name: ";
            getline(cin, lname);
            if(search(fname,lname) == NULL)
               cout << "\nPerson not found \n" << endl;
            else
            {
                temp = search(fname, lname);
                cout << "Person 2" << endl;
                cout << "First Name: ";
                getline(cin, fname);
                cout << "Last Name: ";
                getline(cin, lname);
                if(search(fname,lname) == NULL)
                   cout << "Person not found \n" << endl;
                else
                {
                    temp->makeFriend(search(fname,lname)); // temp is first person
                    search(fname,lname)->makeFriend(temp); // search(fname,lname) is second person
                    cout << "\n\n";
                    temp->print_person();
                    cout << endl << endl;
                    search(fname, lname)->print_person();
                }
                   
            }
               
        }
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
