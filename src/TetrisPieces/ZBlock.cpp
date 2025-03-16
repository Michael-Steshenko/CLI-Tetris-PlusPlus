#include "ZBlock.h"

ZBlock::ZBlock() {
    setBlockType(BlockType::Z);
    coords[0] = Point(0, 8);
    coords[1] = Point(0, 10);
    coords[2] = Point(1, 10);
    coords[3] = Point(1, 12);
}