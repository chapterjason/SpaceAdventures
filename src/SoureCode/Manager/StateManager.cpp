/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include <iostream>
#include "StateManager.hpp"

namespace SoureCode {

    namespace Manager {

        Contract::State *StateManager::getCurrentState() {
            return this->states.back();
        }

        void StateManager::changeState(Contract::State *state) {
            if (!this->states.empty()) {
                this->states.back()->cleanup();
                delete this->states.back();
                this->states.pop_back();
            }

            state->initialize();
            this->states.push_back(state);
        }

        void StateManager::push(Contract::State *state) {
            if (!this->states.empty()) {
                this->states.back()->pause();
            }

            state->initialize();
            this->states.push_back(state);
        }

        void StateManager::pop() {
            if (!this->states.empty()) {
                this->states.back()->cleanup();
                delete this->states.back();
                this->states.pop_back();
            }

            if (!this->states.empty()) {
                this->states.back()->resume();
            }
        }

        void StateManager::draw(sf::RenderWindow *window) {
            if (!this->states.empty()) {
                this->states.back()->draw(window);
            }
        }

        void StateManager::pause() {
            if (!this->states.empty()) {
                this->states.back()->pause();
            }
        }

        void StateManager::resume() {
            if (!this->states.empty()) {
                this->states.back()->resume();
            }
        }

        void StateManager::update(float delta) {
            if (!this->states.empty()) {
                this->states.back()->update(delta);
            }
        }

        StateManager::~StateManager() {
            for (std::vector<Contract::State*>::iterator it = this->states.begin();
                 it != this->states.end(); ++it) {
                delete (*it);
            }
        }

        void StateManager::event(sf::Event event) {
            if (!this->states.empty()) {
                this->states.back()->event(event);
            }
        }
    }
}