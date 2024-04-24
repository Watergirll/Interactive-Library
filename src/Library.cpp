#include "../include/Library.h"

// Constructor
Library::Library() : bookCollection(std::vector<Book>()) {}

// Copy constructor
Library::Library(const Library& altaBiblioteca) {
    bookCollection = altaBiblioteca.bookCollection;
}

// Method for adding a book
void Library::adaugaCarte(const Book& carte) {
    bookCollection.push_back(carte);
}

// Method for deleting a book
void Library::stergeCarte(int index) {
    if(index >= 0 && index < (int)bookCollection.size()) {
        bookCollection.erase(bookCollection.begin() + index);
    } else {
        throw std::out_of_range("Indexul este în afara limitelor colecției de cărți.");
    }
}

// Method for getting a book from collection by index
Book Library::getCarteDinColectie(int index) {

    if(index >= 0 && index < (int)bookCollection.size()) {
        return bookCollection[index];
    } else {
        throw std::out_of_range("Indexul este în afara limitelor colecției de cărți.");
    }
}

const std::vector<Book> &Library::getBookCollection() const {
    return bookCollection;
}

