#pragma once

#include <SFML/System/Time.hpp>

namespace System
{
  class ISystem
  {
  public:
    int ID;

    virtual void update(sf::Time dt) {}
  };
}