#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;
int main() {
    srand(time(0));
    int Number = rand() % 50 + 1;
    int Guess;
    cout << "Number Guessing Game between 1-50!" << endl;
    bool gaming_Ended = false;

    while (!gaming_Ended) {
        cout << "Enter Your Guess please: ";
        cin >> Guess;
        if (Guess < Number) {
            cout << "You Guessed Lower!" << endl;
        } else if (Guess > Number) {
            cout << "You Guessed Higher!" << endl;
        } else {
            cout << "Congratulations! You guessed The number: " << Number << endl;
            gaming_Ended = true;
        }
    }
    return 0;
}
