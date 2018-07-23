/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Border.hpp"

namespace SoureCode {

    namespace UI {
        namespace Stylables {

            void Border::setBorderColor(sf::Color *color, States state) {
                this->setStyle("borderColor", (void *) color, Types::STYLABLE_TYPE_COLOR, state);
            }

            sf::Color *Border::getBorderColor(States state) {
                return this->getStyle<sf::Color>("borderColor", Types::STYLABLE_TYPE_COLOR, state);
            }

            void Border::setBorderWidth(float *width, States state) {

                this->setStyle("borderWidth", (void *) width, Types::STYLABLE_TYPE_INT, state);
            }

            float *Border::getBorderWidth(States state) {
                return this->getStyle<float>("borderWidth", Types::STYLABLE_TYPE_INT, state);
            }


        }
    }
}