#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char c;
    bool Cal = true;

    cout << "Welcome to the Simple Calculator Program\n";

    while (Cal) {
        cout << "\nSelect an operation:\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (x)\n";
        cout << "4. Division (/)\n";
        cout << "Enter your choice: ";
        cin >> c;
        if (c != '+' && c != '-' && c != 'x' && c != '/') {
            cout << "Invalid operation. Please try again.\n";
            continue;
        }
        cout << "Enter your first number: ";
        cin >> num1;
        cout << "Enter your second number: ";
        cin >> num2;
        switch (c) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 'x':
                result = num1 * num2;
                cout << "Result: " << num1 << " x " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
        }
        char d;
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> d;
        if (d == 'n' || d == 'N') {
            Cal = false;
            cout << "Thank you for using the calculator. Goodbye!\n";
        }
    }

    return 0;
}

