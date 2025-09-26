#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string words[] = {"computer", "programming", "science", "network", "keyboard"};
    int n = 5;

    srand(time(0)); 
    string word = words[rand() % n];

    string guessed(word.size(), '_');
    int lives = 6;

    cout << "=== Hangman Game ===" << endl;

    while (lives > 0 && guessed != word) {
        cout << "\nWord: " << guessed << endl;
        cout << "Lives left: " << lives << endl;

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        bool correct = false;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct = true;
            }
        }

        if (correct) {
            cout << "Good guess!" << endl;
        } else {
            lives--;
            cout << "Wrong guess!" << endl;
        }
    }

    if (guessed == word) {
        cout << "\n Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "\n Game Over! The word was: " << word << endl;
    }

    return 0;
}

