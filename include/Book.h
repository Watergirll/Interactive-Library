#ifndef INTERACTIVE_LIBRARY_BOOK_H
#define INTERACTIVE_LIBRARY_BOOK_H

#include <iostream>
#include <vector>
#include <optional>
using std::string;

class Book {
private:
    string title;
    string author;
    string genre;
    int numberOfPages;
    int PublishingYear;
    string zodiacSignC;
    string seasonC;

    bool isAvailable;
    static int bookCount;
    int id;

public:

    /// Default constructor
    Book() = delete;

    // Initialisation constructor
    Book(const string &t, const string &a, const string &g, int nP, int an, const string &zS, const string &season, bool Available = true);

    //Copy Constructor
    Book (const Book& c1);//aici apelez constructorul init -> overloading

    Book& operator= (const Book& c);



    //Destructor
    ~Book() = default;


    // Methods on accessing the data of a Book
    [[nodiscard]] string getTitlu() const;
    [[nodiscard]] string getAutor() const;
    [[nodiscard]] string getGenLiterar() const;
    [[nodiscard]] int getnumarPagini() const;
    [[nodiscard]] int getAnPublicatie() const;
    [[nodiscard]] string getzodiacSign() const;
    [[nodiscard]] string getAnotimp() const;
    [[nodiscard]] bool getAvailability() const;
    [[nodiscard]] int getBookId() const;

    // Setter for isAvailable field
    void setIsAvailable(bool available);


    //afisare a datelor despre carte
    friend std::ostream& operator<<(std::ostream& os, const Book& c);

};


#endif //INTERACTIVE_LIBRARY_BOOK_H
