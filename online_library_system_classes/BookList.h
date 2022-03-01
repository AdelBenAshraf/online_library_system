#ifndef OOP_ASSIGNMENT2_BOOKLIST_H
#define OOP_ASSIGNMENT2_BOOKLIST_H
#include "Book.h"

class BookList {
private:
    Book* books_;
    int capacity_;
    int booksCount_;
public:
    BookList(const BookList&);
    BookList(int);
    Book& searchBook(string);
    Book& searchBook(int);
    void addBook(Book);
    void deleteBook(int);
    Book& getTheHighestRatedBook();
    Book* getBooksForUser(User); // get all books of this author.
    Book & operator [] (int);
    void operator= (const BookList&);
    friend ostream & operator << (ostream &, BookList&);
    ~BookList();


};


#endif
