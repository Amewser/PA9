/*
    Programmer: Francesco Rachetto
    Class: CptS 122, Spring 2021; Lab Section 03
    Programming Assignment: Programming Assignment 9
    Date: April 27, 2021
    Description: Square Lanes
*/

#pragma once

#include <stdlib.h>

#include <SFML/Graphics.hpp>

class Spike : public sf::TriangleShape
{
public:
    Spike();

private:
    float moveSpeed;
    int laneNumPosition;
    int score;
    void spawnLocation();
    void move();
};