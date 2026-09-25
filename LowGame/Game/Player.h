#pragma once
#include "../stdafx.h"
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	Player(const sf::Vector2f& position);

	virtual void Update(float dt) override;
	virtual void UpdateSEC(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	const bool& ActivateParticles(sf::Vector2f& position) const;

private:
	sf::RectangleShape m_rect;
	bool m_activateParticles;
	float m_particleCD;
};