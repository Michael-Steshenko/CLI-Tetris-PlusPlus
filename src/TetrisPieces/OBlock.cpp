#include "OBlock.h"

OBlock::OBlock() {
    setBlockType(BlockType::O);
    coords[0] = Point(0, 4);
    coords[1] = Point(0, 5);
    coords[2] = Point(1, 4);
    coords[3] = Point(1, 5);
}