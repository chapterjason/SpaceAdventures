/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include <stdexcept>
#include "Activatable.hpp"

namespace SoureCode {

    namespace Contract {
        void Activatable::activate() {

            throw std::logic_error("Missing implementation");

        }

        void Activatable::deactivate() {

            throw std::logic_error("Missing implementation");

        }
    }
}