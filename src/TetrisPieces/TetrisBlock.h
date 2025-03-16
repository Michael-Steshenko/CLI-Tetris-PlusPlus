#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include <utility>
#include "Point.h"
#include <array>

using namespace std;

enum BlockType {
    I = 0, // long piece
    J,     
    L,
    O,
    S,
    T,
    Z,
    END,
};

class TetrisBlock {
    private:
        BlockType type;
        bool needRedraw;

    protected:
        std::array<Point, 4> coords;
        std::array<Point, 4> prevCoords;

    protected:

    public:
        TetrisBlock();
        TetrisBlock(BlockType blockType);

        // ----- getters -----
        const Point& getCenter();
        const BlockType& getBlockType();
        array<Point, 4>& getCoords();
        array<Point, 4>& getPrevCoords();
        const bool isNeedRedraw();

        // ----- setters -----
        void setBlockType(BlockType newBlockType);
        void setNeedRedraw(bool newVal);

        // ----- logic -----
        void increaseRow();
        void decreaseRow();
        void rotate();
};

#endif