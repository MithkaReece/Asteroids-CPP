#pragma once
#ifndef HEADER_ISYSTEM
#define HEADER_ISYSTEM
#include <SFML/System/Time.hpp>

class ISystem
{
public:
  int ID;

  virtual void update(sf::Time dt) {}
};
#endif