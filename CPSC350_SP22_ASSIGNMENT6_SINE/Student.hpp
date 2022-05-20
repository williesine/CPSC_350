#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Person.hpp"
using namespace std;
/*
 The Student class must overload equality,
 less than, greater than operators, etc. so that we
 can compare them to one another.
 */

class Student: public Person{
public:
    //default
    Student();

    //overloaded
    Student(int Id,string name, string major, double gpa, int advisor);

    //destructor
    ~Student();

    //accessors
    string getMajor();
    double getGPA();
    int getAdvisor();

    //mutators
    void setID(int id);
    void setName(string n);
    void setMajor(string m);
    void setGPA(double g);
    void setAdvisor(int a);

    string getString();

private:

    string m_major; //string - major
    double m_GPA; // double - GPA
    int m_advisor; // int representing advisor ID
};



#endif
