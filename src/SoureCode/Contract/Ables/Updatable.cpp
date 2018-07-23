/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include <stdexcept>
#include "Updatable.hpp"

namespace SoureCode {

    namespace Contract {

        void Updatable::update(float delta) {

            throw std::logic_error("Missing implementation");
        }

    }

}
