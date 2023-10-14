// Constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H

constexpr const float DEG_TO_RAD = 3.14159f / 180.0f; // Conversion factor from degrees to radians

constexpr const float SCALE_VARIATION = 0.3f; // Noise Variation factor. Use when determining distance of points of center of an asteroid.
constexpr const float MAX_SCALE = 60.0f;      // Maximum scale value of an asteroid
constexpr const float BOUNDARY = 120.0f;      // Boundary value - used for out of boundary and wrapping asteroids

constexpr const float ASTEROID_SPLIT_ANGLE = 30.0f; // Angle asteroids halves will change when separating

#endif // CONSTANTS_H