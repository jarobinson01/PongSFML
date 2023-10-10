#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Global.h"
#include "Paddle.h"
#include "Ball.h"

void updateDt(float& dt, sf::Clock& dtClock) {
    // Updates dt variable with the time it took to update and render one frame
    dt = dtClock.restart().asSeconds();
}

int main() {
    sf::RenderWindow window;
    sf::Clock dtClock;
    float dt;

    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Platformer", sf::Style::Titlebar | sf::Style::Close);
    Paddle leftPaddle(0);
    Paddle rightPaddle(1);
    Ball ball;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        updateDt(dt, dtClock);

        leftPaddle.update(event, dt);
        rightPaddle.update(event, dt);
        ball.update(leftPaddle, rightPaddle, dt);

        window.clear();

        leftPaddle.render(window);
        rightPaddle.render(window);
        ball.render(window);
        window.display();
    }

    return 0;
}