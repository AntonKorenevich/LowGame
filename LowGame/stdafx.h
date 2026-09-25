#pragma once
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <random>

// sfml
#include <SFML/Graphics.hpp>


static const sf::Vector2f s_gravity_force_direction = sf::Vector2f(0.f, 1.0f);
static const float s_gravity_force_value = 100.f;
static const float s_player_force_value = 1500.f;
static const sf::Vector2f s_player_size = sf::Vector2f(10.f, 10.f);
static const float s_reverse_power_value = 2.f;

// particles
static const float s_particle_life_time = 5.8f;
static const float s_particle_force_value = 200.f;
static const float s_particle_cd = 0.001f;
static const sf::Vector2f s_particle_size = sf::Vector2f(3.f, 3.f);
static const float s_decrease_force_factor = 40.f;
static const float s_decrease_size_factor = -0.005f;