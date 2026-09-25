#include "InputController.h"

InputController::InputController()
	: m_drugging(false)
{

}

void InputController::KeyPressed(sf::Keyboard::Scancode code)
{
	m_keyboardStates[code] = true;
}

void InputController::KeyReleased(sf::Keyboard::Scancode code)
{
	m_keyboardStates[code] = false;
}

void InputController::OnMouseMoved(sf::Vector2i position)
{
	m_mousePosition = position;
}

void InputController::OnLeftBtnPressed(sf::Vector2i position)
{
	m_mousePosition = position;
	m_drugging = true;
}

void InputController::OnLeftBtnReleased(sf::Vector2i position)
{
	m_mousePosition = position;
	m_drugging = false;
}

sf::Vector2f InputController::GetDirection() const
{
	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);

	for (const auto& [key, value] : m_keyboardStates)
	{
		if (value)
		{
			switch (key)
			{
			case sf::Keyboard::Scancode::W:
				direction += sf::Vector2f(0.f, -1.f);
				break;
			case sf::Keyboard::Scancode::A:
				direction += sf::Vector2f(-1.f, 0.f);
				break;
			case sf::Keyboard::Scancode::S:
				direction += sf::Vector2f(0.f, 1.f);
				break;
			case sf::Keyboard::Scancode::D:
				direction += sf::Vector2f(1.f, 0.f);
				break;
			}
		}
	}

	return direction;
}

sf::Vector2f InputController::GetRelativeDirection(sf::Vector2f position) const
{
	if (!m_drugging)
	{
		return sf::Vector2f();
	}

	sf::Vector2f relativePosition;
	relativePosition.x = (float)m_mousePosition.x - position.x;
	relativePosition.y = (float)m_mousePosition.y - position.y;
	if (relativePosition == sf::Vector2f())
	{
		return sf::Vector2f();
	}
	relativePosition = relativePosition.normalized();
	return relativePosition;
}
