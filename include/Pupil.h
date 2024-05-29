#ifndef PUPIL_H
#define PUPIL_H

#include "User.h"
#include "Book.h"
// Derived class Pupil
class Pupil : public User {
public:
    Pupil(const std::string& name, std::shared_ptr<Library> lib, int age);
    Book recommendBook(const Taste& userTaste) override {
        // Implement the book recommendation logic for Pupil

    }

};

#endif // PUPIL_H
