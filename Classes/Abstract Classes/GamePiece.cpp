//
// Created by kenny on 12/6/24.
//
#include "GamePiece.h"


GamePiece::~GamePiece() = default;
GamePiece::GamePiece(const std::string &_name, int _maxHealthPoints)
    : name(_name), maxHealthPoints(_maxHealthPoints), currentHealthPoints(_maxHealthPoints) {}