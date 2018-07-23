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
            class Border : public Stylable {

                public:

                    void setBorderColor(sf::Color *color, States state = STYLABLE_STATE_DEFAULT);

                    sf::Color *getBorderColor(States state = STYLABLE_STATE_DEFAULT);

                    void setBorderWidth(float *width, States state = STYLABLE_STATE_DEFAULT);

                    float *getBorderWidth(States state = STYLABLE_STATE_DEFAULT);

            };

        }
    }
}
