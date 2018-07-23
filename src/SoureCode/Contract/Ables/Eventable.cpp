/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Eventable.hpp"

namespace SoureCode {

    namespace Contract {


        void Eventable::event(sf::Event event) {
            throw std::logic_error("Missing implementation");
        }
    }

}