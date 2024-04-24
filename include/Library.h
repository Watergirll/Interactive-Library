#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <stdexcept> // for std::out_of_range
#include "Book.h"    // assuming Book class is defined elsewhere
#include "Taste.h"   // assuming Taste class is defined elsewhere

class Library {
private:
    std::vector<Book> bookCollection;

public:
    /// Constructor
    Library();
    /// Copy constructor
    Library(const Library& altaBiblioteca);

    void adaugaCarte(const Book& carte); // Method for adding a book
    void stergeCarte(int index);          // Method for deleting a book

    Book getCarteDinColectie(int index);

    [[nodiscard]] const std::vector<Book> &getBookCollection() const;
    // Method for getting a book from collection by index

};

#endif // LIBRARY_H
