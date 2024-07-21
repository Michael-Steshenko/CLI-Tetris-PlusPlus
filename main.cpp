#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <csignal>
#include "CLIManager.h"
#include "GameState.h"

using namespace std::literals::chrono_literals;

// Signal handler function
void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    clearScreen();
    showCursor();
    exit(signum);
}

int main() {
    // register signal handler for SIGINT
    signal(SIGINT, signalHandler);
    std::setlocale(LC_ALL, "en_US.UTF-8");
    clearScreen();
    GameState gameState = GameState();

    while (true) {
        cout << "\033[H"; // move the cursor to the top left corner
        gameState.update();
        this_thread::sleep_for(17ms);
    }
    return 0;
}

