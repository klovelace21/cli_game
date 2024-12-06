//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
private:
  int currentHealthPoints;
  int maxHealthPoints;
public:
  Player(int _maxHealthPoints);
  int getHealthPoints();
  void takeDamage(int _damage);
  void restoreHealthPoints(int _toRestore);
};



#endif //PLAYER_H
