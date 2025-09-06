#include "TBlock.h"

TBlock::TBlock() {
    setBlockType(BlockType::T);
    coords[0] = Point(0, 4);
    coords[1] = Point(0, 5);
    coords[2] = Point(0, 6);
    coords[3] = Point(1, 5);
}