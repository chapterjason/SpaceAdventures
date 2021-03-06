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

namespace SoureCode {
    namespace Core {
        namespace Event {
            typedef std::function<void()> EventCallback;
        }
    }
}