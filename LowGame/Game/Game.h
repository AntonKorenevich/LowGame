#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Game
{
public:
	Game();
	
	void Update();
	void Draw();

private:
	std::unique_ptr<sf::RenderWindow> m_window;
	std::unique_ptr<sf::RectangleShape> m_rect;
};
