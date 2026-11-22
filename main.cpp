
#include <iostream>
#include <string>
#include <array>
#include <Book.h>

using namespace std;

array<Book, 50> books;
int bookCount = 8;

void addBook();
void displayBooks();
void searchBook();
void borrowBook();
void returnBook();
void checkOverdueBooks();

int main()
{
    // books in the library
    books[0].setBook("Harry Potter and the Philosopher's Stone",
                     "J.K. Rowling", "B001");

    books[1].setBook("The Hunger Games",
                     "Suzanne Collins", "B002");

    books[2].setBook("Charlotte's Web",
                     "E.B. White", "B003");

    books[3].setBook("The Little Prince",
                     "Antoine de Saint-Exupery", "B004");

    books[4].setBook("Diary of a Wimpy Kid",
                     "Jeff Kinney", "B005");

    books[5].setBook("The Adventures of Tom Sawyer",
                     "Mark Twain", "B006");

    books[6].setBook("Romeo and Juliet",
                     "William Shakespeare", "B007");

    books[7].setBook("The Jungle Book",
                     "Rudyard Kipling", "B008");

    int choice;

    do
    {
        cout << "\n===== LIBRARY LENDING SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. View All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Borrow Book";
        cout << "\n5. Return Book";
        cout << "\n6. Check Overdue Books";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                borrowBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                checkOverdueBooks();
                break;

            case 7:
                cout << "\nThank you for using the system.";
                break;

            default:
                cout << "\nInvalid choice. Please try again.";
        }

    } while (choice != 7);

    return 0;
}

// Function 1: Add a new book
void addBook()
{
    if (bookCount >= 50)
    {
        cout << "\nThe library list is full.";
        return;
    }

    string title, author, id;

    cout << "\nEnter Book ID: ";
    getline(cin, id);

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books[bookCount].setBook(title, author, id);
    bookCount++;

    cout << "\nBook added successfully.";
}

// Function 2: Display all books
void displayBooks()
{
    if (bookCount == 0)
    {
        cout << "\nThere are no books in the library.";
        return;
    }

    cout << "\n===== ALL LIBRARY BOOKS =====";

    for (int i = 0; i < bookCount; i++)
    {
        books[i].displayBook();
    }
}

// Function 3: Search for a book
void searchBook()
{
    string id;
    int found = 0;

    cout << "\nEnter the Book ID: ";
    getline(cin, id);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getID() == id)
        {
            books[i].displayBook();
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "\nBook not found.";
    }
}

// Function 4: Borrow a book
void borrowBook()
{
    string id, name, date;
    int found = 0;

    cout << "\nEnter Book ID: ";
    getline(cin, id);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getID() == id)
        {
            found = 1;

            if (books[i].getStatus() == "Available")
            {
                cout << "Enter Student Name: ";
                getline(cin, name);

                cout << "Enter Due Date (YYYY-MM-DD): ";
                getline(cin, date);

                books[i].borrowBook(name, date);

                cout << "\nBook borrowed successfully.";
                cout << "\nPlease return the book by: " << date;
            }
            else
            {
                cout << "\nThis book is not available.";
            }

            break;
        }
    }

    if (found == 0)
    {
        cout << "\nBook not found.";
    }
}

// Function 5: Return a book and calculate the fee
void returnBook()
{
    string id;
    int found = 0;
    int daysLate;

    cout << "\nEnter Book ID: ";
    getline(cin, id);

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].getID() == id)
        {
            found = 1;

            if (books[i].getStatus() == "Borrowed" ||
                books[i].getStatus() == "Overdue")
            {
                cout << "Enter number of days late (0 if on time): ";
                cin >> daysLate;
                cin.ignore();

                if (daysLate < 0)
                {
                    cout << "\nInvalid number of days.";
                    return;
                }

                books[i].returnBook(daysLate);
            }
            else
            {
                cout << "\nThis book has not been borrowed.";
            }

            break;
        }
    }

    if (found == 0)
    {
        cout << "\nBook not found.";
    }
}

// Function 6: Check overdue books
void checkOverdueBooks()
{
    string today;
    int found = 0;

    cout << "\nEnter today's date (YYYY-MM-DD): ";
    getline(cin, today);

    cout << "\n===== OVERDUE BOOKS =====";

    for (int i = 0; i < bookCount; i++)
    {
        books[i].checkDueDate(today);

        if (books[i].getStatus() == "Overdue")
        {
            books[i].displayBook();
            found = 1;
        }
    }

    if (found == 0)
    {
        cout << "\nThere are no overdue books.";
    }
}
