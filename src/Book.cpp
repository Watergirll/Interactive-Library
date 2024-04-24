#include "../include/Book.h"

int Book::bookCount = 0;

// Initialisation constructor
Book::Book(const string &t, const string &a, const string &g, int nP, int an, const string &zS, const string &season, bool Available) :
        title(t), author(a), genre(g), numberOfPages(nP), PublishingYear(an), zodiacSignC(zS), seasonC(season), isAvailable(Available) {
    bookCount++;
    id = bookCount;
}

Book::Book(const Book &c1) : Book(c1.title, c1.author, c1.genre, c1.numberOfPages, c1.PublishingYear, c1.zodiacSignC, c1.seasonC, c1.isAvailable) {
    this->id = c1.id;
}

Book &Book::operator=(const Book &c) {
    title = c.title;
    author = c.author;
    genre = c.genre;
    numberOfPages = c.numberOfPages;
    PublishingYear = c.PublishingYear;
    zodiacSignC = c.zodiacSignC;
    seasonC = c.seasonC;
    isAvailable = c.isAvailable;
    return *this;
}



string Book::getTitlu() const { return title; }

string Book::getAutor() const { return author; }

string Book::getGenLiterar() const { return genre; }

int Book::getnumarPagini() const {return numberOfPages;}

int Book::getAnPublicatie() const { return PublishingYear; }

string Book::getzodiacSign() const { return zodiacSignC; }

string Book::getAnotimp() const { return seasonC; }

bool Book :: getAvailability() const { return isAvailable;}

int Book ::getBookId() const { return id; }

// Setter for isAvailable field
void Book :: setIsAvailable(bool available) {
    isAvailable = available;
}

std::ostream &operator<<(std::ostream &os, const Book &c) {
    os << c.title << " " << c.author << " " << c.genre << " " << c.numberOfPages << " " << c.PublishingYear << std::endl;
    return os;
}


