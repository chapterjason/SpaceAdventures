/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include "../Contract/Ables/Drawable.hpp"
#include "../Contract/Ables/Eventable.hpp"
#include "../Core/EventEmitter.hpp"

using namespace SoureCode;

namespace SoureCode {

    namespace UI {

        class Button :
                public Contract::Drawable,
                public Contract::Eventable,
                public Core::EventEmitter {

            protected:

                sf::RectangleShape shape;

            public:
                enum Events {
                    CLICK
                };

                Button(sf::Vector2f position, sf::Vector2f size);

                void draw(sf::RenderWindow *window) override;

                void event(sf::Event event) override;


        };

    }
}


