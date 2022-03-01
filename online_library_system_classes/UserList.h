#ifndef OOP_ASSIGNMENT2_USERLIST_H
#define OOP_ASSIGNMENT2_USERLIST_H
#include "User.h"
#include "Book.h"

class UserList {
private:
    User* users_;
    int capacity_;
    int usersCount_;

public:
    UserList(int);
    UserList(const UserList&);
    void addUser(User);// at the end of the array.
    User& searchUser(string);
    User& searchUser(int);
    void deleteUser(int);
    void operator=(const UserList&);
    friend ostream &operator << (ostream &output, UserList &);
    ~UserList();


};
#endif
