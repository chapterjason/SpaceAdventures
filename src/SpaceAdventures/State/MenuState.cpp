/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "MenuState.hpp"

namespace SpaceAdventures {

    namespace State {


        MenuState::MenuState(Core::Game *game) : State(game) {}

        void MenuState::draw(sf::RenderWindow *window) {
        }

        void MenuState::event(sf::Event event) {
        }

        void MenuState::initialize() {
            // @todo render menu
            // @todo listen on click events
            // @todo abstract ui
            // @todo button

            std::cout << "Works!" << std::endl;
        }

        void MenuState::cleanup() {
        }

        void MenuState::pause() {
        }

        void MenuState::resume() {
        }

        void MenuState::update(float delta) {
        }

    }

}