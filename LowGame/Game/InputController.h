#pragma once
#include "../stdafx.h"

class InputController
{
public:
	InputController();

	void KeyPressed(sf::Keyboard::Scancode code);
	void KeyReleased(sf::Keyboard::Scancode code);

	void OnMouseMoved(sf::Vector2i position);
	void OnLeftBtnPressed(sf::Vector2i position);
	void OnLeftBtnReleased(sf::Vector2i position);


	sf::Vector2f GetDirection() const;
	sf::Vector2f GetRelativeDirection(sf::Vector2f position) const;
private:
	std::map<sf::Keyboard::Scancode, bool> m_keyboardStates;

	bool			m_drugging;
	sf::Vector2i	m_mousePosition;
};