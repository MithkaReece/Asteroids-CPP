#pragma once

#include <vector>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	int createEntity();
	void destroyEntity(int entityID);

	template <typename Component>
	void addComponent(int entityID, const Component& component);

	template <typename Component>
	void removeComponent(int entityID);

	template <typename Component>
	Component* getComponent(int entityID);

	template <typename Component>
	bool hasComponent(int entityID);

private:
	int nextEntityID;
	std::vector<std::vector<char>> componentData;
};
