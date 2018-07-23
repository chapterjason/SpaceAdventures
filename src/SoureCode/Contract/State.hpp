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
#include "Ables/Eventable.hpp"
#include "Ables/Updatable.hpp"
#include "Ables/Drawable.hpp"
#include "Ables/Initialable.hpp"
#include "Ables/Pauseable.hpp"

using namespace SoureCode;

namespace SoureCode {

    namespace Contract {

        class State : public Contract::Eventable,
                      public Contract::Updatable,
                      public Contract::Drawable,
                      public Contract::Initialable,
                      public Contract::Pauseable {

        };

    }

}
