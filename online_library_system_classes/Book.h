/*
@author Amira Ali || ID:20190111 || G14
@author Adel Ashraf || ID:20190279 || G14

@Explaination: This is.h  Bookwhich is responsible for making objects of
 type Books which have these attributes: (title, ISBN, ID, Category, author and average rating).

 It have setters and getters for every attribute, have the equality operator overloading, input operator overloading, output operator overloading and a function to be used for rating books.

 ..........

*/
#ifndef OOP_ASSIGNMENT2_BOOK_H
#define OOP_ASSIGNMENT2_BOOK_H

#include<cstring>
#include<iostream>
#include "User.h"

using namespace std;


class Book {
private:

    string title_;
    string isbn_;// International Standard Book Number
    int id_;
    string category_;
    float averageRating_;// this variable should contain the average rating for the book, rateBook function
    float countRating;// This used to count the number of ratings of the book.
    int sumRating;// This used to sum the ratings.
    static int count;// This used to increment the ID variable
    User author_;
public:

    Book();// This is the default constructor.

    Book(string , string , string);// This is the parameterized constructor.

    Book(const Book&);// This is the copying constructor which use references to improve memory using efficiency.

    void setTitle(string);// This used for setting the title as obvious, It takes a parameter of type string.
    string getTitle();// This used for getting the title.

    void setIsbn(string );// This used for setting the ISBN, It takes a parameter of type string.
    string getIsbn();// This used for getting the ISBN.

    void setId();// This used for setting the ID.
    void setId(int id);
    int getId();// This used for getting the ID.


    void setCategory(string);// This used for setting the category of the book, It takes a parameter of type string.
    string getCategory();// This used for getting the category of the book.


    void setAuthor(User);// This for setting the author, it takes a parameter of type User.
    User getAuthor();// This for getting the author.


    void rateBook(float);// This function to calculate and update the book rating, and it takes a parameter of type string.
    float getAverageRating();

    bool operator == (const Book&); // This is an equality operator overloading.



    friend ostream &operator<<(ostream &output, const Book &); // This friend function is the output operator overloading.
    friend istream &operator>>( istream  &input, Book &);// This friend function is the input operator overloading.
};

#endif