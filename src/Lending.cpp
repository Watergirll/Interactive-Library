#include "Lending.h"
#include <memory>


Lending::Lending(int maxDays, float finePerDay) : maxDaysAllowed(maxDays), finePerDay(finePerDay) {}

// Function to borrow a book
void Lending::borrowBook(const User& user, Book& book ) {
    // Check if the book is available for borrowing
    if (! book.getAvailability()) {
        throw BookNotAvailableException();
    }
    else {
        // Book is available, so it can be borrowed
        borrowedBooks.emplace_back(user, std::make_unique<Book>( book ) );
        book.setIsAvailable(false); // Update availability status
        std::cout << "Book has been borrowed by user.\n";
    }
}

// Function to return a book
void Lending::returnBook(const User& user, Book &book) {
    // Check if the book was borrowed by the user
    for ( auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it ) {

        if ( it->first.getId() == user.getId() && it->second->getBookId() == book.getBookId() ) {

            // Book is found in the borrowed list, so it can be returned
            borrowedBooks.erase(it);
            book.setIsAvailable(true); // Update availability status
            std::cout << "Book has been returned.\n";
            return;
        }
    }

    // Book was not found in the borrowed list
    throw BookAlreadyReturnedException();
}
