#pragma once

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <functional>
#include "systems/Render.hpp"

#include "scenes/SceneIManager.hpp"
#include "scenes/Scene.hpp"
#include "scenes/Level.hpp"

namespace Scene
{
  /**
   * @brief Class for managing scenes and switching between them.
   */
  class Manager : public IManager
  {
  private:
    std::vector<std::unique_ptr<Scene>> scenes; // Vector of unique pointers to all scenes
    std::unique_ptr<System::Render> render;

  public:
    /**
     * @brief Constructs a SceneManager object and switches to a given scene.
     *
     * @param registry The entity registry.
     * @param window The SFML render window.
     * @param startingSceneIndex The index of the starting scene.
     */
    Manager(entt::registry &registry, sf::RenderWindow &window);

    template <typename SceneType>
    void addScene();

    template <typename SceneType>
    void removeScene();

    void updateSystems(sf::Time dt);

    void updateRenderSystem(sf::Time dt);

    entt::registry &getRegistry();

    sf::RenderWindow &getWindow();

  private:
    // Sort scenes based on precedence
    void sortScenesByPrecedence();
  };
}