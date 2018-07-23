/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include "../../Contract/Ables/Drawable.hpp"
#include "../../Contract/Ables/Eventable.hpp"
#include "../../Contract/Ables/Activatable.hpp"
#include "../../Core/Event/EventEmitter.hpp"
#include "../Stylables/Background.hpp"
#include "../Stylables/Border.hpp"

using namespace SoureCode;
using namespace SoureCode::Core;
using namespace SoureCode::UI;

namespace SoureCode {

    namespace UI {
        namespace Button {

            class Button :
                    public Contract::Drawable,
                    public Contract::Eventable,
                    public Event::EventEmitter,
                    public Stylables::Background,
                    public Stylables::Border {

                protected:

                    bool entered = false;

                    bool leaved = false;

                    sf::RectangleShape shape;

                    void activate();

                    void deactivate();

                    void hover();

                public:

                    Button(sf::FloatRect sizes);

                    void draw(sf::RenderWindow *window) override;

                    void event(sf::Event event) override;

            };

        }
    }
}


