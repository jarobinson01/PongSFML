#pragma once

#include <SFML/Graphics.hpp>

class Paddle {
    sf::RectangleShape paddleShape;
    int side;
    int moveUp = false;
    int moveDown = false;
public:
    Paddle(int);

    sf::FloatRect getBounds() const;

    void update(sf::Event&, float&);
    void render(sf::RenderTarget&);
};