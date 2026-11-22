#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title,author,bookID,status,studentName,dueDate;

public:
    Book()
    {
        title = "";
        author = "";
        bookID = "";
        status = "Available";
        studentName = "";
        dueDate = "";
    }

    void setBook(string t, string a, string id)
    {
        title = t;
        author = a;
        bookID = id;
        status = "Available";
    }

    void displayBook()
    {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << status;

        if (status == "Borrowed" || status == "Overdue")
        {
            cout << "\nStudent Name: " << studentName;
            cout << "\nDue Date: " << dueDate;
        }

        cout << "\n";
    }

    string getID()
    {
        return bookID;
    }

    string getStatus()
    {
        return status;
    }

    string getTitle()
    {
        return title;
    }

    void borrowBook(string name, string date)
    {
        studentName = name;
        dueDate = date;
        status = "Borrowed";
    }

    void returnBook(int daysLate)
    {
        double fee = daysLate * 1.00; 

        cout << "\nBook returned successfully.";

        if (daysLate > 0)
        {
            cout << "\nDays Late: " << daysLate;
            cout << "\nOverdue Fee: BZ$" << fee;
        }
        else
        {
            cout << "\nThe book was returned on time.";
            cout << "\nNo overdue fee.";
        }

        status = "Available";
        studentName = "";
        dueDate = "";
    }

    void checkDueDate(string today)
    {
        if (status == "Borrowed" && today > dueDate)
        {
            status = "Overdue";
        }
    }
};
