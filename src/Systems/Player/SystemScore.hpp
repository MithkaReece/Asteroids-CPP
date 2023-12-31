#pragma once
#ifndef HEADER_SYSTEM_SCORE
#define HEADER_SYSTEM_SCORE

#include "System.hpp"
#include "ComponentScore.hpp"
#include "ComponentScoreText.hpp"
#include <string>

class SystemScore : public System
{
public:
  SystemScore();

  void update(sf::Time dt);
};

#endif