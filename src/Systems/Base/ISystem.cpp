#include "ISystem.hpp"

ISystem::ISystem() : ID(nextID++) {}

int ISystem::nextID = 0;