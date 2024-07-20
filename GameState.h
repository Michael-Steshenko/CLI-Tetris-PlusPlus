#include "TetrisBlock.h"
#include "LBlock.h"
#include <iostream>
#include <chrono>
#include <memory>

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
        string emptyRow = "                    "; // ROWS * emptySquare
        bool stateArray[ROWS][COLS] = {};
        string emptySquare = "  "; // indicating no block
        string fullSquare = "[]";  // indicating a block
        TetrisBlock* currentBlock;
        TetrisBlock* nextBlock;
        uint64_t lastBlockFallTime;

    
    private:
        void moveCursor(int row, int col);
        void hideCursor();
        uint64_t timeSinceEpochMillisec();
        uint64_t getLastPieceFallTime();
        void updateLastBlockFallTime(uint64_t time);
        void drawCurrentBlock();
        void clearCurrentBlock();
        void drawSymbols(const array<Point, 4>& coords, const string& symbolToDraw);

    private:

    


};