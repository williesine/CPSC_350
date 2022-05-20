#ifndef FACULTY_HPP
#define FACULTY_HPP

#include <string>
#include "Person.hpp"
#include "GenList.hpp"
using namespace std;

/*
 Faculty records are similar to student
 records and will also require overloaded operators.
 */
class Faculty: public Person{
private:
    string m_level; //string - prof level
    string m_department; // string - department
    GenList<int>* m_adviseeList; //list of integers corresponding to which students they advise

public:

    //default
    Faculty();

    //overloaded for faculty with advisee list
    Faculty(int id, string n, string l, string d, GenList<int>* list);

    //overloaded
    Faculty(int id, string n, string l, string d);

    //destructor
    ~Faculty();

    //accessors
    string getLevel();
    string getDepartment();
    GenList<int>* getAdviseeList();

    //mutators
    void setID(int id);
    void setName(string n);
    void setLevel(string l);
    void setDepartment(string d);
    void setAdviseeList(GenList<int>* list);
    void addAdvisee(int stuId);

    string getString();

};


#endif
