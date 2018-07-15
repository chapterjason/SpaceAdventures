/*
 * This file is part of the Kernel package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <Box2D/Box2D.h>
#include "../Contract/State.hpp"
#include "../Core/DebugDraw.hpp"
#include "../Contract/Entity.hpp"
#include "../Core/Game.hpp"

using namespace SoureCode;

namespace SoureCode {

    namespace Entity {

        class State : public Contract::State {

            protected:

                b2World *world;

                Core::DebugDraw *debugDraw;

                Core::Game *game;

                std::vector<Contract::Entity*> entities;

                int velocityIterations = 10;

                int positionIterations = 10;

                bool paused = false;

            public:

                State(Core::Game *game);

                virtual ~State();

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