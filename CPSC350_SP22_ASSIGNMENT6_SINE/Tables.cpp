#include "Tables.hpp"
#include <fstream>

// default, instantiates a Student and Faculty table and reads both files
Tables::Tables(){
    masterFaculty = new BST<Faculty*>();
    masterStudent = new BST<Student*>();
    readFiles();
}

// reads the two, potentially, inputted files, representing student and faculty input
void Tables::readFiles(){
    ifstream studentInput;
    ifstream facultyInput;

    studentInput.open(studentFilePath);
    facultyInput.open(facultyFilePath);

    if(studentInput.is_open()){
        readStudentFile(studentInput);
    }
    else{
        cout << "No student file to read, starting with empty Student tree" << endl;
    }

    if(facultyInput.is_open()){
        readFacultyFile(facultyInput);
    }
    else{
        cout << "No faculty file to read, starting with empty Faculty tree" << endl;
    }
}

// parses the larger student file file into individual student objects and inserts them into the student table
void Tables::readStudentFile(ifstream &input){
    while (!input.eof()) {
        int id;
        input >>id;

        string name;
        input >>name;

        string major;
        input >> major;

        double gpa;
        input >> gpa;

        int advisor;
        input >> advisor;

        if(name.length() != 0){
            Student* stu = new Student(id, name, major, gpa, advisor);
            masterStudent->insert(stu);
        }

    }
}

// parses the larger faculty file into individual student objects and inserts them into the faculty table
void Tables::readFacultyFile(ifstream &input){
    while (!input.eof()) {
        int id;
        input >>id;

        string name;
        input >>name;

        string level;
        input >> level;

        string dept;
        input >> dept;

        int adviseeCount;
        input >> adviseeCount;

        GenList<int>* advisees = new GenList<int>();

        for(int i = 0; i < adviseeCount; i++){
            int advisee;
            input >> advisee;
            advisees->append(advisee);
        }

        if(name.length() != 0){
            Faculty* fac = new Faculty(id, name, level, dept, advisees);
            masterFaculty->insert(fac);
        }

    }
}

// saves the current version of the student and faculty database to file
void Tables::saveToFiles(){
    ofstream studentOut(studentFilePath);
    ofstream facultyOut(facultyFilePath);

    cout << boolalpha << "Faculty outfile open: " << facultyOut.is_open() << endl;
    cout << boolalpha << "Student outfile open: " << studentOut.is_open() << endl;

    //students
    vector<TreeNode<Student*>*> students;
    if(!masterStudent->isEmpty()){
        masterStudent->getPreOrderVector(masterStudent->getRoot(), students);

        for(int i = 0; i < students.size(); i++){
            string result = students[i]->key->getString();
            studentOut << result;
        }
    }


    //faculty
    vector<TreeNode<Faculty*>*> faculty;
    if(!masterFaculty->isEmpty()){
        masterFaculty->getPreOrderVector(masterFaculty->getRoot(), faculty);

        for(int i = 0; i < faculty.size(); i++){
            facultyOut << faculty[i]->key->getString();
        }
    }



//    masterStudent->treeToFile(studentOut);
//    masterFaculty->treeToFile(facultyOut);
}

// find student given ID number, return all his/her information
void Tables::findAndDisplayStudent(int stuId){
    Student* target = findStudent(stuId);

    if(target == nullptr){
        cout << "Student does not exist with id " << stuId << endl;
        return;
    }
    else{
        cout << target->getName() << ", "<< target->getID() << ", "<< target->getMajor() << ", "<< target->getGPA() << ", "<< target->getAdvisor() << endl;
    }
}

// find faculty given ID number, return all his/her information
void Tables::findAndDisplayFaculty(int facId){
    Faculty* target = findFaculty(facId);

    if(target == nullptr){
        cout << "Faculty member does not exist with id " << facId << endl;
        return;
    }
    else{
        cout << target->getName() << ", "<< target->getID() << ", "<< target->getLevel() << ", "<< target->getDepartment() << ", "<< target->getAdviseeList()->toFileString() << endl;
    }
}

// find student's advisor given ID, print information
void Tables::showStudentAdvisor(int stuId){
    Student* target = findStudent(stuId);

    if(target == nullptr){
        cout << "Student does not exist with id " << stuId << endl;
        return;
    }
    else{
        findAndDisplayFaculty(target->getAdvisor());
    }
}

// prints entire faculty members advisee list
void Tables::printAllAdvisees(int facId){
    Faculty* target = findFaculty(facId);

    if(target == nullptr){
        cout << "Faculty member does not exist with id " << facId << endl;
        return;
    }
    else{
        target->getAdviseeList()->printReverse();
    }
}

// adds student to the table
void Tables::addStudent(){
    cout << "Name: ";
    string name;
    cin>> name;

    cout << "Id: ";
    int id;
    cin>> id;

    cout << "gpa: ";
    double gpa;
    cin>> gpa;

    cout << "major: ";
    string major;
    cin>> major;

    cout << "Advisor: ";
    int advisor;
    cin>> advisor;

    Student* stu = new Student(id, name, major, gpa, advisor);
    RollbackItem item = RollbackItem(7);
    item.setStudent(stu);
    rollbackData.push_back(item);

    masterStudent->insert(stu);
}

// adds faculty to the table
void Tables::addFaculty(){
    cout << "Name: ";
    string name;
    cin>> name;

    cout << "Id: ";
    int id;
    cin>> id;

    cout << "Level: ";
    string level;
    cin>> level;

    cout << "Department: ";
    string dept;
    cin>> dept;


    Faculty* fac = new Faculty(id, name, level, dept);
    RollbackItem item = RollbackItem(9);
    item.setFaculty(fac);
    rollbackData.push_back(item);

    masterFaculty->insert(fac);
}

// deletes a faculty member
void Tables::deleteFaculty(int facId){
    Faculty* target = findFaculty(facId);

    if(target == nullptr){
        cout << "Faculty member with ID " << facId << " does not exist and cannot be deleted." << endl;
        return;
    }

    vector<TreeNode<Student*>*> students;
    masterStudent->getInOrderVector(masterStudent->getRoot(),students);

    RollbackItem item = RollbackItem(10);
    item.setFaculty(target);

    masterFaculty->deleteNode(target);

    vector<TreeNode<Faculty*>*> faculty;
    masterFaculty->getInOrderVector(masterFaculty->getRoot(), faculty);


    for (int i = 0; i < students.size(); i++) {
        if(students[i]->key->getAdvisor() == facId){
            int newAdvisorIndex = rand() % faculty.size();
            students[i]->key->setAdvisor(faculty[newAdvisorIndex]->key->getID()); //save fac id to student's advisor data
            faculty[newAdvisorIndex]->key->addAdvisee(students[i]->key->getID()); //save student id to fac's advisee list
        }
    }

} //make sure to save their id, and then traverse WHOLE student tree (use traversal to vect fn to make vecor so easier) and any student with professor id, remove that id and give them new advisor randomly

// deletes student given their ID, removes their object from the faculty members advisee list
void Tables::deleteStudent(int stuId){
    Student* target = findStudent(stuId);
    if(target == nullptr){
        cout << "Student with ID " << stuId << " does not exist and cannot be deleted." << endl;
        return;
    }

    int facId = target->getAdvisor();

    Faculty* fac = findFaculty(facId);

    RollbackItem item = RollbackItem(8);
    item.setFaculty(fac);
    item.setStudent(target);

    if(fac == nullptr){
        return;
    }

    fac->getAdviseeList()->remove(target->getID());
    masterStudent->deleteNode(target);
}

// reinforces and maintains referential integrity in terms of deleting an advisor, and appointing all student in old list a new one
void Tables::changeAdvisor(int stuId, int newFacId){
    Faculty* fac = findFaculty(newFacId);
    Student* stu = findStudent(stuId);


    if(stu == nullptr){
        cout << "Error - cannot find student with id " << stuId << " to update advisor, since no such student exists" << endl;
        return;
    }
    if(fac == nullptr){
        cout << "Error - cannot give student with id " << stuId << " new faculty advisor, since no faculty member with id " << newFacId << " does not exist" << endl;
        return;
    }
    RollbackItem item = RollbackItem(11);
    item.setFaculty(fac);
    item.setStudent(stu);

    Faculty* oldAdvisor = findFaculty(stu->getAdvisor()); //get old advisor
    oldAdvisor->getAdviseeList()->remove(stu->getID()); //remove student from old advisor list
    stu->setAdvisor(newFacId); //save fac id to student's advisor data
    fac->addAdvisee(stu->getID()); //save student id to fac's advisee list
}

// // reinforces and maintains referential integrity in terms of deleting a student, and updating all instances of the deleted student in DB
void Tables::removeAdvisee(int stuId, int facId){
    Faculty* fac = findFaculty(facId);
    Student* stu = findStudent(stuId);

    if(stu == nullptr){
        cout << "Error - cannot find student with id " << stuId << " to remove from any advisee list" << endl;
        return;
    }
    if(fac == nullptr){
        cout << "Error -  no faculty member with id " << facId << " exists" << endl;
        return;
    }
    RollbackItem item = RollbackItem(12);
    item.setFaculty(fac);
    item.setStudent(stu);

    fac->getAdviseeList()->remove(stu->getID());

    vector<TreeNode<Faculty*>*> faculty;
    masterFaculty->getInOrderVector(masterFaculty->getRoot(), faculty);

    if(faculty.size() > 1){
        //make sure to pick diff advisor
        int newAdvisorIndex= rand() % faculty.size();
        while(faculty[newAdvisorIndex]->key->getID() == facId){
            newAdvisorIndex= rand() % faculty.size();
        }

        //update to new advisor
        stu->setAdvisor(faculty[newAdvisorIndex]->key->getID()); //save fac id to student's advisor data
        faculty[newAdvisorIndex]->key->addAdvisee(stu->getID()); //save student id to fac's advisee list

    }
    else{
        cout << "Warning - student with id " << stu->getID() << " was removed from the only advisor's advisee list. They now no longer have an advisor." << endl;
        stu->setAdvisor(-1);
    }


}

// switches on all operations that might require reversal in terms of changes to the tree
void Tables::rollback(){
    if(rollbackData.size() == 0){
        cout << "No rollback options available" << endl;
        return;
    }

    RollbackItem item = rollbackData.at(0);
    rollbackData.erase(rollbackData.begin());

    switch (item.getMenuId()) {
        case 7: //reversing add student
        {
            deleteStudent(item.getStudent()->getID());
            break;
        }
        case 8: //reversing delete student
        {
            masterStudent->insert(item.getStudent());
            changeAdvisor(item.getStudent()->getID(), item.getFaculty()->getID());
            break;
        }
        case 9: //reversing add faculty
        {
            deleteFaculty(item.getFaculty()->getID());
            break;
        }
        case 10: //reversing delete faculty
        {
            masterFaculty->insert(item.getFaculty());
            break;
        }
        case 11: //reversing update advisor
        {
            changeAdvisor(item.getStudent()->getID(), item.getFaculty()->getID());
            break;
        }
        case 12: //reversing remove advisee
        {
            item.getStudent()->setAdvisor(item.getFaculty()->getID());
            item.getFaculty()->addAdvisee(item.getStudent()->getID());
            break;
        }
        default:
            break;
    }
}

// prints the students from the tree in ascending id #
bool Tables::printStudents(){
    vector<TreeNode<Student*>*> students;
    bool treeEmpty = true;

    masterStudent->getInOrderVector(masterStudent->getRoot(),students);

    for(int i = 0; i < students.size(); i++){
        if(students[i]->key->getName().length() != 0){
            cout << students[i]->key->getName() << ", "<< students[i]->key->getID() << ", "<< students[i]->key->getMajor() << ", "<< students[i]->key->getGPA() << ", "<< students[i]->key->getAdvisor() << endl;
            treeEmpty = false;
        }

    }
    return treeEmpty;
}

 //all their info, sorted by ascending ID #
bool Tables::printFaculty(){
    vector<TreeNode<Faculty*>*> faculty;
    bool treeEmpty = true;

    masterFaculty->getInOrderVector(masterFaculty->getRoot(), faculty);

    for(int i = 0; i < faculty.size(); i++){
        if(faculty[i]->key->getName().length() != 0){
            cout << faculty[i]->key->getName() << ", "<< faculty[i]->key->getID() << ", "<< faculty[i]->key->getLevel() << ", "<< faculty[i]->key->getDepartment() << ", "<< faculty[i]->key->getAdviseeList()->toFileString() << endl;
            treeEmpty = false;
        }
    }
    return treeEmpty;
}

// finds a student given the id number, traverses tree until found, null if not
Student* Tables::findStudent(int stuId){
    TreeNode<Student*>* root = masterStudent->getRoot();
    if(root == nullptr){
        return nullptr;
    }
    TreeNode<Student*>* current = root;
    while(current != nullptr && current->key->getID() != stuId){

        if(current->key->getID() < stuId){
            current = current->right;
        }
        else{
            current = current->left;
        }

    }
    if(current == nullptr){
        return nullptr;
    }
    return current->key;
}

// finds faculty given the id number, traverses the tree until found, null if not
Faculty* Tables::findFaculty(int facId){
    TreeNode<Faculty*>* root = masterFaculty->getRoot();
    if(root == nullptr){
        return nullptr;
    }
    TreeNode<Faculty*>* current = root;
    while(current != nullptr && current->key->getID() != facId){
        if(current->key->getID() < facId){
            current = current->right;
        }
        else{
            current = current->left;
        }

    }
    if(current == nullptr){
        return nullptr;
    }
    return current->key;
}
