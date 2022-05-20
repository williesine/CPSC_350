#ifndef TABLES_HPP
#define TABLES_HPP

#include "BST.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "RollbackItem.hpp"

class Tables{
public:
    Tables();//default
    //Tables(BST<Student*>* stu, BST<Faculty*>* fac);//overloaded

    //all their info, sorted by ascending ID #
    bool printStudents();

    //all their info, sorted by ascending ID #
    bool printFaculty();

    // handles the reading and writing to files for the student and faculty tables
    void readStudentFile(ifstream &input);
    void readFacultyFile(ifstream &input);
    void readFiles();
    void saveToFiles();

    // main functions of the database
    void findAndDisplayStudent(int stuId);
    void findAndDisplayFaculty(int facId);
    void showStudentAdvisor(int stuId);
    void printAllAdvisees(int facId);
    void addStudent();
    void addFaculty();
    void deleteFaculty(int facId); //make sure to save their id, and then traverse WHOLE student tree (use traversal to vect fn to make vecor so easier) and any student with professor id, remove that id and give them new advisor randomly
    void deleteStudent(int stuId);
    void changeAdvisor(int stuId, int newFacId);
    void removeAdvisee(int stuId, int facId);
    void rollback();


    //helperFns
    Student* findStudent(int stuId);
    Faculty* findFaculty(int facId);

private:
    // Student Tree
    BST<Student*>* masterStudent;

    // Faculty Tree
    BST<Faculty*>* masterFaculty;

    const string studentFilePath = "student.txt";
    const string facultyFilePath = "fac.txt";

    vector<RollbackItem> rollbackData;
};



#endif
