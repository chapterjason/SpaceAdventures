/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "../../Contract/Ables/Stylable.hpp"

using namespace SoureCode::Contract;

namespace SoureCode {

    namespace UI {
        namespace Stylables {
            class Background : public Stylable {

                public:

                    void setBackgroundColor(sf::Color *color, States state = STYLABLE_STATE_DEFAULT);

                    sf::Color *getBackgroundColor(States state = STYLABLE_STATE_DEFAULT);

            };

        }
    }
}
