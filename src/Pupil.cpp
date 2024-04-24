#include "Pupil.h"
#include <iostream>

Pupil::Pupil(const std::string& name, std::shared_ptr<Library> lib, int age) : User(name, lib, age) {
    userCount++;
    id = userCount;
}




