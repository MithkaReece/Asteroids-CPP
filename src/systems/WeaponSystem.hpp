#pragma once

#include "System.hpp"

#include "../components/TransformComponent.hpp"
#include "../components/PlayerInputComponent.hpp"
#include "../components/WeaponComponent.hpp"

#include "../entities/BulletEntity.hpp"

#include "../Constants.h"

class WeaponSystem : public System
{
public:
    void update(entt::registry &registry, sf::Time dt)
    {
        auto view = registry.view<Component::Transform, Component::PlayerInput, Component::Weapon>();
        for (auto entity : view)
        {
            if (!registry.valid(entity))
            {
                continue;
            }
            Component::Transform &transform = view.get<Component::Transform>(entity);
            Component::PlayerInput &input = view.get<Component::PlayerInput>(entity);
            Component::Weapon &weapon = view.get<Component::Weapon>(entity);

            if (input.shootPressed && weapon.remainingCooldown <= sf::Time::Zero)
            {
                // Calculate forward velocity
                const float magnitude = 10.0f;
                sf::Vector2f velocity = sf::Vector2f(
                    magnitude * std::cos(transform.rotation * DEG_TO_RAD),
                    magnitude * std::sin(transform.rotation * DEG_TO_RAD));

                // Offset the position from the player
                sf::Vector2f position = transform.position;
                position += velocity;

                createBullet(registry, position, velocity, transform.rotation);

                weapon.remainingCooldown = weapon.cooldownDuration;
                input.shootPressed = false;
            }

            // Update the cooldown timer
            if (weapon.remainingCooldown > sf::Time::Zero)
                weapon.remainingCooldown -= dt;
        }
    }
};