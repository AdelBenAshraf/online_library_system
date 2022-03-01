/*
 @author Amira Ali || ID:20190111 || G14
 @author Adel Ashraf || ID:20190279 || G14

@Explaination: This User.cpp which have the implementation of the methods for the class which make type users
which have these attributes (name, age, email, password, id) and It have also the implementation of setters and getters for every attribute,
 have the equality operator overloading, input operator overloading and output operator overloading.

 .............


 */

#include "User.h"
#include <iostream>
using namespace std;

int User::count = 0;
User::User() {
    age_ = 0;
    name_ = "";
    email_ = "";
    password_ = "";
    id_ = ++count;

}

User::User(string name, int age, string email, string password) {
    name_ = name;
    age_ = age;
    email_ = email;
    password_ = password;
    id_ = ++count;
}

User::User(const User&user){
    name_ = user.name_;
    age_ = user.age_;
    email_ = user.email_;
    password_ = user.password_;
    id_ = user.id_;
}

void User::setName(string name) {
    name_ = name;
}
string User::getName() const {
    return name_;
}

void User::setAge(int age) {
    age_ = age;
}

int User::getAge() {
    return age_;
}

void User::setId() {
    id_ = count;
}
void User::setId(int id){
    id_ = id;
}

int User::getId() {
    return id_;
}

void User::setEmail(string email) {
    email_ = email;
}

string User::getEmail() {
    return email_;
}

void User::setPassword(string password) {
    password_ = password;
}

string User::getPassword() const {
    return password_;
}

bool User::operator == (const User&user){
    if (email_ == user.email_ && name_ == user.name_ && age_ == user.age_ && id_ == user.id_){
        return true;
    }else{
        return false;
    }
}

ostream &operator<<(ostream &output, const User &user){
    output << "========User " << user.id_ << " info ========\n"
    <<"Name: " << user.name_ << "\nAge: " << user.age_ << "\nId: " << user.id_ << "\nEmail: " << user.email_
    << "\n=====================================================\n";
    return output;
}
istream &operator>>(istream &input, User &user){
    input >> user.name_ >> user.age_ >> user.email_ >> user.password_;
    return input;
}
