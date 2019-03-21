#ifndef CURRENTUSER_H
#define CURRENTUSER_H

#include <Repository/User/User.h>

class Session {
public:
    static User* currentUser;

private:
    Session();
    ~Session();
};

#endif // CURRENTUSER_H
