#include "EntityManager.hpp"

EntityManager::EntityManager() :
	nextEntityID(0)
{
}

EntityManager::~EntityManager()
{
}

int EntityManager::createEntity()
{
	int entityID = nextEntityID++;
	// Add default component data for the entity
	componentData.emplace_back(); //same as push_back but does not need a temporary to copy
	return entityID;
}

void EntityManager::destroyEntity(int entityID)
{
	if (entityID >= componentData.size())
	{
		return;
	}
	// Remove component data associated with the entity
	componentData.erase(componentData.begin() + entityID);
}

template <typename Component>
void EntityManager::addComponent(int entityID, const Component& component)
{
	if (entityID >= componentData.size())
	{
		return;
	}
	// Serialize and store the component data for the entity
	componentData[entityID].push_back(reinterpret_cast<const char*>(&component), sizeof(Component));
}

template <typename Component>
void EntityManager::removeComponent(int entityID)
{
	if (entityID >= componentData.size())
	{
		return;
	}
	// Remove all components data associated with the entity
	componentData[entityID].clear();
}

template <typename Component>
Component* EntityManager::getComponent(int entityID)
{
	if (entityID >= componentData.size())
	{
		return nullptr;
	}
	if (componentData[entityID].empty())
	{
		return nullptr;
	}
	// Retrieve and return the component data for the entity
	return reinterpret_cast<Component*>(&componentData[entityID][0]);
}

template <typename Component>
bool EntityManager::hasComponent(int entityID)
{
	if (entityID >= componentData.size())
	{
		return false;
	}
	// Check if the entity has the specified component
	return !componentData[entityID].empty();
}