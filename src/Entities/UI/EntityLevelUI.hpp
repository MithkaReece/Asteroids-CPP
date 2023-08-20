#pragma once
#ifndef HEADER_ENTITY_LEVEL_UI
#define HEADER_ENTITY_LEVEL_UI
#include <SFML/Graphics.hpp>
#include "Scene.hpp"
#include "ComponentText.hpp"
#include <memory>
#include <iostream>
#include "ResourceManager.hpp"

#include "GlobalObjects.hpp"

void EntityLevelUI(Scene &scene, sf::Vector2f position, std::string ID);
#endif