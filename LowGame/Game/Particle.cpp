#include "Particle.h"

Particle::Particle()
{
	sf::Vector2f position(150.f, 150.f);
	
	m_rect.setSize(s_particle_size);
	m_rect.setPosition(position);

	GameObject::GameObject(position, s_particle_size);

	m_rect.setFillColor(sf::Color::Red);
	
	m_lifeTime = 0.f;
}

Particle::Particle(const sf::Vector2f& position)
	: GameObject(position, s_particle_size)
{
	m_rect.setSize(s_particle_size);
	m_rect.setPosition(position);

	m_rect.setFillColor(sf::Color::Red);

	m_lifeTime = 0.f;
}

void Particle::Update(float dt)
{
	GameObject::Update(dt);
	m_lifeTime += dt;
	if (m_lifeTime > s_particle_life_time)
	{
		m_delete = true;
	}
	m_rect.setPosition(GetPosition());
	m_rect.setSize(GetSize());
}

void Particle::Draw(sf::RenderWindow& window)
{
	window.draw(m_rect);
	GameObject::Draw(window);
}

