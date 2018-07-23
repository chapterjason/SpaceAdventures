/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Background.hpp"

namespace SoureCode {

    namespace UI {
        namespace Stylables {

            void Background::setBackgroundColor(sf::Color *color, States state) {

                this->setStyle("backgroundColor", (void *) color, Types::STYLABLE_TYPE_COLOR, state);
            }

            sf::Color *Background::getBackgroundColor(States state) {
                return this->getStyle<sf::Color>("backgroundColor", Types::STYLABLE_TYPE_COLOR, state);
            }
        }
    }
}