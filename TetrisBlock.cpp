#include "TetrisBlock.h"
#include <stdexcept>

TetrisBlock::TetrisBlock() {
    Point center = Point(0,0);
    BlockType blockType = BlockType::I;
    setBlockType(blockType);
    needRedraw = true;
}

TetrisBlock::TetrisBlock(BlockType blockType) {
    Point center = Point(0,0);
    setBlockType(blockType);
};

// ----- getters -----

BlockType& TetrisBlock::getBlockType() {
    return type;
}

array<Point, 4>& TetrisBlock::getCoords() {
    return coords;
}

array<Point, 4>& TetrisBlock::getPrevCoords() {
    return prevCoords;
}

bool TetrisBlock::isNeedRedraw() {
    return needRedraw;
}

// ----- setters -----

void TetrisBlock::setBlockType(BlockType& newBlockType) {
    type = newBlockType;
}

void TetrisBlock::setNeedRedraw(bool newVal) {
    needRedraw = newVal;
}

// ----- logic -----
void TetrisBlock::rotate() {
    throw runtime_error("rotate() not implemented for this block type");
}

