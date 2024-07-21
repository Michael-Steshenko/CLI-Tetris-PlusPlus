#include "LBlock.h"

LBlock::LBlock() {
    BlockType newBlockType = BlockType::L;
    setBlockType(newBlockType);
    coords[0] = Point(0, 6);
    coords[1] = Point(0, 8);
    coords[2] = Point(0, 10);
    coords[3] = Point(0, 12);

    prevCoords[0] = Point(0, 6);
    prevCoords[1] = Point(0, 8);
    prevCoords[2] = Point(0, 10);
    prevCoords[3] = Point(0, 12);
}

void LBlock::rotate() {

}