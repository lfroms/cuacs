#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <Models/User/User.h>

class CurrentUser {
public:
    static User* user;

private:
    CurrentUser();
    ~CurrentUser();
};

#endif // CURRENTUSER_H
