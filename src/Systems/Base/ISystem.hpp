#pragma once
#ifndef HEADER_ISYSTEM
#define HEADER_ISYSTEM
#include <SFML/System/Time.hpp>

class ISystem
{
protected:
  static int nextID;

public:
  ISystem();
  int ID;

  virtual void update(sf::Time dt) {}
};
#endif