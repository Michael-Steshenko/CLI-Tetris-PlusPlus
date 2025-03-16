#include "LBlock.h"

LBlock::LBlock() {
    setBlockType(BlockType::L);
    coords[0] = Point(0, 6);
    coords[1] = Point(0, 8);
    coords[2] = Point(0, 10);
    coords[3] = Point(0, 12);
}
