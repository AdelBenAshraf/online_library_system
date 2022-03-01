#include "UserList.h"

UserList::UserList(int capacity)
{
    capacity_ = capacity;
    users_ = new User[capacity_];
    usersCount_ = 0;
}
UserList::UserList(const UserList &obj)
{
    this->users_ = new User[obj.capacity_];
    this->usersCount_ = obj.usersCount_;
    this->capacity_ = obj.capacity_;
    for (int i = 0; i < usersCount_; i++)
    {

        obj.users_[i].setId(i+1);
        this->users_[i] = obj.users_[i];
    }

}

void UserList::addUser(User user)
{
    if (usersCount_ <= capacity_)
    {
        users_[usersCount_] = user;
        usersCount_++;
    }
    else
        cout << "There is no empty places\n";
}
User & UserList::searchUser(string name)
{
    for (int i = 0; i < usersCount_; ++i)
    {
        if (users_[i].getName() == name)
        {
            return users_[i];
        }
    }
    cout << "User is not found\n";
}

User & UserList::searchUser(int id)
{
    for (int i = 0; i < usersCount_; ++i)
    {
        if (users_[i].getId() == id)
        {
            return users_[i];
        }
    }
    cout << "User not found\n";
}

void UserList::deleteUser(int id)
{
    for (int i = 0; i < usersCount_; ++i)
    {
        if (users_[i].getId() == id)
        {
            for (int j = i; j < usersCount_-1; ++j)
            {
                users_[j] = users_[j+1];

            }
        }
    }
    usersCount_--;
}

void UserList::operator=(const UserList &obj)
{
    if (this != &obj)
    {
        this->users_ = new User[obj.capacity_];
        this->capacity_= obj.capacity_;
        this->usersCount_ = obj.usersCount_;
        for (int i = 0; i < usersCount_; i++)
        {
            obj.users_[i].setId(i+1);
            this->users_[i] = obj.users_[i];
        }
    }
}


ostream &operator << (ostream &output, UserList & userList)
{
    for (int i = 0; i < userList.usersCount_; i++){
        output<< userList.users_[i] << endl;
    }
    return output;
}

UserList::~UserList()
{
    delete [] users_;
}