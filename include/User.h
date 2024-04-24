#ifndef USER_H
#define USER_H

#include <string>
#include "Book.h"
#include "Taste.h"
#include "Library.h"
#include <memory>


// Base class User
class User {
protected:
    std::string name;
    std::shared_ptr<Library> lib;
    int age;
    int id;
    static int userCount;


public:
    User(const std::string& name, std::shared_ptr<Library> lib, int age);
    virtual ~User() = default;



    [[nodiscard]] int getId() const;
    virtual Book recommendBook(const Taste& userTaste); // Method for recommending a book based on user's taste

    const std::shared_ptr<Library> getLib();

};

#endif // USER_H
