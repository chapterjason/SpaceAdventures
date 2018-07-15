/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "StateManager.hpp"

namespace SoureCode {

    namespace Manager {


        Contract::State *StateManager::getCurrentState() {
            return this->states.back();
        }

        void StateManager::changeState(Contract::State *state) {
            if (!this->states.empty()) {
                this->getCurrentState()->cleanup();
                delete this->getCurrentState();
                this->states.pop_back();
            }

            this->states.push_back(state);
            this->getCurrentState()->initialize();
        }

        void StateManager::push(Contract::State *state) {
            if (!this->states.empty()) {
                this->getCurrentState()->pause();
            }

            this->states.push_back(state);
            this->getCurrentState()->initialize();
        }

        void StateManager::pop() {
            if (!this->states.empty()) {
                this->getCurrentState()->cleanup();
                delete this->getCurrentState();
                this->states.pop_back();
            }

            if (!this->states.empty()) {
                this->getCurrentState()->resume();
            }
        }

        void StateManager::draw(sf::RenderWindow *window) {
            if (!this->states.empty()) {
                this->getCurrentState()->draw(window);
            }
        }

        void StateManager::pause() {
            if (!this->states.empty()) {
                this->getCurrentState()->pause();
            }
        }

        void StateManager::resume() {
            if (!this->states.empty()) {
                this->getCurrentState()->resume();
            }
        }

        void StateManager::update(float delta) {
            if (!this->states.empty()) {
                this->getCurrentState()->update(delta);
            }
        }

        StateManager::~StateManager() {
            for (std::vector<Contract::State*>::iterator it = this->states.begin();
                 it != this->states.end(); ++it) {
                delete (*it);
            }
        }
    }
}