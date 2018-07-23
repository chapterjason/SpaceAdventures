/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include <iostream>
#include "EventEmitter.hpp"

namespace SoureCode {

    namespace Core {


        namespace Event {

            EventEmitter::EventEmitter() {

                this->listenerId = 0;
            }

            int EventEmitter::addListener(std::string event, EventCallback callback) {

                int id = ++this->listenerId;

                this->listeners.insert(std::make_pair(event, EventListener(id, callback)));

                return id;
            }

            void EventEmitter::removeListener(std::string event) {

                std::pair<Iterator, Iterator> iterpair = this->listeners.equal_range(event);

                for (Iterator it = iterpair.first; it != iterpair.second; ++it) {
                    this->listeners.erase(it);
                }
            }

//            void EventEmitter::removeListener(std::string eventType, int id) {
//                std::pair<iterator, iterator> iterpair = this->listeners.equal_range(eventType);
//
//                iterator it = iterpair.first;
//                for (; it != iterpair.second; ++it) {
//                    if (it->second.getId() == id) {
//                        this->listeners.erase(it);
//                        break;
//                    }
//                }
//            }

            void EventEmitter::emit(std::string event) {

//                std::cout << event << std::endl;

                std::pair<Iterator, Iterator> iterpair = this->listeners.equal_range(event);

                for (Iterator it = iterpair.first; it != iterpair.second; ++it) {
                    it->second.getCallback()();
                }
            }

        }

    }
}
