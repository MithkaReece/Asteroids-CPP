#pragma once

#include <entt/entt.hpp>
#include "Scene0.hpp"

class SceneManager
{
private:
    std::reference_wrapper<entt::registry> registry;
    std::vector<std::unique_ptr<Scene>> scenes;
    int currentSceneIndex;

public:
    SceneManager(entt::registry &registry, int startingSceneIndex) : registry(registry)
    {
        // Add scenes that exist
        scenes.emplace_back(std::make_unique<Scene0>());

        switchToScene(startingSceneIndex);
    }

    // Switch to a scene by index
    void switchToScene(int sceneIndex)
    {
        // Valid scene index
        assert(sceneIndex >= 0 && sceneIndex < scenes.size());
        // Clear and init scene
        registry.get().clear();
        currentSceneIndex = sceneIndex;
        scenes[currentSceneIndex]->init(registry.get());
    }
};