#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame() {
    srand(time(nullptr)); 
    int random = rand() % 100 + 1;
    int guess = 0;
    int a = 0;

    cout << "=============================\n";
    cout << "      Number Guessing Game   \n";
    cout << "=============================\n";
    cout << "I have generated a number between 1 and 100. Can you guess it?\n";

    while (true) {
        cout << "Enter your guess: ";
        while (!(cin >> guess)) {
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Invalid input! Please enter a numeric value.\n";
            cout << "Enter your guess: "; 
        }

        a++; 

        if (guess < random) {
            cout << "Too low! Try again.\n";
        } else if (guess > random) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You've guessed the number in " << a << " attempts.\n";
            break;
        }

        char c;
        cout << "Do you want to continue guessing? (y/n): ";
        cin >> c;

        if (c == 'n' || c == 'N') {
            cout << "You chose to leave the game. The correct number was " << random << ".\n";
            break;
        }
    }
}

int main() {
    char choice;

    do {
        playGame();
        cout << "Do you want to play a new game? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
