#include "Person.hpp"

// default - sets name and ID to default values
Person::Person(){
  m_name = "";
  m_ID = -1;
}

// overloaded - sets name and ID to params
Person::Person(string n, int id){
  m_name = n;
  m_ID = id;
}

// accessor for ID
int Person::getID(){
  return m_ID;
}

// accessor for name
string Person::getName(){
  return m_name;
}

// mutator for ID
void Person::setID(int id){
  m_ID = id;
}

// mutator for name
void Person::setName(string n){
  m_name = n;
}

// person is the same if they hace the same id
bool Person::operator==(const Person& rhs){
    if(m_ID == rhs.m_ID){
        return true;
    }
    return false;
}

// custom operator for person based on id
bool Person::operator<(const Person& rhs){
    if(m_ID < rhs.m_ID){
        return true;
    }
    return false;
}

// custom operator for person based on id
bool Person::operator>(const Person& rhs){
    if(m_ID > rhs.m_ID){
        return true;
    }
    return false;
}

// custom operator for person based on id
bool Person::operator<=(const Person& rhs){
    if(m_ID <= rhs.m_ID){
        return true;
    }
    return false;
}

// custom operator for person based on id
bool Person::operator>=(const Person& rhs){
    if(m_ID >= rhs.m_ID){
        return true;
    }
    return false;
}
