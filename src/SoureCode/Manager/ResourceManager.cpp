/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "ResourceManager.hpp"

namespace SoureCode {

    namespace Manager {


        sf::Texture *ResourceManager::getTexture(std::string name) {
            if (this->textures.find(name) != textures.end()) {
                return this->textures[name];
            } else {
                return NULL;
            }
        }

        sf::Texture *ResourceManager::loadTexture(std::string name, std::string path) {
            sf::Texture *texture = new sf::Texture();

            if (texture->loadFromFile(path)) {
                this->textures[name] = texture;
                return textures[name];
            } else {
                delete texture;
                return NULL;
            }
        }

        ResourceManager::~ResourceManager() {
            for (std::map<std::string, sf::Texture *>::iterator it = this->textures.begin();
                 it != this->textures.end(); ++it) {
                delete it->second;
            }
        }
    }
}