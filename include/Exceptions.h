#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

class BookNotAvailableException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Error: Book is not available for borrowing.";
    }
};

class BookAlreadyReturnedException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Error: Book is already returned.";
    }
};

#endif // EXCEPTIONS_H
