/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "EventEmitter.hpp"

#include <stdexcept>

namespace SoureCode {

    namespace Core {

        template<typename... Args>
        unsigned int EventEmitter::addListener(unsigned int event_id, std::function<void(Args...)> cb) {

            if (!cb) {
                throw std::invalid_argument("EventEmitter::addListener: No callback provided.");
            }

//            std::lock_guard<std::mutex> lock(mutex);

            unsigned int listener_id = ++this->listenerId;
            listeners.insert(std::make_pair(event_id, std::make_shared<Listener<>>(listener_id, cb)));

            return listener_id;
        }

        unsigned int EventEmitter::addListener(unsigned int event_id, std::function<void()> cb) {

            if (!cb) {
                throw std::invalid_argument("EventEmitter::addListener: No callback provided.");
            }

            unsigned int listener_id = ++this->listenerId;
            listeners.insert(std::make_pair(event_id, std::make_shared<Listener<>>(listener_id, cb)));

            return listener_id;
        }

        void EventEmitter::removeListener(unsigned int listener_id) {
//            std::lock_guard<std::mutex> lock(mutex);

            auto i = std::find_if(listeners.begin(), listeners.end(),
                                  [&](std::pair<const unsigned int, std::shared_ptr<ListenerBase>> p) {
                                      return p.second->id == listener_id;
                                  });

            if (i != listeners.end()) {
                listeners.erase(i);
            } else {
                throw std::invalid_argument("EventEmitter::removeListener: Invalid listener id.");
            }
        }

        template<typename... Args>
        void EventEmitter::emit(unsigned int event_id, Args... args) {

            std::list<std::shared_ptr<Listener<Args...>>> handlers;
            {
//                std::lock_guard<std::mutex> lock(mutex);

                auto range = listeners.equal_range(event_id);
                handlers.resize(static_cast<unsigned long>(std::distance(range.first, range.second)));
                std::transform(range.first, range.second, handlers.begin(),
                               [](std::pair<const unsigned int, std::shared_ptr<ListenerBase>> p) {
                                   auto l = std::dynamic_pointer_cast<Listener<Args...>>(p.second);
                                   if (l) {
                                       return l;
                                   } else {
                                       throw std::logic_error("EventEmitter::emit: Invalid event signature.");
                                   }
                               });
            }

            for (auto &h : handlers) {
                h->cb(args...);
            }
        }

        EventEmitter::EventEmitter() {

        }

        EventEmitter::~EventEmitter() {

        }

//
//        void EventEmitter::addEventListener(std::string event, std::function<void ()> callback) {
//
//            std::map<std::string, std::vector<std::function<void()>>>::iterator it = this->listeners.find(event);
//
//            if (it != this->listeners.end()) {
//                it->second.push_back(callback);
//            } else {
//                std::vector<std::function<void()>> listeners;
//                listeners.push_back(callback);
//                this->listeners[event] = listeners;
//            }
//        }
//
//        void EventEmitter::removeEventLister(std::string event) {
//
//            std::map<std::string, std::vector<std::function<void()>>>::iterator iterator = this->listeners.find(
//                    event);
//
//            if (iterator != this->listeners.end()) {
//                this->listeners.erase(iterator);
//            }
//        }
//
//        void EventEmitter::removeEventLister(std::string event, std::function<void ()> callback) {
//
//            std::map<std::string, std::vector<std::function<void()>>>::iterator it = this->listeners.find(
//                    event);
//
//            if (it != this->listeners.end()) {
//                std::vector<std::function<void()>>::iterator foundCallback = std::find_if(it->second.begin(),
//                                                                                          it->second.end(),
//                                                                                          [callback, this](
//                                                                                                  std::function<void()> findCallback) {
//                                                                                              return this->getAddress(
//                                                                                                      callback) ==
//                                                                                                     this->getAddress(
//                                                                                                             findCallback);
//                                                                                          });
//                if (foundCallback != it->second.end()) {
//                    it->second.erase(foundCallback);
//                }
//            }
//
//        }
//
//        template<typename T, typename... U>
//        size_t EventEmitter::getAddress(std::function<T(U...)> f) {
//
//            typedef T(fnType)(U...);
//            fnType **fnPointer = f.template target<fnType *>();
//            return (size_t) *fnPointer;
//        }
//
//        template<typename... Args>
//        void EventEmitter::emit(std::string event, Args... args) {
//
//            std::map<std::string, std::vector<std::function<void()>>>::iterator iterator = this->listeners.find(
//                    event);
//
//            if (iterator != this->listeners.end()) {
//                for (std::vector<std::function<void()>>::iterator it = iterator->second.begin();
//                     it != iterator->second.end(); ++it) {
//                    (*it)(args...);
//                }
//            }
//        }

    }
}
