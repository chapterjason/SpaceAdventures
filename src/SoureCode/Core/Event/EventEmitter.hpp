/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <map>
#include "EventListener.hpp"
#include "EventCallback.hpp"

namespace SoureCode {

    namespace Core {

        namespace Event {

            class EventEmitter {

                protected:

                    std::multimap<std::string, EventListener> listeners;

                    int listenerId;

                public:

                    typedef std::multimap<std::string, EventListener>::iterator Iterator;

                    EventEmitter();

                    int addListener(std::string event, EventCallback callback);

                    void removeListener(std::string event);

//                    void removeListener(std::string eventType, int id);

                    void emit(std::string event);

            };

        }

    }

}


