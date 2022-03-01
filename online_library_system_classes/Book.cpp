/*
@author Amira Ali || ID:20190111 || G14
@author Adel Ashraf || ID:20190279 || G14

@Explaination: This is Book.cpp which is responsible for making objects of
 type Books which have these attributes: (title, ISBN, ID, Category, author and average rating).

 It have the implementation of the following  setters and getters for every attribute, have the equality operator overloading,
 input operator overloading, output operator overloading and a function to be used for rating books.

 ..........

*/

#include "Book.h"
#include <iostream>

using namespace std;

int Book::count = 0;
Book::Book() {
    title_ = "";
    isbn_ = "";
    category_ = "";
    id_ = ++count;
    countRating = 0;
    averageRating_ = 0;
    sumRating = 0;
    User author_;
}

Book::Book(string title, string isbn, string category) {
    title_ = title;
    isbn_ = isbn;
    category_ = category;
    id_ = ++count;
    countRating = 0;
    averageRating_ = 0;
    sumRating = 0;
    User author_;
}

Book::Book(const Book& book){
    title_ = book.title_;
    isbn_ = book.isbn_;
    category_ = book.category_;
    id_ = book.id_;
    author_ = book.author_;
}

void Book::setTitle(string title){
    title_ = title;
}

string Book::getTitle(){
    return title_;
}

void Book::setIsbn(string isbn){
    isbn_ = isbn;
}

string Book::getIsbn(){
    return isbn_;
}

void Book::setId(){
    id_ = count;
}
void Book::setId(int id){
    id_ = id;
}
int Book::getId(){
    return id_;
}

void Book::setCategory(string category){
    category_ = category;
}
string Book::getCategory(){
    return category_;
}
void Book::setAuthor(User user){
    author_ = user;
}
User Book::getAuthor(){
    return author_;
}


void Book::rateBook(float rating){
    countRating++;
    sumRating += rating;
    if (countRating != 0)
        averageRating_ = (sumRating/countRating);
}

float Book::getAverageRating()
{
    return averageRating_;
}


bool Book::operator == (const Book& book){
    if (title_ == book.title_ && isbn_ == book.isbn_ && category_ == book.category_ && id_ == book.id_ && author_ == book.author_)
        return true;
    else
        return false;
}


ostream &operator<<(ostream &output, const Book &book ){
    output << "========Book " << book.id_ << " info ========\n"
    << "Title: " << book.title_ << "\nISBN: " << book.isbn_ << "\nId: " <<  book.id_ << "\nCategory: " << book.category_ << "\nAverage Rating: " << book.averageRating_
    << "\n=========================================================\n";
    return output;
}

istream &operator>>( istream  &input, Book &book ){
    input >> book.title_ >> book.isbn_ >> book.category_;
    return input;
}

