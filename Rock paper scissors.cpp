#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getComputerChoice() {
    string options[3] = {"rock", "paper", "scissors"};
    int randomIndex = rand() % 3;
    return options[randomIndex];
}

string checkWinner(string player, string computer) {
    if (player == computer) {
        return "It's a tie!";
    }
    else if ((player == "rock" && computer == "scissors") ||
             (player == "paper" && computer == "rock") ||
             (player == "scissors" && computer == "paper")) {
        return "You win!";
    }
    else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0)); // seed random number

    string playerChoice;
    cout << "Enter your choice (rock, paper, scissors): ";
    cin >> playerChoice;

    string computerChoice = getComputerChoice();

    cout << "You chose: " << playerChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;
    cout << checkWinner(playerChoice, computerChoice) << endl;

    return 0;
}
