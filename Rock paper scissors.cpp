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
        return "tie";
    }
    else if ((player == "rock" && computer == "scissors") ||
             (player == "paper" && computer == "rock") ||
             (player == "scissors" && computer == "paper")) {
        return "player";
    }
    else {
        return "computer";
    }
}

int main() {
    srand(time(0)); // seed random number

    int tries = 0;
    int playerScore = 0, computerScore = 0, ties = 0;

    while (tries < 3) {
        string playerChoice;
        cout << "\nRound " << tries + 1 << " of 3" << endl;
        cout << "Enter your choice (rock, paper, scissors): ";
        cin >> playerChoice;

        string computerChoice = getComputerChoice();

        cout << "You chose: " << playerChoice << endl;
        cout << "Computer chose: " << computerChoice << endl;

        string winner = checkWinner(playerChoice, computerChoice);

        if (winner == "player") {
            cout << "You win this round!" << endl;
            playerScore++;
        }
        else if (winner == "computer") {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        }
        else {
            cout << "This round is a tie!" << endl;
            ties++;
        }

        tries++;
    }

    // Final Result
    cout << "\n===== Final Result =====" << endl;
    cout << "Your score: " << playerScore << endl;
    cout << "Computer score: " << computerScore << endl;
    cout << "Ties: " << ties << endl;

    if (playerScore > computerScore) {
        cout << "?? You are the overall winner!" << endl;
    }
    else if (computerScore > playerScore) {
        cout << "?? Computer is the overall winner!" << endl;
    }
    else {
        cout << "?? The game is a tie overall!" << endl;
    }

    cout << "\nGame Over! Thanks for playing." << endl;

    return 0;
}
