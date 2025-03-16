#include "SBlock.h"

SBlock::SBlock() {
    setBlockType(BlockType::S);
    coords[0] = Point(0, 10);
    coords[1] = Point(0, 12);
    coords[2] = Point(1, 8);
    coords[3] = Point(1, 10);
}