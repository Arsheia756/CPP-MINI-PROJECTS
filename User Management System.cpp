#include<iostream>
#include<string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    // Welcome screen
    void welcome() {
        cout << "=====================================================\n";
        cout << "       ?? WELCOME TO THE USER MANAGEMENT SYSTEM ??      \n";
        cout << "=====================================================\n";
        cout << "Register, Login, or Retrieve your password with ease!\n";
        cout << "-----------------------------------------------------\n";
    }

    // Register new user
    void registeruser() {
        cout << "\n?? Register Yourself\n";
        cin.ignore(); // clear input buffer
        cout << "?? Enter username: ";
        getline(cin, username);
        cout << "?? Enter password: ";
        getline(cin, password);
        cout << "\n? Registration Successful! You can now login.\n";
    }

    // Login registered user
    void loginuser() {
        string user, pass;
        cout << "\n?? User Login\n";
        cin.ignore();
        cout << "?? Username: ";
        getline(cin, user);
        cout << "?? Password: ";
        getline(cin, pass);
        
	//check credentials
        if (user == username && pass == password) {
            cout << "\n? Login Successful! Welcome back, " << user << "!\n";
        } else {
            cout << "\n? Invalid username or password. Try again.\n";
        }
    }

    // Forgot password functionality
    void forgotpassword() {
        string user;
        cout << "\n? Forgot Password\n";
        cin.ignore();
        cout << "?? Enter your username: ";
        getline(cin, user);

        if (user == username) {
            cout << "\n?? Your password is: " << password << "\n";
        } else {
            cout << "\n? Username not found. Please register first.\n";
        }
    }
};

int main() {
    User userobj;
    int choice;

    userobj.welcome();

    do {
        cout << "\n========================= MENU =========================\n";
        cout << "1??  Register User\n";
        cout << "2??  Login User\n";
        cout << "3??  Forgot Password\n";
        cout << "4??  Exit Program\n";
        cout << "========================================================\n";
        cout << "?? Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
            userobj.registeruser();
            break;
        case 2:
            userobj.loginuser();
            break;
        case 3:
            userobj.forgotpassword();
            break;
        case 4:
            cout << "\n?? Exiting Program. Thank you for using our system!\n";
            break;
        default:
            cout << "\n?? Invalid input! Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

