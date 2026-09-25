#include "Player.h"

Player::Player()
{
	// fake data

	sf::Vector2f position(50.f, 50.f);
	sf::Vector2f size(s_player_size);

	m_rect.setSize(size);
	m_rect.setPosition(position);

	GameObject::GameObject(position, size);

	m_rect.setFillColor(sf::Color::Blue);
	m_activateParticles = false;
	m_particleCD = 0.f;

	// fake data
}

Player::Player(const sf::Vector2f& position)
{
	// fake data
	sf::Vector2f size(s_player_size);

	m_rect.setSize(size);
	m_rect.setPosition(position);

	GameObject::GameObject(position, size);

	m_rect.setFillColor(sf::Color::Blue);
	m_activateParticles = false;
	m_particleCD = s_particle_cd * 0.5f;
	// fake data
}

void Player::Update(float dt)
{
	m_rect.setPosition(GetPosition() - (s_player_size * 0.5f));
	GameObject::Update(dt);
	
	// particle generator
	if (m_intencity > 0)
	{
		m_particleCD = m_intencity;
		if (m_particleCD > s_particle_cd)
		{
			m_particleCD = 0.f;
			m_activateParticles = true;
		}
		else
		{
			m_activateParticles = false;
		}
	}
	else
	{
		m_activateParticles = false;
	}
	if (m_intencity > 0.f)
	{
		std::cout << m_intencity << std::endl;
	}
	m_particleCD += dt;
}

void Player::UpdateSEC(float dt)
{
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(m_rect);
	GameObject::Draw(window);
}

const bool& Player::ActivateParticles(sf::Vector2f& position) const
{
	position = GetPosition();
	return m_activateParticles;
}
