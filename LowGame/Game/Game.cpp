#include "Game.h"

Game::Game()
    : m_generator(m_randomDevice())
{
    m_timerSEC = 0.f;

    m_window = sf::RenderWindow(
        sf::VideoMode({ 1200, 800 }),
        "LowGame"
    );
    
    m_player = m_gameObjectFactory.createPlayer();
}

void Game::Update()
{
    while (m_window.isOpen())
    {
        while (const std::optional event = m_window.pollEvent())
        {
            // input controls
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                m_inputController.KeyPressed(keyPressed->scancode);
            }

            if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
                m_inputController.KeyReleased(keyReleased->scancode);
            }

            if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mousePressed->button == sf::Mouse::Button::Left)
                {
                    m_inputController.OnLeftBtnPressed(mousePressed->position);
                }
            }
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                m_inputController.OnMouseMoved(mouseMoved->position);
            }
            if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseReleased->button == sf::Mouse::Button::Left)
                {
                    m_inputController.OnLeftBtnReleased(mouseReleased->position);
                }
            }

            if (event->is<sf::Event::Closed>())
            {
                m_window.close();
            }
        }
        
        float deltaTime = m_clock.restart().asSeconds();
        Update(deltaTime);

        m_timerSEC += deltaTime;
        if (m_timerSEC >= 0.5f)
        {
            UpdateSEC(deltaTime);
            m_timerSEC = 0.f;
        }


        m_window.clear();
        Draw();
        m_window.display();
    }
}

void Game::Draw()
{
    if (m_player)
    {
        m_player->Draw(m_window);
    }
    for (auto& particle : m_particles)
    {
        particle->Draw(m_window);
    }
}

float Game::GetRandomFloat(float min, float max)
{
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(m_generator);
}

void Game::Update(float dt)
{
    if (m_player)
    {
        m_player->Update(dt);
        sf::Vector2f direction = m_inputController.GetRelativeDirection(m_player->GetPosition());
        float directionFactor = abs(direction.x) + abs(direction.y) > 1.f ? 0.5f : 1.f;
        direction *= directionFactor;
        if (direction != sf::Vector2f())
        {
            m_player->ApplyForce(direction, s_player_force_value, dt);
        }
        sf::Vector2f particlePosition = sf::Vector2f(0.f, 0.f);
        if (m_player->ActivateParticles(particlePosition))
        {
            particlePosition.x += GetRandomFloat(-s_player_size.x * 0.5f, s_player_size.x * 0.5f);
            particlePosition.y += GetRandomFloat(-s_player_size.y * 0.5f, s_player_size.y * 0.5f);
            m_particles.emplace_back(m_gameObjectFactory.createGameObject(GameObjectType::PARTICLE, particlePosition));
               
            sf::Vector2f velo = -m_player->GetVelocity();
            sf::Vector2f dir = -direction;

            dir.x += GetRandomFloat(-0.5, 0.5);
            dir.y += GetRandomFloat(-0.5, 0.5);

            m_particles.back()->LiniarSizeDecrease(s_decrease_size_factor, dt);
            m_particles.back()->ApplyReocuringForce(dir, s_particle_force_value, dt);
        }

    }
    for (auto& particle : m_particles)
    {
        particle->Update(dt);
    }

    for (auto it = m_particles.begin(); it != m_particles.end();)
    {
        if ((*it)->IsDead())
        {
            it = m_particles.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Game::UpdateSEC(float dt)
{
    m_timerSEC += dt;
    if (m_timerSEC >= 1.f)
    {
        m_timerSEC = 0.f;
        m_player->UpdateSEC(dt);
    }
    for (auto& particle : m_particles)
    {
        particle->UpdateSEC(dt);
    }
    
}

void Game::OnLeftBtnPressed(sf::Vector2i vi)
{
    
}

void Game::OnLeftBtnReleased(sf::Vector2i vi)
{
}

