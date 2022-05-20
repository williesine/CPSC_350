
#ifndef ROLLBACKITEM_HPP
#define ROLLBACKITEM_HPP

#include <stdio.h>

class RollbackItem {
private:
    int menuId;
    Student* stu;
    Faculty* fac;

public:

    // overloaded
    RollbackItem(int id){
        menuId = id;
        stu = nullptr;
        fac = nullptr;
    }


    void setStudent(Student* stu){
        this->stu = stu;
    }
    void setFaculty(Faculty* fac){
        this->fac = fac;
    }
    Student* getStudent(){
        return stu;
    }
    Faculty* getFaculty(){
        return fac;
    }
    int getMenuId(){
        return menuId;
    }
};

#endif /* RollbackItem_hpp */
