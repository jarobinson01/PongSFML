#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"

class Game {
    sf::RenderWindow* window;
    Paddle* leftPaddle = new Paddle(0);
    Paddle* rightPaddle = new Paddle(1);
    Ball ball;

    PaddleEvent paddleEvent;
public:
    Game();

    void initWindow();

    void updateDt();
    void update(sf::Event&);
    void render();
    void run();
};