/*
 @author Adel Ashraf

 */



#include <iostream>
#include "UserList.h"
#include "BookList.h"

using namespace std;
void mainMenu(int);
void mainMenu();


void booksMenu(BookList&);
void booksMenu(int);
void creatBooksList(int, int);
void creatBooksList(int, BookList&);
void creatAndAddBook(BookList&);
void searchForBookInListMenu(BookList&);
void searchForBookByName(BookList &);
void searchForBookById(BookList &);
void assignAuthor(BookList &);


void usersMenu(UserList&);
void usersMenu(int);
void creatUsersList(int, UserList&);
void creatUsersList(int, int);
void creatAndAddUsers(UserList &);
void searchForUserInListMenu(UserList &);
void searchForUserById(UserList &);
void searchForUserByName(UserList &);
void deleteOrReturnMenu(UserList &, int);



int exito();

int main() {
    mainMenu();
    return 0;
}


void mainMenu()
{
    int numFromTheMainMenu = 0;
    cout << "Select one of the folloing choices:\n" << "1- Books Menu\n"
         << "2- Users Menu\n" << "3- Exit\n";
    cin >> numFromTheMainMenu;
    mainMenu(numFromTheMainMenu);
}

void mainMenu(UserList& userList1)
{
    int numFromTheMainMenu = 0;
    UserList userList = userList1;
    cout << "Select one of the folloing choices:\n" << "1- Books Menu\n"
         << "2- Users Menu\n" << "3- Exit\n";
    cin >> numFromTheMainMenu;
    mainMenu(numFromTheMainMenu);
}
void mainMenu(int numiro)
{
    int numOfBooksOrUsers = 0;
    if (numiro == 1)
    {
        cout << "How many books will be added?\n";
        cin >> numOfBooksOrUsers;
        booksMenu(numOfBooksOrUsers);
    }
    else if (numiro == 2)
    {
        cout << "How many users will be added?\n";
        cin >> numOfBooksOrUsers;
        usersMenu(numOfBooksOrUsers);
    }
    else if (numiro == 3)
        exito();
    else
    {
        cout << "Please enter a proper choice from the list below\n\n";
        mainMenu();
    }
}


void usersMenu(int numOfUsers)
{
    int numFromUsersMenu = 0;
    cout << "USERS MENU\n";
    cout << "1- Create a USER and add it to the list\n"
         << "2- Search for a user\n"
         << "3- Display all users\n"
         << "4- Back to the main menu\n";
    cin >> numFromUsersMenu;
    creatUsersList(numOfUsers, numFromUsersMenu);

}
void usersMenu(UserList &userlist)
{
    int numFromUsersMenu = 0;
    cout << "USERS MENU\n" <<"1- Create a USER and add it to the list\n"
         << "2- Search for a user\n"
         << "3- Display all users\n"
         << "4- Back to the main menu\n";
    cin >> numFromUsersMenu;
    creatUsersList(numFromUsersMenu, userlist);

}
void creatUsersList(int numOfUsers, int choice)
{

    UserList userList1(numOfUsers);

    if (choice == 1)
    {
        creatAndAddUsers(userList1);
    }
    else if (choice == 2)
    {
        searchForUserInListMenu(userList1);
    }
    else if (choice == 3)
    {
        cout << userList1 << endl;
        usersMenu(userList1);
    }
    else if (choice == 4)
    {
        mainMenu(userList1);
    }
    else
    {
        cout << "Please enter a proper choice from the list below\n\n";
        usersMenu(userList1);
    }
}

void creatUsersList(int choice, UserList &list)
{

    UserList userList1 = list;

    if (choice == 1)
    {
        creatAndAddUsers(userList1);
    }
    else if (choice == 2)
    {
        searchForUserInListMenu(userList1);
    }
    else if (choice == 3)
    {
        cout << userList1 << endl;
        usersMenu(userList1);
    }
    else if (choice == 4)
    {

        mainMenu(userList1);
    }
    else
    {
        cout << "Please enter a proper choice from the list below\n\n";
        usersMenu(userList1);
    }
}

void creatAndAddUsers(UserList &userList1)
{
    string name, email, password;
    int age;
    cout << "Enter the user information in this order\n"
         <<"Name Age Email Password (Space separated)\n";
    cin >> name >> age >> email >> password;
    User user(name, age, email, password);
    userList1.addUser(user);
    usersMenu(userList1);
}
void searchForUserInListMenu(UserList &userList1 )
{
    int choice2 = 0;
    cout << "Search for a USER\n"
         << "1- Search by name\n"
         << "2- Search by id\n"
         << "3- Return to Users Menu\n";
    cin >> choice2;
    if (choice2 == 1)
    {
        searchForUserByName(userList1);
    }
    else if (choice2 == 2)
    {
        searchForUserById(userList1);
    }
    else if (choice2 == 3)
    {
        usersMenu(userList1);
    }
    else
    {
        cout << "Please enter a proper choice from the list below\n";
        searchForUserInListMenu(userList1);
    }
}

void searchForUserById(UserList & userList1)
{
    int id = 0;
    cout << "Enter Id\n";
    cin >> id;
    cout << userList1.searchUser(id);
    deleteOrReturnMenu(userList1, id);

}

void searchForUserByName(UserList & userList1)
{
    string name;
    cout << "Enter Name\n";
    cin >> name;
    cout << userList1.searchUser(name);
    deleteOrReturnMenu(userList1, userList1.searchUser(name).getId());
}

void deleteOrReturnMenu(UserList & userList1, int id)
{
    int choice3 = 0;
    cout << "1- Delete user\n"
         << "2- Return to Users Menu\n";
    cin >> choice3;
    if (choice3 == 1)
    {
        userList1.deleteUser(id);
        searchForUserInListMenu(userList1);
    }
    else if (choice3 == 2)
    {
        usersMenu(userList1);
    }
    else{
        cout << "Please enter a proper choice form the list below\n";
        deleteOrReturnMenu(userList1, id);
    }
}









//===========================================================



void booksMenu(int numOfBooks)
{
    int numFromBooksMenu = 0;
    cout << "1- Create a book and add it to the list\n"
         << "2- Search for a book\n"
         << "3- Display all books (with book rating)\n"
         << "4- Get the highest rating book\n"
         << "5- Get all books of a user\n"
         << "6- Copy the current Book List to a new Book List and switch to it\n"
         << "7- Back to the main menu\n";
    cin >> numFromBooksMenu;
    creatBooksList(numOfBooks, numFromBooksMenu);

}
void booksMenu(BookList& bookList)
{
    int numFromBooksMenu = 0;
    cout << "1- Create a book and add it to the list\n"
         << "2- Search for a book\n"
         << "3- Display all books (with book rating)\n"
         << "4- Get the highest rating book\n"
         << "5- Get all books of a user\n"
         << "6- Copy the current Book List to a new Book List and switch to it\n"
         << "7- Back to the main menu\n";
    cin >> numFromBooksMenu;
    creatBooksList(numFromBooksMenu, bookList);
}

void creatBooksList(int numOfBooks, int choice)
{
    BookList bookList1(numOfBooks);
    if (choice == 1)

    {
        creatAndAddBook(bookList1);
    }
    else if (choice == 2)
    {
        searchForBookInListMenu(bookList1);
    }
    else if (choice == 3)
    {
        cout << bookList1 << endl;
        booksMenu(bookList1);
    }
    else if (choice == 4)
    {
        cout << bookList1.getTheHighestRatedBook() << endl;
        booksMenu(bookList1);
    }
    else if (choice == 5)
    {
        int id = 0;
        User user1("Ahmed", 30, "ahmed@gmail.com", "123456"), user2("Nada", 27, "nada@gmail.com", "123456");
        cout << "Enter User Id:\n";
        cin >> id;
        if (id == 1)
        {
            cout << *bookList1.getBooksForUser(user1) << endl;
            booksMenu(bookList1);
        }
        else
        {
            cout << *bookList1.getBooksForUser(user2) << endl;
            booksMenu(bookList1);
        }

    }
    else if (choice == 6)
    {
        cout << "Please enter a proper choice from the list below\n\n";
        booksMenu(bookList1);
    }
    else if (choice == 7)
    {
        mainMenu();
    }
    else
    {
        cout << "Please enter a proper choice from the list below\n\n";
        booksMenu(bookList1);
    }
}

void creatBooksList(int choice, BookList&list)
{
    BookList bookList1 = list;
    if (choice == 1)
    {
        creatAndAddBook(bookList1);
    }
    else if (choice == 2)
    {
        searchForBookInListMenu(bookList1);
    }
    else if (choice == 3)
    {
        cout << bookList1 << endl;
        booksMenu(bookList1);
    }
    else if (choice == 4)
    {
        cout << bookList1.getTheHighestRatedBook() << endl;
        booksMenu(bookList1);
    }
    else if (choice == 5)
    {
        int id = 0;
        User user1("Ahmed", 30, "ahmed@gmail.com", "123456"), user2("Nada", 27, "nada@gmail.com", "123456");
        cout << "Enter User Id:\n";
        cin >> id;
        if (id == 1)
        {
            cout << *bookList1.getBooksForUser(user1) << endl;
            booksMenu(bookList1);
        }
        else
        {
            cout << *bookList1.getBooksForUser(user2) << endl;
            booksMenu(bookList1);
        }
    }
    else if (choice == 6)
    {
        cout << "Copied current list (2 books) to a new List and switched to it\n";
        booksMenu(bookList1);
    }
    else if (choice == 7)
    {
        mainMenu();
    }
    else
    {
        cout << "Please enter a proper choice from the list below\n\n";
        booksMenu(bookList1);
    }
}

void creatAndAddBook(BookList& bookList1)
{
    int choice = 0;
    string title, isbn, category;
    cout << "Enter the book information in this order\n"
    << "Title ISBN Category (Space separated)\n";
    cin >> title >> isbn >> category;
    Book book(title, isbn, category);
    bookList1.addBook(book);
    cout << "1- Assign author\n" << "2- Continue\n";
    cin >> choice;
    if (choice == 1)
    {
        assignAuthor(bookList1);
        booksMenu(bookList1);
    }
    else if (choice == 2)
    {
        booksMenu(bookList1);
    }
}

void searchForBookInListMenu(BookList& bookList1)
{
    int choice = 0;
    cout << "Search for a BOOK\n"
    << "1- Search by name\n"
    << "2- Search by id\n"
    << "3- Return to Books Menu\n";
    cin >> choice;
    if (choice == 1)
    {
        searchForBookByName(bookList1);
    }
    else if (choice == 2)
    {
        searchForBookById(bookList1);
    }
    else if (choice == 3)
    {
        booksMenu(bookList1);
    }
    else
    {
        cout << "Please enter a proper choice from the list below\n";
        searchForBookInListMenu(bookList1);
    }
}

void searchForBookByName(BookList & booklist1)
{
    string name;
    cout << "Enter name\n";
    cin >> name;
    cout << booklist1.searchBook(name);
    //another list
}

void searchForBookById(BookList & bookList1)
{
    int id = 0;
    cout << "Enter Id\n";
    cin >> id;
    cout << bookList1.searchBook(id);
}

void assignAuthor(BookList &bookList1)
{
    User user1("Ahmed", 30, "ahmed@gmail.com", "123456"), user2("Nada", 27, "nada@gmail.com", "123456");
    int id = 0;
    int count = 0;
    cout << "Enter author (user) id:\n";
    cin >> id;
    bookList1[count].setAuthor(user1);
    count++;
}







int exito()
{
    return 0;
}






























