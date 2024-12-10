#include <iostream>
#include <set>

#include "Classes/AbstractClasses/GamePiece/GamePiece.h"
#include "Classes/Player/Player.h"
#include "Classes/Enemy/Enemy.h"
#include "Classes/GameManager/GameManager.h"
#include "Classes/Ability/Ability.h"
#include "Classes/AbilityBook/AbilityBook.h"
#include "Classes/Consumable/Consumable.h"

using namespace std;


const std::string initPlayerName() {
    std::string playerName;
    cout << "What is your name? ";
    getline(cin, playerName);

    return playerName;
}


int main() {
    srand(time(nullptr));
    Player player(0,0, initPlayerName(), 100);
    cout << player.getName() << endl;
    GameManager::startTurn(&player);


    return 0;
}
