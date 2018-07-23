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
        namespace Button {

            void Button::draw(sf::RenderWindow *window) {
//    if(this->entered){
//        window->setMouseCursor();
//    }

                window->draw(this->shape);
            }

            void Button::event(sf::Event event) {

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        this->emit("pressed");
                        this->activate();
                    }
                }

                if (event.type == sf::Event::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        this->emit("released");
                        this->emit("click");
                        this->hover();
                        this->leaved = false;
                        this->entered = true;
                    }
                }


                if (event.type == sf::Event::MouseMoved) {
                    if (this->shape.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
                        if(this->leaved || (!this->leaved && !this->entered)){
                            this->emit("entered");
                            this->hover();
                            this->leaved = false;
                            this->entered = true;
                        }
                    }else{
                        if(this->entered){
                            this->emit("leaved");
                            this->deactivate();
                            this->leaved = true;
                            this->entered = false;
                        }

                        if(!this->leaved && !this->entered){
                            this->leaved = true;
                            this->entered = false;
                        }
                    }
                }


            }

            Button::Button(sf::FloatRect sizes) {
                // set active

                this->shape = sf::RectangleShape();
                this->shape.setPosition(sizes.left, sizes.top);
                this->shape.setSize(sf::Vector2f(sizes.width, sizes.height));

                this->setBackgroundColor(new sf::Color(51, 51, 51));
                this->setBackgroundColor(new sf::Color(81, 81, 81), STYLABLE_STATE_HOVER);
                this->setBackgroundColor(new sf::Color(102, 102, 102), STYLABLE_STATE_ACTIVE);

                // @todo fallbacks for states
                this->setBorderWidth(new float(1.f));
                this->setBorderWidth(new float(1.f), STYLABLE_STATE_HOVER);
                this->setBorderWidth(new float(1.f), STYLABLE_STATE_ACTIVE);

                this->setBorderColor(new sf::Color(81, 81, 81));
                this->setBorderColor(new sf::Color(102, 102, 102), STYLABLE_STATE_HOVER);
                this->setBorderColor(new sf::Color(153, 153, 153), STYLABLE_STATE_ACTIVE);

                this->deactivate();

            }

            void Button::activate() {
                // set to active
                sf::Color *backgroundColor = this->getBackgroundColor(STYLABLE_STATE_ACTIVE);
                if (backgroundColor != nullptr) {
                    this->shape.setFillColor(*backgroundColor);
                }

                sf::Color *borderColor = this->getBorderColor(STYLABLE_STATE_ACTIVE);
                if (borderColor != nullptr) {
                    this->shape.setOutlineColor(*borderColor);
                }

                float *borderWidth = this->getBorderWidth(STYLABLE_STATE_ACTIVE);
                if (borderWidth != nullptr) {
                    this->shape.setOutlineThickness(*borderWidth);
                }
            }

            void Button::deactivate() {
                // set to default
                sf::Color *backgroundColor = this->getBackgroundColor();
                if (backgroundColor != nullptr) {
                    this->shape.setFillColor(*backgroundColor);
                }

                sf::Color *borderColor = this->getBorderColor();
                if (borderColor != nullptr) {
                    this->shape.setOutlineColor(*borderColor);
                }

                float *borderWidth = this->getBorderWidth();
                if (borderWidth != nullptr) {
                    this->shape.setOutlineThickness(*borderWidth);
                }
            }

            void Button::hover() {
                // set to hover
                sf::Color *backgroundColor = this->getBackgroundColor(STYLABLE_STATE_HOVER);
                if (backgroundColor != nullptr) {
                    this->shape.setFillColor(*backgroundColor);
                }

                sf::Color *borderColor = this->getBorderColor(STYLABLE_STATE_HOVER);
                if (borderColor != nullptr) {
                    this->shape.setOutlineColor(*borderColor);
                }

                float *borderWidth = this->getBorderWidth(STYLABLE_STATE_HOVER);
                if (borderWidth != nullptr) {
                    this->shape.setOutlineThickness(*borderWidth);
                }
            }

        }
    }
}

