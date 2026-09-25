#include "GameObjectFactory.h"
#include "Particle.h"

std::unique_ptr<GameObject> GameObjectFactory::createGameObject(GameObjectType type, const sf::Vector2f& position)
{
	switch (type)
	{
		case GameObjectType::PLAYER:
			return std::make_unique<Player>(position);
		case GameObjectType::PARTICLE:
			return std::make_unique<Particle>(position);

	}

	return nullptr;
}

std::unique_ptr<Player> GameObjectFactory::createPlayer()
{
	return std::make_unique<Player>();
}
