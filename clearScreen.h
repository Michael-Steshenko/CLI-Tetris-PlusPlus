#include <iostream>

using namespace std;

void clearScreen() {
    // Clear the screen
    cout << "\033[2J";
    // Move cursor to home position (0, 0)
    cout << "\033[H";
    cout << flush;
}