/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <SFML/Graphics.hpp>
#include "./Ables/Eventable.hpp"
#include "./Ables/Updatable.hpp"
#include "./Ables/Drawable.hpp"

using namespace SoureCode;

namespace SoureCode {

    namespace Contract {

        class Entity : public Contract::Eventable,
                       public Contract::Updatable,
                       public Contract::Drawable {

        };

    }

}
