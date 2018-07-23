/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Box2D/Box2D.h>
#include "./DebugDraw.hpp"
#include "../Contract/Entity.hpp"
#include "../Contract/State.hpp"
#include "../Manager/StateManager.hpp"
#include "../Manager/ResourceManager.hpp"

using namespace SoureCode;

namespace SoureCode {

    namespace Core {

        class Game
                : public Contract::State {

            protected:

                sf::RenderWindow *window;

                sf::Clock *clock;

                Manager::StateManager *stateManager;

                Manager::ResourceManager<sf::Texture> *textureManager;

                Manager::ResourceManager<sf::Font> *fontManager;

                float multiplier = 60.f;

            public:

                virtual ~Game();


                void initialize();

                void run();

                void cleanup();

                void draw(sf::RenderWindow *window) override;

                void event(sf::Event event) override;

                void update(float delta) override;

                sf::RenderWindow *getWindow() const;

                Manager::StateManager *getStateManager() const;

                Manager::ResourceManager<sf::Texture> *getTextureManager() const;

                Manager::ResourceManager<sf::Font> *getFontManager() const;

        };

    }

}