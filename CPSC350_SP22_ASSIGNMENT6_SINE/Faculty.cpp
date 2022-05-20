#include "Faculty.hpp"

// Creates a new Faculty Object, instantiates attributes to default values
Faculty::Faculty() : Person(){
  m_level = "";
  m_department = "";
    m_adviseeList = NULL;
}

// overloaded sets faculty member attributes equal to the parameters
Faculty::Faculty(int Id, string n, string l, string d, GenList<int>* list) : Person(n, Id){

  m_level = l;
  m_department = d;
  m_adviseeList = list;
}

// overloaded sets faculty object attributes equal to parameters
Faculty::Faculty(int Id, string n, string l, string d) : Person(n, Id){

  m_level = l;
  m_department = d;
    m_adviseeList = new GenList<int>();
}

// accessor for level attribute
string Faculty::getLevel(){
  return m_level;
}

// accessor for department attribute
string Faculty::getDepartment(){
  return m_department;
}

// accessor for the the advisee list
GenList<int>* Faculty::getAdviseeList(){
  return m_adviseeList;
}

// mutator for the level attribute
void Faculty::setLevel(string l){
  m_level = l;
}

// mutator for the level attributes
void Faculty::setDepartment(string d){
  m_department = d;
}

// mutator for the advisee list
void Faculty::setAdviseeList(GenList<int>* list){
  m_adviseeList = list;
}

// returns a string representing all attributes of the faculty object in a formatted manner
string Faculty::getString(){
    string str = "";
    str += to_string(getID());
    str += "\n" + getName();
    str += "\n" + m_level;
    str += "\n" + m_department;
    str += "\n" + m_adviseeList->toFileString() + "\n";
    return str;
}

// appends an student to the faculty's advisee list
void Faculty::addAdvisee(int stuId){
    m_adviseeList->append(stuId);
}
