#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include <entt/entt.hpp>

#include "systems/SystemManager.hpp"

namespace Scene
{
  /**
   * @brief Base class for scenes in an ECS (entt) and SFML project.
   * Scenes represent different states or levels in the game.
   */
  class Scene
  {
  protected:
    std::unordered_set<entt::entity> createdEntities;
    std::reference_wrapper<System::Manager> systemManagerRef;

  public:
    std::reference_wrapper<entt::registry> registryRef;
    std::reference_wrapper<sf::RenderWindow> windowRef;

    virtual int precedence();

    Scene(System::Manager &systemManager, entt::registry &registry, sf::RenderWindow &window);
    virtual ~Scene();
    /**
     * @brief Updates all the systems in the scene.
     *
     * @param registry The entt::registry containing the game entities.
     * @param dt The time delta for the update.
     */
    void updateSystems(sf::Time dt);

    entt::entity create();

    // Templated method to add a component to an entity in the scene
    template <typename ComponentType, typename... Args>
    void emplace(entt::entity entity, Args &&...args)
    {
      registryRef.get().emplace<ComponentType>(entity, std::forward<Args>(args)...);
    }

    // TODO Setup systems somewhere else
    template <typename SystemType, typename... Args>
    void addSystem(Args &&...args)
    {
      // systems.push_back(std::make_unique<SystemType>(sceneManagerRef.get(), *this, std::forward<Args>(args)...));
    }
  };
}