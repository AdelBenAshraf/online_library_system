#include "BookList.h"

BookList::BookList(const BookList & anotherList)
{
    capacity_ = anotherList.capacity_;
    booksCount_ = anotherList.booksCount_;
    books_ = new Book[capacity_];
    for (int i = 0; i < booksCount_; i++)
    {
        anotherList.books_[i].setId(i+1);
        books_[i] = anotherList.books_[i];
    }
}

BookList::BookList(int capacity)
{
    capacity_ = capacity;
    booksCount_ = 0;
    books_ = new Book[capacity_];
    for (int i = 0; i < capacity_; i++)
    {
        books_[i].setTitle("");
        books_[i].setIsbn("");
        books_[i].setCategory("");
    }
}
void BookList::addBook(Book book)
{
    if (booksCount_ <= capacity_)
    {
        books_[booksCount_] = book;
        booksCount_++;
    }
}

Book & BookList::searchBook(string name)
{
    for (int i = 0; i < booksCount_; ++i)
    {
        if (books_[i].getTitle() == name)
        {
            return books_[i];
        }
    }
}

Book & BookList::searchBook(int id)
{
    for (int i = 0; i < booksCount_; ++i)
    {
        if (books_[i].getId() == id)
        {
            return books_[i];
        }
    }
}

void BookList::deleteBook(int id)
{
    for (int i = 0; i < booksCount_; ++i)
    {
        if (books_[i].getId() == id)
        {
            for (int j = i; j < booksCount_-1; ++j)
            {
                books_[j] = books_[j+1];

            }
        }
    }
    booksCount_--;
}

Book &BookList::getTheHighestRatedBook()
{
    int max = 0;
    for ( int i = 1; i < booksCount_; ++i)
    {
        if (books_[i].getAverageRating() > books_[max].getAverageRating())
        {
            max = i;
        }
    }
    return books_[max];
}

Book * BookList::getBooksForUser(User user)
{
    for (int i = 0; i < booksCount_; i++)
    {
        if (books_[i].getAuthor() == user)
        {
            return &books_[i];
        }
    }
}

Book  &BookList::operator[](int position)
{
    if (position < 0 || position >= capacity_)
    {
        cout << "Please enter an existing position" << endl;
    }
    else
    {
        booksCount_++;
        return books_[position];
    }

}

void BookList::operator=(const BookList &anotherList)
{
    capacity_ = anotherList.capacity_;
    booksCount_ = anotherList.booksCount_;
    books_ = new Book[capacity_];
    for (int i = 0; i < booksCount_; i++)
    {
        anotherList.books_[i].setId(i+1);
        books_[i] = anotherList.books_[i];
    }
}


ostream &operator << (ostream &output, BookList & bookList)
{
    for (int i = 0; i < bookList.booksCount_; i++){
        output << bookList.books_[i] << endl;
    }
    return output;
}

BookList::~BookList()
{
    delete [] books_;
}
