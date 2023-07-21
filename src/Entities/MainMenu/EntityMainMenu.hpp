#pragma once
#ifndef HEADER_ENTITY_MAIN_MENU
#define HEADER_ENTITY_MAIN_MENU
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "ComponentMenuItem.hpp"
#include "EnumMenuItemID.hpp"

void EntityMenuItem(Scene &scene, sf::RenderWindow &window, MenuItemID itemID, std::string stringText, sf::Vector2f position);

#endif