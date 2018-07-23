/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Game.hpp"

namespace SoureCode {

    namespace Core {


        Game::~Game() {

            this->cleanup();

        }

        void Game::initialize() {

            this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Kernel");
            this->window->setActive(false);

            this->clock = new sf::Clock;

            this->stateManager = new Manager::StateManager();
            this->textureManager = new Manager::ResourceManager<sf::Texture>();

        }

        void Game::run() {
            float delta;

            while (this->window->isOpen()) {
                sf::Event event;
                while (this->window->pollEvent(event)) {
                    this->event(event);
                }

                delta = this->clock->restart().asSeconds();

                this->update(delta);
                this->draw(this->window);

            }

        }

        void Game::cleanup() {

            if (this->window->isOpen()) {
                this->window->close();
            }

            // @todo cleanup childs

            delete this->window;
            delete this->clock;
            delete this->stateManager;
            delete this->textureManager;

        }

        void Game::draw(sf::RenderWindow *window) {

            window->clear(sf::Color::Black);

            this->stateManager->draw(window);

            window->display();

        }

        void Game::event(sf::Event event) {

            if (event.type == sf::Event::Closed) {
                this->window->close();
            }

            this->stateManager->event(event);

        }

        void Game::update(float delta) {
            this->stateManager->update(delta * this->multiplier);
        }

        sf::RenderWindow *Game::getWindow() const {
            return this->window;
        }

        Manager::StateManager *Game::getStateManager() const {
            return this->stateManager;
        }

        Manager::ResourceManager<sf::Texture> *Game::getTextureManager() const {
            return this->textureManager;
        }

        Manager::ResourceManager<sf::Font> *Game::getFontManager() const {
            return this->fontManager;
        }


    }

}