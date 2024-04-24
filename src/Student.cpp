#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, std::shared_ptr<Library> lib, int age) : User(name, lib, age) {
    userCount++;
    id = userCount;
}

