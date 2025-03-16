#include "GameState.h"

GameState::GameState() {
    hideCursor();
    curBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    drawUIBorder();
    drawCurrentBlock();
    updateLastBlockFallTime(timeSinceEpochMillisec());
}

void GameState::update() {
    uint64_t curTime = timeSinceEpochMillisec();
    
    // if a second passed set the new block coordinates and remember the coordinates to clear
    if (curTime  - lastBlockFallTime > 300 ) {
        updateLastBlockFallTime(curTime);
        curBlock.setNeedRedraw(true);
        
        array<Point, 4> currentBlockCoordsCopy = curBlock.getCoords();
        curBlock.getPrevCoords() = currentBlockCoordsCopy;
        curBlockTryFall();
        drawCurrentBlock();
    }
}

// try to make the current block fall, if it can fall update the row and return true, otherwise lock the block in place and return false
void GameState::curBlockTryFall() {
    curBlock.increaseRow();
    array<Point, 4>& coords = curBlock.getCoords();
    for (Point& point: coords) {
        if (point.getRow() >= ROWS) {
            lockInFallingBlock();
        } else if (stateArray[point.getRow()][point.getCol()]) {    // this is dangerous, no bound checks for col
            lockInFallingBlock();
        }
    }
}

// notice that we lock the previous position of the falling block, because if we reach here, it means we updated the current position of the falling block and it was taken.
void GameState::lockInFallingBlock() {
    array<Point, 4>& coords = curBlock.getPrevCoords();
    for (Point& point: coords) {
        stateArray[point.getRow()][point.getCol()] = true;
    }
/*     // since we're getting rid of the block, we won't get the chance to draw it later.
    drawCurrentBlock(); */
    getNextBlock();
}

TetrisBlock GameState::getRandomBlock() {
    static std::random_device rd;     // Only used once to initialise (seed) engine
    static std::mt19937 rng(rd());    // Random-number engine used (Mersenne-Twister in this case)
    static std::uniform_int_distribution<int> uni(0, BlockType::END - 1);

    BlockType blockType = BlockType(uni(rng)); // Adjust the range based on the number of block types
    switch (blockType) {
        case BlockType::I:
            return IBlock();
            break;
        case BlockType::J:
            return JBlock();
            break;
        case BlockType::L:
            return LBlock();
            break;
        case BlockType::O:
            return OBlock();
            break;
        case BlockType::S:
            return SBlock();
            break;
        case BlockType::T:
            return TBlock();
            break;
        case BlockType::Z:
            return ZBlock();
            break;
        // Add cases for other block types here
        default:
            return IBlock();
            break;
        }
}

void GameState::getNextBlock() {
    curBlock = nextBlock;
    nextBlock = getRandomBlock();
}

void GameState::drawState() {
    
/*     moveCursor(2, 2);
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
    array<Point, 4>& prevBlockCoords = curBlock.getPrevCoords();
    drawSymbols(prevBlockCoords, emptySquare);
}

// draws current block if it needs a redraw and clears previous position
void GameState::drawCurrentBlock() {
    if (!curBlock.isNeedRedraw()) {
        return;
    }
    clearCurrentBlock();
    array<Point, 4>& currentBlockCoords = curBlock.getCoords();
    drawSymbols(currentBlockCoords, fullSquare);
    curBlock.setNeedRedraw(false);
    cout << flush;
}

// draws symbolToDraw, at the board positions indicated by coords
void GameState::drawSymbols(const array<Point, 4>& coords, const string& symbolToDraw) {
    for (Point point : coords) {
        if ( !SHOW_HIDDEN_ROWS && (point.getRow() < HIDDEN_ROWS) ) {
            continue;
        }
        int rowOffset = 0;
        if (!SHOW_HIDDEN_ROWS) {
            rowOffset = HIDDEN_ROWS;
        }
        // for example, when SHOW_HIDDEN_ROWS == false, a point at 3,3, should be drawn at 1, 3
        moveCursor(point.getRow() + borderTopWidth - rowOffset, point.getCol() + borderLeftWidth);
        cout << symbolToDraw;
    }
}

void GameState::drawUIBorder() {
    int rows = ROWS;
    if (!SHOW_HIDDEN_ROWS) {
        rows = ROWS - HIDDEN_ROWS;
    }

    // draws all the static elements of the game, border, static text etc.
    moveCursor(0, 0);
    cout << "┌────────────────────┐" << endl;
    for (int row = 0; row < rows; row++) {
        cout << "|" << emptyRow << "|" << endl;
    }
    cout << "└────────────────────┘" << endl;
}

void GameState::moveCursor(int row, int column) {
    // + 1 because top left row is considered 1, 1, and we want to work with 0-index, like normal people
    string moveString = "\033[" + to_string(row + 1) +";" + to_string(column + 1) + "H";
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