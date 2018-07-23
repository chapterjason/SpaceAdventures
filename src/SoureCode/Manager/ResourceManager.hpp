/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

//using namespace SoureCode;

#include <map>
#include <SFML/Graphics.hpp>

namespace SoureCode {

    namespace Manager {

        template<class ResourceType>
        class ResourceManager {

            protected:
                std::map<std::string, ResourceType *> resources;

            public:
                ResourceType *getResource(std::string name);

                ResourceType *loadResource(std::string name, std::string path);

                virtual ~ResourceManager();
        };

        template<class ResourceType>
        ResourceType *ResourceManager<ResourceType>::getResource(std::string name) {

            if (this->resources.find(name) != resources.end()) {
                return this->resources[name];
            } else {
                return NULL;
            }
        }

        template<class ResourceType>
        ResourceType *ResourceManager<ResourceType>::loadResource(std::string name, std::string path) {

            ResourceType *resource = new ResourceType();

            if (resource->loadFromFile(path)) {
                this->resources[name] = resource;
                return resources[name];
            } else {
                delete resource;
                return NULL;
            }
        }

        template<class ResourceType>
        ResourceManager<ResourceType>::~ResourceManager() {
            for (class std::map<std::string, ResourceType *>::iterator it = this->resources.begin();
                 it != this->resources.end(); ++it) {
                delete it->second;
            }
        }

    }
}