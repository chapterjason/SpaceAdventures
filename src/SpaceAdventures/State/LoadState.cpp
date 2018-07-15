/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "LoadState.hpp"

namespace SpaceAdventures {

    namespace State {


        LoadState::LoadState(Core::Game *game) : State(game) {}

        void LoadState::draw(sf::RenderWindow *window) {
        }

        void LoadState::event(sf::Event event) {
        }

        void LoadState::initialize() {

            Manager::ResourceManager *resourceManager = this->game->getResourceManager();
            Manager::StateManager *stateManager = this->game->getStateManager();

            resourceManager->loadTexture("fighter", "./fighter.png");

            stateManager->changeState(new MenuState(this->game));
        }

        void LoadState::cleanup() {
        }

        void LoadState::pause() {
        }

        void LoadState::resume() {
        }

        void LoadState::update(float delta) {
        }

    }

}