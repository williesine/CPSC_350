// Responsible for the implementation of the class
#include "HelloWorld.h"
#include <iostream>
using namespace std;

// default constructor
HelloWorld::HelloWorld(){
  cout << "Default Construct called" << endl;
}

// output method
void HelloWorld::printHelloWorld(){
  cout << "Hello World!" << endl;
}

// destructor
HelloWorld::~HelloWorld(){
  cout << "Deconstructor called" << endl;
}
