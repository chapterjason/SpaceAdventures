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
#include <string>
#include <SFML/Graphics.hpp>
#include "StylableStyle.hpp"
#include "StylableTypes.hpp"
#include "StylableStates.hpp"

namespace SoureCode {
    namespace Contract {

        class Stylable {
            public:
                typedef std::multimap<std::string, Style>::iterator Iterator;

                typedef std::pair<Iterator, Iterator> Pair;

            protected:

                std::multimap<std::string, Style> styles;

                Pair getFullStyle(std::string property);

                Iterator getStylePosition(std::string property, Types type, States state);

                void setFullStyle(std::string property, Style style);

                void setStyle(std::string property, void *data, Types type, States state = STYLABLE_STATE_DEFAULT);

                template<typename T>
                T *getStyle(std::string property, Types type, States state = STYLABLE_STATE_DEFAULT);

        };

        template<typename T>
        T *Stylable::getStyle(std::string property, Types type, States state) {

            Iterator position = this->getStylePosition(property, type, state);
            if (position == this->styles.end()) {
                return nullptr;
            } else {
                return static_cast<T *>(position->second.data);
            }
        }

    }
}


