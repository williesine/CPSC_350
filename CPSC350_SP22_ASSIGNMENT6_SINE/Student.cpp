#include "Student.hpp"

// default - extends person object, sets attributes to default values
Student::Student() : Person(){
  m_major = "";
  m_GPA = 0.0;
  m_advisor = -1;
}

// overloaded - extends person object, sets attributes to paramter values
Student::Student(int id, string name, string major, double gpa, int advisor) : Person(name, id){
  m_major = major;
  m_GPA = gpa;
  m_advisor = advisor;
}

Student::~Student(){}

// accessor for major
string Student::getMajor(){
  return m_major;
}

// accessor for the GPA
double Student::getGPA(){
  return m_GPA;
}

//accessor for advisor
int Student::getAdvisor(){
  return m_advisor;
}

// mutator for major
void Student::setMajor(string m){
  m_major = m;
}

// mutator for GPA
void Student::setGPA(double g){
  m_GPA = g;
}

// mutator for advisor
void Student::setAdvisor(int a){
  m_advisor = a;
}

// returns a formatted string representing the Student object
string Student::getString(){
    string str = "";
    str += to_string(getID());
    str += "\n" + getName();
    str += "\n" + m_major;
    str += "\n" + to_string(m_GPA);
    str += "\n" + to_string(m_advisor) + "\n";
    return str;

}
