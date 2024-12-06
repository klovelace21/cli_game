//
// Created by kenny on 12/6/24.
//
#ifndef ENCOUNTER_H
#define ENCOUNTER_H



class Encounter {
private:
  std::string name{};
  int health;
public:
  // placeholder until design decision
  Encounter(const std::string &_name, int health);
  std::string getName();
};

#endif //ENCOUNTER_H
