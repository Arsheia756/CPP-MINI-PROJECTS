#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    char choice;
    cout << "====================================\n";
    cout << "        NUMBER GUESSING GAME        \n";
    cout << "====================================\n\n";

    do {
        srand(time(0));  
        // random number between 1 and 100
        int secretNumber = rand() % 100 + 1;  
        int guess, attempts = 0;

        cout << "Guess the number between 1 and 100." << endl;

        while (attempts < 5) {
            cout << "Enter your guess (Attempt " << (attempts + 1) << " of 5): ";
            cin >> guess;
            attempts++;

            if (guess == secretNumber) {
                cout << "\nCongratulations! You guessed the number in " 
                     << attempts << " attempts!\n\n";
                break;
            } 
            else if (guess < secretNumber) {
                cout << "Too low! Try again.\n";
            } 
            else {
                cout << "Too high! Try again.\n";
            }

            cout << "Attempts left: " << (5 - attempts) << "\n\n";
        }

        if (guess != secretNumber) {
            cout << "Game Over! The secret number was " << secretNumber << ".\n\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "====================================\n";
    cout << " Thanks for playing!   See you soon \n";
    cout << "====================================\n";
    return 0;
}

