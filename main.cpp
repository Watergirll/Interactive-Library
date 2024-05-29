#include <iostream>
#include "include/Exceptions.h"
#include "include/Library.h"
#include "include/Book.h"
#include "include/Taste.h"
#include "include/User.h"
#include "include/Student.h"
#include "include/Librarian.h"
#include "include/UserFactory.h"
#include "TasteBuilder.h"
using std::string;



int main(){
//    //building the library
//
    Book c1("Titanic Vals", "Tudor Musatescu", "drama", 100, 1932, "leu", "vara"), c2("Plumb", "George Bacovia", "poezie", 100, 1916, "scorpion", "toamna");
    Library library;
    library.adaugaCarte(c1);
    library.adaugaCarte(c1);
    User user_1("Teo", std::make_shared<Library> (library), 19);

    auto library1 = std::make_shared<Library>();
//// Register user types
    UserFactory& factory = UserFactory::instance();
    factory.registerUser<Student>("Student");
    factory.registerUser<Pupil>("Pupil");
    factory.registerUser<Librarian>("Librarian");

    // Create user instances
    std::shared_ptr<User> user1 = factory.createUser("Student", "Alice", library1, 20);
    std::shared_ptr<User> user2 = factory.createUser("Pupil", "Bob", library1, 15);
    std::shared_ptr<User> user3 = factory.createUser("Librarian", "Charlie", library1, 35);

    // Print user details
    std::cout << user1->getId() << ": Alice is a Student." << std::endl;
    std::cout << user2->getId() << ": Bob is a Pupil." << std::endl;
    std::cout << user3->getId() << ": Charlie is a Librarian." << std::endl;



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

    TasteBuilder builder;
    Taste taste = builder.setGenLit("Science Fiction")
            .setAutor("Isaac Asimov")
            .setZodiacSign("Capricorn")
            .setAnMin(1950)
            .setAnMax(1990)
            .setLenMin(200)
            .setLenMax(500)
            .build();

    std::cout << taste << std::endl;

    std::cout<<user_1.recommendBook(userTaste);
//
//    return 0;
}


