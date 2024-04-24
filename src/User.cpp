#include "../include/User.h"
#include <iostream>

int User::userCount = 0;///the initialisation of the static variable of user -> I'll use it for the UserId


User::User(const std::string& name, std::shared_ptr<Library> lib, int age) : name(name), lib(lib), age(age) {
    userCount++;
    id = userCount;
}


int User ::getId() const { return id;}

// Method for recommending a book based on user's taste
Book User::recommendBook(const Taste& userTaste) {
    int maxScore = 0, score = 0;
    Book c = lib->getBookCollection()[0]; // Initialize with the first book

    for(const auto& book : lib->getBookCollection()) {
        if (userTaste.getzodiacSign() == book.getzodiacSign()) {
            score += 10;
        }
        /// Add more conditions for scoring based on taste
        if (score > maxScore) {
            c = book;
            maxScore = score;
        }
        score = 0;
    }
    return c;
}

const std::shared_ptr<Library> User::getLib() {
    return this->lib;
}

