/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include "../../SoureCode/Entity/State.hpp"
#include "MenuState.hpp"

using namespace SoureCode;

namespace SpaceAdventures {

    namespace State {

        class LoadState : public Entity::State {

            public:
                LoadState(Core::Game *game);



                void draw(sf::RenderWindow *window) override;

                void event(sf::Event event) override;

                void initialize() override;

                void cleanup() override;

                void pause() override;

                void resume() override;

                void update(float delta) override;

        };

    }

}