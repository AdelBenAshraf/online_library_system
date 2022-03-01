/*
 @author Amira Ali || ID:20190111 || G14
 @author Adel Ashraf || ID:20190279 || G14

@Explaination: This User.h which have the declaration of the attribute and methods for the class which make type users
which have these attributes (name, age, email, password, id) and It have setters and getters for every attribute,
 have the equality operator overloading, input operator overloading and output operator overloading.

 .............


 */

#ifndef OOP_ASSIGNMENT2_USER_H
#define OOP_ASSIGNMENT2_USER_H



#include <cstring>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class User {
private:
    string name_;
    int age_;
    int id_;
    string password_;
    string email_;

public:
    static int count;// This used to increment the ID attribute.

    User();// This the default constructor.
    User(string, int, string, string);//This is the parameterized constructor.
    User(const User&);//This is the copying constructor and it is using reference to avoid copying by value and avoid wasting memory.

    bool operator == (const User&);// This is an equality operator overloading to compare to users to each other.

    void setName(string); // This function takes one parameter which is string to set the name.
    string getName() const;// This function used for getting the name.

    void setPassword(string);// This function takes one parameter which is string to set the password.
    string getPassword() const;// This function used for getting the password.

    void setEmail(string);// This function takes one parameter which is string to set the email.
    string getEmail();// This function used for getting the email.

    void setAge(int);// This function takes one parameter which is int to set the age.
    int getAge();// This function used for getting the age.

    void setId();// This function for setting the Id.
    void setId(int);
    int getId();// // This function used for getting the Id.

    friend ostream &operator<<(ostream &output, const User &);// This friend function is the output operator overloading.
    friend istream &operator>>(istream &input, User &);// This friend function is the input operator overloading.
};

#endif
