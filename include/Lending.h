#ifndef LENDING_H
#define LENDING_H

#include <iostream>
#include <vector>
#include "Book.h" // Assuming Book class is defined elsewhere
#include "User.h" // Assuming User class is defined elsewhere
#include "Exceptions.h" // Including custom exceptions
#include <memory>

class Lending {
private:

    std::vector<std::pair<User, std::unique_ptr<Book> > >borrowedBooks ; // List of borrowed books with corresponding users
    int maxDaysAllowed; // Maximum days allowed for borrowing
    float finePerDay; // Fine amount per day for overdue books

public:
    Lending(int maxDays, float finePerDay);

    // Function to borrow a book
    void borrowBook(const User& user, Book& book );

    // Function to return a book
    void returnBook(const User& user, Book& book );

    // Other functions for managing lending operations, such as checking due dates, calculating fines, etc.
};

#endif // LENDING_H
