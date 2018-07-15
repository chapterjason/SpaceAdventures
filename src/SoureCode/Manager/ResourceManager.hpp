/*
 * This file is part of the Kernel package.
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

        class ResourceManager {

            protected:
                std::map<std::string, sf::Texture *> textures;

            public:

                sf::Texture *getTexture(std::string name);

                sf::Texture *loadTexture(std::string name, std::string path);

                virtual ~ResourceManager();
        };

    }
}