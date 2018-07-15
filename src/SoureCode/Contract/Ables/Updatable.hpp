/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

namespace SoureCode {

    namespace Contract {

        class Updatable {

            public:

                /**
                 * @param delta time in seconds thats pasts away sine last frame
                 */
                virtual void update(float delta);

        };

    }

}
