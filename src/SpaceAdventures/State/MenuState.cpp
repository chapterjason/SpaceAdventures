/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "MenuState.hpp"

namespace SpaceAdventures {

    namespace State {


        MenuState::MenuState(Core::Game *game) : State(game) {

        }

        void MenuState::draw(sf::RenderWindow *window) {
            this->exitButton->draw(window);
        }

        void MenuState::event(sf::Event event) {
            this->exitButton->event(event);
        }

        void MenuState::initialize() {
            // @todo render menu
            // @todo listen on click events
            // @todo abstract ui

            this->exitButton = new SoureCode::UI::Button::Button(sf::FloatRect(100.f, 100.f, 250.f, 50.f));

            this->exitButton->addListener("click", [](){
                std::cout << "test" << std::endl;
            });
        }

        void MenuState::cleanup() {
            State::cleanup();
            delete this->exitButton;
        }

    }

}