#include "SceneLevelUI.hpp"

SceneLevelUI::SceneLevelUI(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : Scene(systemManager, registry, window)
{
  EntityLevelUI(*this, windowRef.get());

  addSystem<SystemScore>();
  addSystem<SystemLives>();
}
