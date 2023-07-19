#include "SceneGameUI.hpp"

SceneGameUI::SceneGameUI(SystemManager &systemManager, entt::registry &registry, sf::RenderWindow &window)
    : Scene(systemManager, registry, window)
{
  entityLevelUI(*this, windowRef.get());
}


