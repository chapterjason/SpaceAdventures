/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include "../../SoureCode/Contract/Entity.hpp"
#include <Box2D/Box2D.h>

namespace SpaceAdventures {

    namespace Entity {

        class Entity : public SoureCode::Contract::Entity {

            protected:

                b2Body *body;

                sf::Sprite sprite;


        };

    }

}