#include <iostream>

#include "Global.h"
#include "Game.h"

Game::Game() : paddleEvent(0, 0) {
    initWindow();
}

void Game::initWindow() {
    this->window = new sf::RenderWindow();
    this->window->create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong", sf::Style::Titlebar | sf::Style::Close);
}

void Game::update(sf::Event& event) {
    ball.update(*leftPaddle, *rightPaddle);
    leftPaddle->update(event, paddleEvent);
    rightPaddle->update(event, paddleEvent);
}

void Game::render() {
    this->window->clear();

    leftPaddle->render(*this->window);
    rightPaddle->render(*this->window);
    ball.render(*this->window);
    this->window->display();
}

void Game::run() {
    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();
        }

        update(event);
        render();
    }
}