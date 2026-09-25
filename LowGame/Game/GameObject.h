#pragma once
#include "../stdafx.h"

class GameObject
{
public:
	GameObject();
	GameObject(const sf::Vector2f& position, const sf::Vector2f& size);
	virtual ~GameObject() = default;
	
	virtual void Update(float dt);
	virtual void UpdateSEC(float dt);
	virtual void Draw(sf::RenderWindow& rw);

	const bool& IsDead() const { return m_delete; };
	void ApplyForce(sf::Vector2f force, float forceFactor, float dt);
	void ApplyReocuringForce(sf::Vector2f force, float forceFactor, float dt);
	
	void LiniarSizeDecrease(float scaleFactor, float dt);

	const sf::Vector2f& GetVelocity() const;
	void SetVelocity(const sf::Vector2f& velocity);
	sf::Vector2f GetSize() const;
	sf::Vector2f GetPosition() const;

protected:
	void SetPosition(const sf::Vector2f& position);
	void SetSize(const sf::Vector2f& size);

	const float& GetSpeed() const;
	float GetRandomFloat(float min, float max);


	float			m_intencity;
	float			m_forceInteraction;
	
	bool			m_delete;
private:
	sf::Vector2f	m_position;
	sf::Vector2f	m_size;

	sf::Vector2f	m_force;
	sf::Vector2f	m_velocity;
	
	float				m_speed;

	sf::Vector2f m_reocuringForce;
	float m_reocuringForceFactor;
	float m_scaler;
	float m_dynamicScaleFactor;


	std::random_device m_randomDevice;
	std::mt19937 m_generator;
};