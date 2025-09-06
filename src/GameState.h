#include "config.h"
#include "TetrisPieces/TetrisBlock.h"
#include "TetrisPieces/IBlock.h"
#include "TetrisPieces/JBlock.h"
#include "TetrisPieces/LBlock.h"
#include "TetrisPieces/OBlock.h"
#include "TetrisPieces/SBlock.h"
#include "TetrisPieces/TBlock.h"
#include "TetrisPieces/ZBlock.h"
#include "CLIManager.h"
#include <iostream>
#include <chrono>
#include <memory>
#include <algorithm>
#include <random>

class GameState {
    public:

    public:
        GameState();
        void drawState();
        void drawUIBorder();
        void update();

    private:
        static const int ROWS = 22, COLS = 10;
        static const int HIDDEN_ROWS = 2;
        static const int FIRST_VISIBLE_ROW = 2;
        static const int borderLeftWidth = 1;
        static const int borderTopWidth = 1;
        const string emptyRow = " . . . . . . . . . ."; // COLS * emptySquare
        bool stateArray[ROWS][COLS] = {};
        const string emptySquare = " ."; // indicating no block
        const string fullSquare = "[]";  // indicating a block
        static const int blockWidth = 2; // in characters 
        TetrisBlock curBlock;
        TetrisBlock nextBlock;
        uint64_t lastBlockFallTime;

    
    private:
        void moveCursor(int row, int col);
        uint64_t timeSinceEpochMillisec();
        uint64_t getLastPieceFallTime();
        void updateLastBlockFallTime(uint64_t time);
        void drawCurrentBlock();
        void clearCurrentBlock();
        void drawSymbols(const array<Point, 4>& coords, const string& symbolToDraw);
        void curBlockTryFall();
        void lockInFallingBlock();
        TetrisBlock getRandomBlock();
        void getNextBlock();
    
};