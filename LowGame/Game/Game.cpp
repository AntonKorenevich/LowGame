#include "Game.h"

Game::Game()
{
   m_window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode({ 800, 600 }),
        "LowGame"
    );


   m_rect = std::make_unique<sf::RectangleShape>(sf::Vector2f(50.f, 50.f));
   m_rect->setFillColor(sf::Color::Red);
   m_rect->setPosition(sf::Vector2f(50.f, 50.f));
}

void Game::Update()
{
    if (m_window)
    {
        while (m_window->isOpen())
        {
            while (const std::optional event = m_window->pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    m_window->close();
                }
            }

            m_window->clear();
            Draw();
            m_window->display();
        }
    }
}

void Game::Draw()
{
    if (m_window)
    {
        if (m_rect)
        {
            m_window->draw(*m_rect.get());
        }
    }
}

