#include "SBlock.h"

SBlock::SBlock() {
    setBlockType(BlockType::S);
    coords[0] = Point(0, 5);
    coords[1] = Point(0, 6);
    coords[2] = Point(1, 4);
    coords[3] = Point(1, 5);
}