#include <iostream>
#include <chrono>
#include <cstdlib>
#include <thread>
#include "CLIManager.h"
#include "GameState.h"

using namespace std::literals::chrono_literals;

#include <csignal>

// Global flag to indicate if Ctrl+C was pressed
volatile sig_atomic_t flag = 0;

// Signal handler function
void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    clearScreen();
    showCursor();
    exit(signum);
}

int main() {
    // Register signal handler for SIGINT
    signal(SIGINT, signalHandler);
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

