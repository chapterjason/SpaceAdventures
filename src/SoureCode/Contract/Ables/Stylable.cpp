/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Stylable.hpp"

namespace SoureCode {
    namespace Contract {

        Stylable::Pair Stylable::getFullStyle(std::string property) {

            return this->styles.equal_range(property);
        }

        Stylable::Iterator Stylable::getStylePosition(std::string property, Types type, States state) {

            Pair range = this->getFullStyle(property);

            for (Iterator it = range.first; it != range.second; ++it) {
                if (it->second.type == type && it->second.state == state) {
                    return it;
                }
            }

            return this->styles.end();
        }

        void Stylable::setFullStyle(std::string property, Style style) {

            Iterator position = this->getStylePosition(property, static_cast<Types>(style.type),
                                                       static_cast<States>(style.state));

            if (position == this->styles.end()) {
                this->styles.insert(std::make_pair(property, style));
            } else {
                this->styles.erase(position);
                this->styles.insert(position, std::make_pair(property, style));
            }
        }

        void Stylable::setStyle(std::string property, void *data, Types type, States state) {

            this->setFullStyle(property, {
                    type,
                    state,
                    data
            });
        }

    }
}