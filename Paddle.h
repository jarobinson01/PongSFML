#pragma once

#include <SFML/Graphics.hpp>

#include "PaddleEvent.h"

class Paddle {
    sf::RectangleShape paddleShape;
    int side;
    bool moveUp = false;
    bool moveDown = false;

    float x_vel = 0;
    float y_vel = 0;
public:
    Paddle(int);

    sf::FloatRect getBounds() const;

    void update(sf::Event&, PaddleEvent&);
    void update(float, float);
    void render(sf::RenderTarget&);
};