#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "Book.h"

/// Derived class Student
class Student : public User {
public:
    Student(const std::string& name, std::shared_ptr<Library> lib, int age);
    Book recommendBook(const Taste& userTaste) override {
        // Implement the book recommendation logic for Pupil

    }
};

#endif // STUDENT_H
