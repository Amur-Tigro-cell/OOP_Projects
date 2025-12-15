#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int number, guess, attempts = 5;

    srand(time(0));
    number = rand() % 100 + 1;

    cout << "===== NUMBER GUESSING GAME =====\n";
    cout << "Guess a number between 1 and 100\n";
    cout << "You have 5 attempts\n\n";

    while (attempts > 0) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == number) {
            cout << "\n🎉 Congratulations! You guessed the correct number.\n";
            return 0;
        } else if (guess > number) {
            cout << "Too High!\n";
        } else {
            cout << "Too Low!\n";
        }

        attempts--;
        cout << "Attempts left: " << attempts << "\n\n";
    }

    cout << "❌ Game Over! The number was: " << number << endl;

    return 0;
}
