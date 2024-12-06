//
// Created by kenny on 12/6/24.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
private:
  int currentHealthPoints;
  int maxHealthPoints;
  int row;
  int column;
  std::string name;
public:
  Player(std::string _name, int _maxHealthPoints);
  int getCurrentHealthPoints();
  void takeDamage(int _damage);
  void restoreHealthPoints(int _toRestore);
  std::string getName();
  int* getCurrentPosition();
};



#endif //PLAYER_H
