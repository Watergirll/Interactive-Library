#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

/// Derived class Student
class Student : public User {
public:
    Student(const std::string& name, std::shared_ptr<Library> lib, int age);

};

#endif // STUDENT_H
