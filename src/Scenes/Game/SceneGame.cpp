#include "SceneGame.hpp"

SceneGame::SceneGame(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : Scene(systemManager, registry, window)
{
  EntityGame(*this, windowRef.get());
}