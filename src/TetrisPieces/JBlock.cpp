#include "JBlock.h"

JBlock::JBlock() {
    setBlockType(BlockType::J);
    coords[0] = Point(0, 8);
    coords[1] = Point(0, 10);
    coords[2] = Point(0, 12);
    coords[3] = Point(1, 12);
}