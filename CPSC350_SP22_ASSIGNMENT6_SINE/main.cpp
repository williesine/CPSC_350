#include <iostream>
#include <fstream>
#include "BST.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "Tables.hpp"
using namespace std;

// displays database operation options to user
void printMenu(){

    cout << "Enter '1' to print all students information (in ascending order of ID)" << endl;
    cout << "Enter '2' to print all faculty information (in ascending order of ID)" << endl;
    cout << "Enter '3' to find student information given ID number" << endl;
    cout << "Enter '4' to find faculty information given ID number" << endl;
    cout << "Enter '5' to find advisor given a student's ID" << endl;
    cout << "Enter '6' to find all students given a faculty's ID" << endl;
    cout << "Enter '7' to enter a new student in the database" << endl;
    cout << "Enter '8' to delete a student given the ID" << endl;
    cout << "Enter '9' to add a new faculty member" << endl;
    cout << "Enter '10' to delete a faculty member given their id" << endl;
    cout << "Enter '11' to change a student's advisor given the student ID and new Faculty ID" << endl;
    cout << "Enter '12' to remove an advisor from a faculty member given the IDS" << endl;
    cout << "Enter '13' to rollback the last 5 commands that changed the DB" << endl;
    cout << "Enter '14' to save and exit" << endl;

    cout << "\nWhat would you like to do: ";
}

// main is the interface for the user to interact with
// each case in the switch statement represents and handles the logic of calling the necessary functions to manipulate DB
int main(int argc, char **argv){
    Tables records = Tables();
    srand(time(NULL));
    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
            case 1:
            {
                //student print
                bool nothingPrinted = records.printStudents();
                //use inorder to print, will sort it  in ascending order
                if(nothingPrinted){
                    cout << "Student Tree is empty" << endl;
                }

                break;
            }
            case 2:
            {
                //faculty print
                bool nothingPrinted = records.printFaculty();
                //use inorder to print, will sort it  in ascending order
                if(nothingPrinted){
                    cout << "Faculty Tree is empty" << endl;
                }
                break;
            }
            case 3:
            {
                cout << "Please enter a student id to look up: ";
                int id;
                cin >> id;

                records.findAndDisplayStudent(id);

                break;
            }
            case 4:
            {
                cout << "Please enter a faculty id to look up: ";
                int id;
                cin >> id;

                records.findAndDisplayFaculty(id);

                break;
            }
            case 5:
            {
                cout << "Please enter a student id to view their advisor info: ";
                int id;
                cin >> id;

                records.showStudentAdvisor(id);

                break;
            }
            case 6:
            {
                cout << "Please enter a faculty id to view their advisee list: ";
                int id;
                cin >> id;

                records.printAllAdvisees(id);


                break;
            }
            case 7:
            {
                records.addStudent();
                break;
            }
            case 8:
            {
                cout << "Please enter a student id to delete: ";
                int id;
                cin >> id;
                records.deleteStudent(id);
                break;
            }
            case 9:
            {
                records.addFaculty();
                break;
            }
            case 10:
            {
                cout << "Please enter a faculty id to delete: ";
                int id;
                cin >> id;

                records.deleteFaculty(id);

                break;
            }
            case 11:
            {
                cout << "Please enter a student id to update: ";
                int id;
                cin >> id;

                cout << "Please enter the id of the new faculty advisor: ";
                int facId;
                cin >> facId;

                records.changeAdvisor(id, facId);

                break;
            }
            case 12:
            {
                cout << "Please enter a student id to remove: ";
                int id;
                cin >> id;

                cout << "Please enter the id of the old advisor: ";
                int facId;
                cin >> facId;

                records.removeAdvisee(id, facId);

                break;
            }
            case 13:
            {
                records.rollback();

                break;
            }
            case 14:
            {
                records.saveToFiles();
                break;
            }
            default:
            {
                //this catches anything not 1-14 prints error if invalid choice
                cout << "Error! Invalid menu choice. Must be 1-14 (inclusive). Please try again." << endl;
                //TODO print error invalid choice msg
                break;
            }
        }




    } while (choice != 14);


    return 0;
}
