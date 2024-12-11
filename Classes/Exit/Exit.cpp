//
// Created by kenny on 12/10/24.
//

#include "Exit.h"

Exit::Exit(int _row, int _column, const std::string &_name)
    : GamePiece(_name), row(_row), column(_column) {}

int Exit::getRow() const {
    return row;
}

int Exit::getColumn() const {
    return column;
}