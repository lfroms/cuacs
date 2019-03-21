#ifndef SESSION_H
#define SESSION_H

#include <Repository/User/User.h>

class Session {
public:
    static User* currentUser;

private:
    Session();
    ~Session();
};

#endif // SESSION_H
