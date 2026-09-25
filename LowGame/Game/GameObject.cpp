#include "GameObject.h"


static int	m_id;

GameObject::GameObject()
	: m_position(sf::Vector2f(0.f, 0.f))
	, m_size(sf::Vector2f(0.f, 0.f))
	, m_velocity(sf::Vector2f(0.f, 0.f))
	, m_speed(0.f)
	, m_delete(false)
	, m_generator(m_randomDevice())
	, m_reocuringForceFactor(0.f)
	, m_reocuringForce(sf::Vector2f(0.f, 0.f))
	, m_scaler(1.f)
	, m_dynamicScaleFactor(0.f)
	, m_intencity(0.f)
{
	m_id++;
}

GameObject::GameObject(const sf::Vector2f& position, const sf::Vector2f& size)
	: m_position(position)
	, m_size(size)
	, m_velocity(sf::Vector2f(0.f, 0.f))
	, m_speed(0.f)
	, m_delete(false)
	, m_generator(m_randomDevice())
	, m_reocuringForceFactor(0.f)
	, m_reocuringForce(sf::Vector2f(0.f, 0.f))
	, m_scaler(1.f)
	, m_dynamicScaleFactor(0.f)
	, m_intencity(0.f)
{
	m_id++;
}

void GameObject::Update(float dt)
{
	sf::Vector2f oldPos = m_position;

	sf::Vector2f resistanceForce = -m_velocity * s_reverse_power_value;
	ApplyForce(resistanceForce, 1.0f, dt);

	if (m_reocuringForceFactor >= 0)
	{
		ApplyForce(m_reocuringForce, m_reocuringForceFactor, dt);
		m_reocuringForceFactor -= s_decrease_force_factor * dt;
	}

	
	
	
	m_position += m_velocity * dt;
	// m_intencity = abs(m_velocity.x - (m_velocity.x * s_reverse_power_value)) + abs(m_velocity.y - (m_velocity.y * s_reverse_power_value));
	sf::Vector2f deltaPos = oldPos - m_position;
	m_speed = abs(deltaPos.x) + abs(deltaPos.y);
	
	if (m_speed > 0.01f)
	{
		m_intencity = m_speed;
	}
	else
	{
		m_intencity = 0.f;
	}

	// scaler
	m_size *= m_scaler;
	if (m_scaler > 0.f)
	{
		m_scaler += m_dynamicScaleFactor * dt;
	}
	else
	{
		m_delete = true;
	}
}

void GameObject::UpdateSEC(float dt)
{
	// debug purpose for now

	
}

void GameObject::Draw(sf::RenderWindow& rw)
{

}

void GameObject::ApplyForce(sf::Vector2f force, float forceFactor, float dt)
{
	m_velocity += force * forceFactor *  dt;
}

void GameObject::ApplyReocuringForce(sf::Vector2f force, float forceFactor, float dt)
{
	m_reocuringForce = force;
	m_reocuringForceFactor = forceFactor;
	m_velocity += force * forceFactor * dt;
}

void GameObject::LiniarSizeDecrease(float scaleFactor, float dt)
{
	m_dynamicScaleFactor = scaleFactor;
	m_scaler += m_dynamicScaleFactor * dt;
}

void GameObject::SetPosition(const sf::Vector2f& position)
{
	m_position = position;
}

sf::Vector2f GameObject::GetPosition() const
{
	return m_position;
}

void GameObject::SetSize(const sf::Vector2f& size)
{
	m_size = size;
}

sf::Vector2f GameObject::GetSize() const
{
	return m_size;
}

const sf::Vector2f& GameObject::GetVelocity() const
{
	return m_velocity;
}

void GameObject::SetVelocity(const sf::Vector2f& velocity)
{
	m_velocity = velocity;
}

const float& GameObject::GetSpeed() const
{
	return m_speed;
}

float GameObject::GetRandomFloat(float min, float max)
{
	std::uniform_real_distribution<float> distribution(min, max);
	return distribution(m_generator);
}
