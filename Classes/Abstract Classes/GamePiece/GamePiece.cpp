//
// Created by kenny on 12/6/24.
//
#include "GamePiece.h"


GamePiece::~GamePiece() = default;

GamePiece::GamePiece() = default;

GamePiece::GamePiece(int _row, int _column, const std::string &_name)
    : row(_row), column(_column), name(_name) {}

GamePiece::GamePiece(const std::string &_name) : name(_name) {}

int GamePiece::getRow() const { return row; }

int GamePiece::getColumn() const { return column; }

std::string GamePiece::getName() const { return name; }