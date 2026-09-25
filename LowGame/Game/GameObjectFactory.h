#pragma once
#include "../stdafx.h"
#include "Definitions.h"
#include "GameObject.h"
#include "Player.h"

class GameObjectFactory
{
public:
	std::unique_ptr<GameObject> createGameObject(GameObjectType type, const sf::Vector2f& position);
	std::unique_ptr<Player> createPlayer();
};