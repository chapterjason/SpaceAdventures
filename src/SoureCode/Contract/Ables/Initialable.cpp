/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include <stdexcept>
#include "Initialable.hpp"

namespace SoureCode {

    namespace Contract {


        void Initialable::cleanup() {
            throw std::logic_error("Missing implementation");
        }

        void Initialable::initialize() {
            throw std::logic_error("Missing implementation");
        }
    }

}
