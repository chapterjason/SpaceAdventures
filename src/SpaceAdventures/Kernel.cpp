/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "Kernel.hpp"
#include "State/LoadState.hpp"

namespace SpaceAdventures {

    void Kernel::initialize() {
        Core::Game::initialize();

        this->stateManager->changeState(new SpaceAdventures::State::LoadState(this));
    }

}