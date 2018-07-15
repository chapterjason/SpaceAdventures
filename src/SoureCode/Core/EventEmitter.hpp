/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <mutex>
#include <list>
#include <algorithm>

namespace SoureCode {

    namespace Core {

        class EventEmitter {

            protected:

                struct ListenerBase {
                    ListenerBase() {}

                    ListenerBase(unsigned int i)
                            : id(i) {}

                    virtual ~ListenerBase() {}

                    unsigned int id;
                };

                template<typename... Args>
                struct Listener : public ListenerBase {
                    Listener() {}

                    Listener(unsigned int i, std::function<void(Args...)> c)
                            : ListenerBase(i), cb(c) {}

                    std::function<void(Args...)> cb;
                };

                unsigned int listenerId;

                std::multimap<unsigned int, std::shared_ptr<ListenerBase>> listeners;

            public:

                EventEmitter();

                ~EventEmitter();

                template<typename... Args>
                unsigned int addListener(unsigned int event_id, std::function<void(Args...)> cb);

                unsigned int addListener(unsigned int event_id, std::function<void()> cb);

                void removeListener(unsigned int listener_id);

                template<typename... Args>
                void emit(unsigned int event_id, Args... args);
        };


    }

}


