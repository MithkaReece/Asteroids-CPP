#pragma once
#ifndef HEADER_ENTITY_MAIN_MENU
#define HEADER_ENTITY_MAIN_MENU
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "ComponentMenuItem.hpp"
#include "ResourceManager.hpp"

#include "GlobalObjects.hpp"

void EntityMenuItem(Scene &scene, std::string buttonText,
                    sf::Vector2f position, sf::Vector2f outerborderRatio, OnClickFunc onClickFunc);

#endif