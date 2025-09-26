#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;
    string title, author;
    bool issued;

public:
    Book() {
        id = 0;
        title = "";
        author = "";
        issued = false;
    }

    void setBook(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }

    int getId() { 
		return id;
		 }
    string getTitle() { 
	return title;
		}
    string getAuthor() {
	 return author;
	  }
    bool isIssued() {
	 return issued; 
	 }

    void issueBook() { 
	issued = true;
	 }
    void returnBook() { 
	issued = false; 
	}

    void displayBook() {
        cout << "ID: " << id
             << " | Title: " << title
             << " | Author: " << author
             << " | Status: " << (issued ? "Issued" : "Available") << endl;
    }
};

class Library {
private:
	 // Fixed size array of books
    Book books[100];  
     // Keeps track of how many books are stored
    int bookCount;  

public:
    Library() {
        bookCount = 0;
    }

    void addBook(int id, string title, string author) {
        if (bookCount < 100) {
            books[bookCount].setBook(id, title, author);
            bookCount++;
            cout << "Book added successfully!\n";
        } else {
            cout << "Library is full! Cannot add more books.\n";
        }
    }

    void showBooks() {
        if (bookCount == 0) {
            cout << "No books in library.\n";
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBook();
        }
    }

    void searchBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getId() == id) {
                books[i].displayBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void issueBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getId() == id) {
                if (!books[i].isIssued()) {
                    books[i].issueBook();
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook(int id) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getId() == id) {
                if (books[i].isIssued()) {
                    books[i].returnBook();
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    while (true) {
        cout << "\n===== Library Management System (OOP + Array) =====\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;

        case 2:
            lib.showBooks();
            break;

        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            lib.searchBook(id);
            break;

        case 4:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            lib.issueBook(id);
            break;

        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
            break;

        case 6:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}

