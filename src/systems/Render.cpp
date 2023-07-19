#include "systems/Render.hpp"

namespace System
{
  Render::Render(std::reference_wrapper<Scene::IManager> sceneManager)
      : sceneManagerRef(sceneManager)
  {
  }

  void Render::update(sf::Time dt)
  {
    sf::RenderWindow &window = sceneManagerRef.get().windowRef.get();
    entt::registry &registry = sceneManagerRef.get().registryRef.get();

    auto view = registry.view<Component::Render, Component::Transform>();

    for (auto entity : view)
    {
      if (!registry.valid(entity))
        continue;

      Component::Render &render = view.get<Component::Render>(entity);
      Component::Transform &transform = view.get<Component::Transform>(entity);

      // Render the entity using the render and transform components
      sf::Drawable *drawable = render.drawable.get();
      assert(drawable != nullptr && "Drawable is null!");

      sf::Transform sfTransform;
      sfTransform.translate(transform.position);
      sfTransform.scale(transform.scale);
      sfTransform.rotate(transform.rotation);
      window.draw(*drawable, sfTransform); // Draw the drawable object to the window
    }

    // Render UI elements
    auto viewUI = registry.view<Component::Transform, Component::TextUI, Component::ScoreTag>();

    for (auto entity : viewUI)
    {
      if (!registry.valid(entity))
        continue;

      Component::Transform &transform = viewUI.get<Component::Transform>(entity);
      Component::TextUI &textUI = viewUI.get<Component::TextUI>(entity);
      // Render the UI element
      sf::Text scoreText;
      scoreText.setFont(textUI.font);
      scoreText.setString(textUI.text);
      scoreText.setCharacterSize(25);
      scoreText.setPosition(window.getSize().x * transform.position.x, window.getSize().y * transform.position.y);
      scoreText.setFillColor(textUI.color);
      window.draw(scoreText);
    }
  }
}

/*
namespace System
{
  Render::Render(std::reference_wrapper<Scene::Manager> sceneManager)
      : System::System(sceneManager) {}

  void Render::update(sf::Time dt)
  { TODO
     sf::RenderWindow &window = sceneManagerRef.get().windowRef.get();
     entt::registry &registry = sceneManagerRef.get().registryRef.get();

     auto view = registry.view<Component::Render, Component::Transform>();

     for (auto entity : view)
     {
       if (!registry.valid(entity))
         continue;

       Component::Render &render = view.get<Component::Render>(entity);
       Component::Transform &transform = view.get<Component::Transform>(entity);

       // Render the entity using the render and transform components
       sf::Drawable *drawable = render.drawable.get();
       assert(drawable != nullptr && "Drawable is null!");

       sf::Transform sfTransform;
       sfTransform.translate(transform.position);
       sfTransform.scale(transform.scale);
       sfTransform.rotate(transform.rotation);
       window.draw(*drawable, sfTransform); // Draw the drawable object to the window
  }

  // Render UI elements
  auto viewUI = registry.view<Component::Transform, Component::TextUI, Component::ScoreTag>();

  for (auto entity : viewUI)
  {
    if (!registry.valid(entity))
      continue;

    Component::Transform &transform = viewUI.get<Component::Transform>(entity);
    Component::TextUI &textUI = viewUI.get<Component::TextUI>(entity);
    // Render the UI element
    sf::Text scoreText;
    scoreText.setFont(textUI.font);
    scoreText.setString(textUI.text);
    scoreText.setCharacterSize(25);
    scoreText.setPosition(window.getSize().x * transform.position.x, window.getSize().y * transform.position.y);
    scoreText.setFillColor(textUI.color);
    window.draw(scoreText);
  }
  }
}
*/