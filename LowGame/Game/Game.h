#pragma once
#include "../stdafx.h"
#include "InputController.h"
#include "Definitions.h"
#include "GameObjectFactory.h"
// temporary
#include "Player.h"

class Game
{
public:
	Game();
	
	void Update();
	void Draw();
	float GetRandomFloat(float min, float max);

private:
	void Update(float dt);
	void UpdateSEC(float dt);

	void OnLeftBtnPressed(sf::Vector2i vi);
	void OnMouseMoved(sf::Vector2i vi);
	void OnLeftBtnReleased(sf::Vector2i vi);

private:
	sf::Clock			m_clock;
	sf::RenderWindow	m_window;
	InputController		m_inputController;
	
	// utility stuff
	float				m_timerSEC;
	GameObjectFactory	m_gameObjectFactory;
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	
	// temporary
	std::unique_ptr<Player>						m_player;
	std::vector<std::unique_ptr<GameObject>>	m_particles;

	std::random_device m_randomDevice;
	std::mt19937 m_generator;
};
