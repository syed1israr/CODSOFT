#include <iostream>
using namespace std;

int main() {
    cout << "Enter two numbers and an arithmetic operator (+, -, *, /)." << endl;
    
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b; 

    char operation;
    cout << "Now, Enter the Operator (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        cout << "The addition of " << a << " and " << b << " is " << a + b;
    } else if (operation == '-') {
        cout << "The subtraction of " << a << " and " << b << " is " << a - b;
    } else if (operation == '*') {
        cout << "The multiplication of " << a << " and " << b << " is " << a * b;
    } else if (operation == '/') {
        if (b != 0) {
            cout << "The division of " << a << " and " << b << " is " << static_cast<double>(a) / b;
        } else {
            cout << "Division by 0 is not allowed.";
        }
    } else {
        cout << "Enter a valid operator (+, -, *, /)" << endl;
    }

    return 0;
}
