/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <vector>
#include "../Contract/State.hpp"

using namespace SoureCode;

namespace SoureCode {

    namespace Manager {

        class StateManager : public Contract::Eventable,
                             public Contract::Updatable,
                             public Contract::Drawable,
                             public Contract::Pauseable {

            protected:
                std::vector<Contract::State *> states;

            public:
                virtual ~StateManager();

                Contract::State *getCurrentState();

                void changeState(Contract::State *state);

                void push(Contract::State *state);

                void pop();

                void draw(sf::RenderWindow *window) override;

                void pause() override;

                void resume() override;

                void update(float delta) override;


        };

    }
}