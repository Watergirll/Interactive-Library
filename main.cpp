#include <iostream>
#include "include/Exceptions.h"
#include "include/Library.h"
#include "include/Book.h"
#include "include/Taste.h"
#include "include/User.h"
#include "include/Student.h"
#include "include/Librarian.h"
using std::string;



int main(){
    //building the library

    Book c1("Titanic Vals", "Tudor Musatescu", "drama", 100, 1932, "leu", "vara"), c2("Plumb", "George Bacovia", "poezie", 100, 1916, "scorpion", "toamna");
    Library library;
    library.adaugaCarte(c1);
    library.adaugaCarte(c1);
    User user1("Teo", std::make_shared<Library> (library), 19);
    
    //code block to get a book by index
    try {
        Book book = library.getCarteDinColectie(0);
        // Use the book object
    } catch (std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        // Handle the out_of_range exception
    }

    //register the user's taste
    Taste userTaste("poezie", "", "scorpion", 2000, 1900, 10, 500);

    std::cout<<user1.recommendBook(userTaste);
    return 0;
}


