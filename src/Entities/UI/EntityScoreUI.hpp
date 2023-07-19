#pragma once
#ifndef HEADER_ENTITY_SCORE_UI
#define HEADER_ENTITY_SCORE_UI
#include <entt/entt.hpp>

#include "ComponentTransform.hpp"
#include "TextUI.hpp"
#include "ScoreTag.hpp"

#include "Scene.hpp"

#include <SFML/Graphics.hpp>

/**
 * @brief Create a score UI entity with the specified components.
 *
 * @param registry The entity registry.
 */
void entityScoreUI(Scene &scene);
#endif