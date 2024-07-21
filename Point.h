#ifndef POINT_H
#define POINT_H

class Point {
    private:
        int row, col;

    public:
        Point() : row(0), col(0) {}

        Point(int row, int col) : row(row), col(col) {}

        // ----- getters -----
        const int getRow() {
            return row;
        }

        const int getCol() {
            return col;
        }

        // ----- setters -----
        void setRow(int newX) {
            row = newX;
        }

        void setCol(int newY) {
            col = newY;
        }

        void increaseRow() {
            row += 1;
        }

        void decreaseRow() {
            row -= 1;
        }
};

#endif