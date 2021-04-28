/*
    Programmer: Francesco Rachetto
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 27, 2021
    Description: Square Lanes
*/

#include "PowerUp.h"

PowerUp::PowerUp()
{
    this->setSize(sf::Vector2f(100.0f, 100.0f));
    this->setFillColor(sf::Color::Blue);
    this->setOrigin(this->getSize().x / 2, this->getSize().y / 2);
    laneNumPosition = rand() % 4 + 1;
    moveSpeed = 3.0f;
    score = 0;
    spawnLocation();
}

void Player::spawnLocation(void)
{
    float yPosition = 1480.f; //Spawns off screen

    switch (laneNumPosition)
    {
    case 1: // First lane
        this->setPosition(240.f, yPosition);
        break;
    case 2: // Second lane
        this->setPosition(720.f, yPosition);
        break;
    case 3: // Third lane
        this->setPosition(1200.f, yPosition);
        break;
    case 4: // Fourth lane
        this->setPosition(1680.f, yPosition);
        break;
    default:
        break;
    }
}

void PowerUp::move(void)
{
    
}

void PowerUp::shield(void)
{
    if (Player.health == 1)
    {
        Player.health = 2;
    }
}