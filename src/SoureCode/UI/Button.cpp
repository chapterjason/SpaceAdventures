/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Button.hpp"

namespace SoureCode {
    namespace UI {

        void Button::draw(sf::RenderWindow *window) {

        }

        void Button::event(sf::Event event) {
            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    this->emit(Button::Events::CLICK, event);
                }
            }
        }

        Button::Button(sf::Vector2f position, sf::Vector2f size) {

            this->shape = sf::RectangleShape(position);
            this->shape.setSize(size);
        }


    }
}

