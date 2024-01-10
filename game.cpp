#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getUserChoice() {
    int choice;
    cout << "Enter 1 for Rock, 2 for Paper, or 3 for Scissors: ";
    cin >> choice;
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please enter 1 for Rock, 2 for Paper, or 3 for Scissors: ";
        cin >> choice;
    }
    return choice;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

void determineWinner(int userChoice, int computerChoice) {
    cout << "You chose ";
    if (userChoice == 1) {
        cout << "Rock.";
    } else if (userChoice == 2) {
        cout << "Paper.";
    } else {
        cout << "Scissors.";
    }

    cout << " Computer chose ";
    if (computerChoice == 1) {
        cout << "Rock.";
    } else if (computerChoice == 2) {
        cout << "Paper.";
    } else {
        cout << "Scissors.";
    }

    if (userChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    cout << "Welcome to Rock, Paper, Scissors!\n";

    do {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();
        determineWinner(userChoice, computerChoice);

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing. Goodbye!\n";
            break;
        }
    } while (true);

    return 0;
}
