#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using namespace std;

class Person{
public:
    //default
    Person();

    //overloaded
    Person(string n, int Id);

    // accessor for ID attribute
    int getID();

    // accessor for name attribute
    string getName();

    // mutator for ID attribute
    void setID(int id);

    // mutator for name attribute
    void setName(string n);

    //custom overloaded operators to compare Person Objects
    bool operator==(const Person& rhs);
    bool operator<(const Person& rhs);
    bool operator>(const Person& rhs);
    bool operator<=(const Person& rhs);
    bool operator>=(const Person& rhs);
private:

    // Attributes: name and ID number
    string m_name;
    int m_ID;


};




#endif
