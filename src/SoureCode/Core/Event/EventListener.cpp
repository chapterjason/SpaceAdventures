/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "EventListener.hpp"

namespace SoureCode {

    namespace Core {

        namespace Event {


            int EventListener::getId() {

                return this->id;
            }

            EventCallback EventListener::getCallback() {

                return this->callback;
            }

            EventListener::EventListener(int id, const EventCallback &callback) : id(id), callback(callback) {}
        }
    }
}