#pragma once
#include "../stdafx.h"
#include "GameObject.h"

class Particle : public GameObject
{
public:
	Particle();
	Particle(const sf::Vector2f& position);

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

private:
	sf::RectangleShape m_rect;
	float m_lifeTime;
};