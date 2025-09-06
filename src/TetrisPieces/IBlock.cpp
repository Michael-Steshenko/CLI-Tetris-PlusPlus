#include "IBlock.h"

IBlock::IBlock() {
    setBlockType(BlockType::I);
    coords[0] = Point(0, 3);
    coords[1] = Point(0, 4);
    coords[2] = Point(0, 5);
    coords[3] = Point(0, 6);
}