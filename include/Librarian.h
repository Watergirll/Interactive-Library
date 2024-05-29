#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "User.h"
#include "Book.h"

// Derived class Librarian
class Librarian : public User {
public:
    Librarian(const std::string& name, std::shared_ptr<Library> lib, int age);


};

#endif // LIBRARIAN_H
