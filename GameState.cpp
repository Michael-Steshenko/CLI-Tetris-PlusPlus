#include "GameState.h"
#include <algorithm>


GameState::GameState() {
    hideCursor();
    //LBlock newBlock = LBlock();
    currentBlock = new LBlock();

    updateLastBlockFallTime(timeSinceEpochMillisec());

/*     stateArray[5][5] = true;
    stateArray[4][4] = true; */
}

void GameState::update() {
    uint64_t curTime = timeSinceEpochMillisec();
    
    // if a second passed set the new block coordinates and remember the coordinates to clear
    if (curTime  - lastBlockFallTime > 1000 ) {
        updateLastBlockFallTime(curTime);
        currentBlock->setNeedRedraw(true);
        
        // create a deep copy of current block coords and assign them to prevCoords
        array<Point, 4> currentBlockCoordsCopy = currentBlock->getCoords();
        currentBlock->getPrevCoords() = currentBlockCoordsCopy;
        
        currentBlock->increaseRow();
    }
}

void GameState::drawState() {
    /*moveCursor(2, 2);
     for (int row = FIRST_VISIBLE_ROW; row < ROWS; row++) {
        moveCursor(row + FIRST_VISIBLE_ROW, 2);
        for (int col = 0; col < COLS; col++) {
            if(stateArray[row][col]) {
                cout << fullSquare;
            } else {
                cout << emptySquare;
            }
        }
    } */
    drawCurrentBlock();
}

// clears current block from screen without checks
void GameState::clearCurrentBlock() {
    array<Point, 4>& prevBlockCoords = currentBlock->getPrevCoords();
    drawSymbols(prevBlockCoords, emptySquare);
}

// draws current block if it needs a redraw and clears previous position
void GameState::drawCurrentBlock() {
    if (!currentBlock->isNeedRedraw()) {
        return;
    }
    clearCurrentBlock();
    array<Point, 4>& currentBlockCoords = currentBlock->getCoords();
    drawSymbols(currentBlockCoords, fullSquare);
    currentBlock->setNeedRedraw(false);
    cout << flush;
}

// draws symbolToDraw, at the board positions indicated by coords
void GameState::drawSymbols(const array<Point, 4>& coords, const string& symbolToDraw) {
    for (Point point : coords) {
        if (point.getRow() < HIDDEN_ROWS) {
            continue;
        }
        moveCursor(point.getRow() + 2, point.getCol() + 2);
        cout << symbolToDraw;
    }
}

void GameState::drawUIBorder() {
    // draws all the static elements of the game, border, static text etc.
    moveCursor(1, 1);
    cout << "┌────────────────────┐" << endl;
    for (int row = 0; row < ROWS; row++) {
        //moveCursor(row + 1, 0);
        cout << "|" << emptyRow << "|" << endl;
    }
    //moveCursor(rows, 0);
    cout << "└────────────────────┘" << endl;
}

// top left is considered 1, 1
void GameState::moveCursor(int row, int column) {
    string moveString = "\033[" + to_string(row) +";" + to_string(column) + "H";
    cout << moveString;
}

uint64_t GameState::timeSinceEpochMillisec() {
  using namespace chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

uint64_t GameState::getLastPieceFallTime() {
    return lastBlockFallTime;
}

void GameState::updateLastBlockFallTime(uint64_t time) {
    lastBlockFallTime = time;
}