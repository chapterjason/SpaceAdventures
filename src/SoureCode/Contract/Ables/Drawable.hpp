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

namespace SoureCode {

    namespace Contract {

        class Drawable {

            public:

                virtual void draw(sf::RenderWindow *window);;

        };

    }

}