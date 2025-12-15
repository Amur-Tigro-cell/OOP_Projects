#include <iostream>
using namespace std;

int main() {
    int score = 0;
    char answer;

    cout << "===== QUIZ APPLICATION =====\n\n";

    cout << "Q1. C++ is a ?\n";
    cout << "a) Compiler\nb) Language\nc) Editor\nd) OS\n";
    cin >> answer;
    if (answer == 'b' || answer == 'B') score++;

    cout << "\nQ2. Which symbol is used for comments in C++?\n";
    cout << "a) //\nb) ##\nc) **\nd) $$\n";
    cin >> answer;
    if (answer == 'a' || answer == 'A') score++;

    cout << "\nQ3. Which loop is entry-controlled?\n";
    cout << "a) do-while\nb) while\nc) for\nd) both b and c\n";
    cin >> answer;
    if (answer == 'd' || answer == 'D') score++;

    cout << "\nQ4. Which header file is used for input/output?\n";
    cout << "a) stdio.h\nb) conio.h\nc) iostream\nd) stdlib.h\n";
    cin >> answer;
    if (answer == 'c' || answer == 'C') score++;

    cout << "\nQ5. Which OOP concept is used for reusability?\n";
    cout << "a) Polymorphism\nb) Inheritance\nc) Encapsulation\nd) Abstraction\n";
    cin >> answer;
    if (answer == 'b' || answer == 'B') score++;

    cout << "\n===== RESULT =====\n";
    cout << "Your Score: " << score << "/5\n";

    if (score >= 3)
        cout << "🎉 You Passed!\n";
    else
        cout << "❌ You Failed!\n";

    return 0;
}
