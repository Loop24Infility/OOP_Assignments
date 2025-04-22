#include <iostream>
#include <unordered_map>
using namespace std;

enum Status { ON_SHELF, ON_LOAN, RESERVED };

class Book {
    int classMark;
    Status status;
public:
    Book(int cm) : classMark(cm), status(ON_SHELF) {}

    int getClassMark() const {
        return classMark;
    }

    Status getStatus() const {
        return status;
    }

    bool checkOut() {
        if (status == ON_SHELF) {
            status = ON_LOAN;
            return true;
        }
        return false;
    }

    bool reserve() {
        if (status == ON_LOAN) {
            status = RESERVED;
            return true;
        }
        return false;
    }

    string statusString() const {
        switch (status) {
            case ON_SHELF: return "On Shelf";
            case ON_LOAN: return "On Loan";
            case RESERVED: return "Reserved";
        }
        return "Unknown";
    }
};

class Library {
    unordered_map<int, Book> books;
public:
    void addBook(int classMark) {
        books[classMark] = Book(classMark);
    }

    void checkOut(int classMark) {
        if (books.count(classMark)) {
            if (books[classMark].checkOut())
                cout << "Book " << classMark << " checked out.\n";
            else
                cout << "Book " << classMark << " is not available for checkout.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    void reserve(int classMark) {
        if (books.count(classMark)) {
            if (books[classMark].reserve())
                cout << "Book " << classMark << " reserved.\n";
            else
                cout << "Book " << classMark << " cannot be reserved.\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    void inquire(int classMark) {
        if (books.count(classMark)) {
            cout << "Book " << classMark << " status: " << books[classMark].statusString() << endl;
        } else {
            cout << "Book not found.\n";
        }
    }

    void summary() {
        int total = books.size(), loan = 0, reserved = 0, shelf = 0;
        for (const auto& pair : books) {
            Status s = pair.second.getStatus();
            if (s == ON_LOAN) loan++;
            else if (s == RESERVED) reserved++;
            else if (s == ON_SHELF) shelf++;
        }
        cout << "Books in library = " << total << endl;
        cout << "Books on loan = " << loan << endl;
        cout << "Books reserved = " << reserved << endl;
        cout << "Books on shelves = " << shelf << endl;
    }
};

int main() {
    Library lib;

    for (int i = 1; i <= 100; ++i)
        lib.addBook(i);

    int choice, classMark;
    while (true) {
        cout << "\nLibrary Menu\n";
        cout << "1. Check out a book\n2. Reserve a book\n3. Inquire book status\n4. Summary\n5. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter class mark of book to check out: ";
            cin >> classMark;
            lib.checkOut(classMark);
        } else if (choice == 2) {
            cout << "Enter class mark of book to reserve: ";
            cin >> classMark;
            lib.reserve(classMark);
        } else if (choice == 3) {
            cout << "Enter class mark of book to inquire: ";
            cin >> classMark;
            lib.inquire(classMark);
        } else if (choice == 4) {
            lib.summary();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    cout << "CODE BY KSHITIJ JADHAV";
  
    return 0;
}
