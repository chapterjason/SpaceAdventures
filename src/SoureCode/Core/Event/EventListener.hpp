/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include "EventCallback.hpp"

namespace SoureCode {

    namespace Core {

        namespace Event {

            class EventListener {

                protected:
                    int id;
                    EventCallback callback;

                public:

                    EventListener(int id, const EventCallback &callback);

                    int getId();

                    EventCallback getCallback();

            };

        }
    }
}
