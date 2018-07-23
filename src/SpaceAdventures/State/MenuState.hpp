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
#include "../../SoureCode/UI/Button/Button.hpp"
#include <iostream>

namespace SpaceAdventures {

    namespace State {

        class MenuState : public Entity::State {
            protected:
//                Button *playButton;
//                Button *settingsButton;
                SoureCode::UI::Button::Button *exitButton;

            public:
                MenuState(Core::Game *game);

                void draw(sf::RenderWindow *window) override;

                void event(sf::Event event) override;

                void initialize() override;

                void cleanup() override;

        };

    }

}