#include "Librarian.h"
#include <iostream>

Librarian::Librarian(const std::string& name, std::shared_ptr<Library> lib, int age) : User(name, lib, age) {
    userCount++;
    id = userCount;
}




