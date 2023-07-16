#pragma once

class SceneManager
{
public:
    SceneManager() : activeScene(nullptr) {}

    // Create a new scene
    void createScene()
    {
        scenes.emplace_back(std::make_unique<Scene>());
    }

    // Switch to a scene by index
    void switchToScene(size_t index)
    {
        if (index < scenes.size())
        {
            // Clear the registry of the previous scene
            registry.clear();

            // Set the active scene to the specified index
            activeScene = scenes[index].get();

            // Initialize the new scene
            activeScene->initialize(registry);
        }
    }

    // Update the active scene
    void updateActiveScene(float dt)
    {
        if (activeScene)
        {
            activeScene->update(registry, dt);
        }
    }

private:
    entt::registry registry;
    std::vector<std::unique_ptr<Scene>> scenes;
    Scene* activeScene;
};