//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
private:
  int currentHealthPoints;
  int maxHealthPoints;
  std::string name;
public:
  Player(std::string _name, int _maxHealthPoints);
  int getHealthPoints();
  void takeDamage(int _damage);
  void restoreHealthPoints(int _toRestore);
  std::string getName();
};



#endif //PLAYER_H
