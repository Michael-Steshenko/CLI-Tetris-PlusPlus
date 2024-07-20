#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include "clearScreen.h"
#include "GameState.h"

using namespace std::literals::chrono_literals;

int main() {
    std::setlocale(LC_ALL, "en_US.UTF-8");
    clearScreen();

    GameState gameState = GameState();
    gameState.drawUIBorder();

    while (true) {
        cout << "\033[H"; // Move the cursor to the top left corner
        gameState.update();
        gameState.drawState();
        this_thread::sleep_for(17ms);
    }
    return 0;
}

