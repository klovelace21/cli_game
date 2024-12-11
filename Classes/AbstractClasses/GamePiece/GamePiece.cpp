//
// Created by kenny on 12/6/24.
//
#include "GamePiece.h"


GamePiece::GamePiece(const std::string &_name)
    : name(_name) {}


std::string GamePiece::getName() const { return name; }