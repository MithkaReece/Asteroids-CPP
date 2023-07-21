#pragma once
#ifndef HEADER_ENTITY_LEVEL_UI
#define HEADER_ENTITY_LEVEL_UI
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "ComponentScoreText.hpp"
#include "ComponentLivesText.hpp"
#include <memory>
#include <iostream>

void EntityLevelUI(Scene &scene, sf::RenderWindow &window);
#endif