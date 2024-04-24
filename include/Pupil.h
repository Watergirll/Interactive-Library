#ifndef PUPIL_H
#define PUPIL_H

#include "User.h"

// Derived class Pupil
class Pupil : public User {
public:
    Pupil(const std::string& name, std::shared_ptr<Library> lib, int age);


};

#endif // PUPIL_H
