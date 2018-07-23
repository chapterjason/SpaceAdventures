/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "State.hpp"

namespace SoureCode {

    namespace Entity {


        State::State(Core::Game *game) {
            this->game = game;
        }

        State::~State() {
            this->cleanup();
        }

        void State::draw(sf::RenderWindow *window) {
            for (std::vector<Contract::Entity*>::iterator it = this->entities.begin();
                 it != this->entities.end(); ++it) {
                (*it)->draw(window);
            }

            this->world->DrawDebugData();
        }

        void State::event(sf::Event event) {
            for (std::vector<Contract::Entity*>::iterator it = this->entities.begin();
                 it != this->entities.end(); ++it) {
                (*it)->event(event);
            }
        }

        void State::initialize() {
            this->world = new b2World(b2Vec2(0.f, 0.f));
            this->debugDraw = new Core::DebugDraw(this->game->getWindow());

            this->world->SetDebugDraw(this->debugDraw);

            this->debugDraw->SetFlags(
                    b2Draw::e_aabbBit |
                    b2Draw::e_centerOfMassBit |
                    b2Draw::e_jointBit |
                    b2Draw::e_pairBit |
                    b2Draw::e_shapeBit
            );

        }

        void State::cleanup() {
            delete this->world;
            delete this->debugDraw;
            for (std::vector<Contract::Entity*>::iterator it = this->entities.begin();
                 it != this->entities.end(); ++it) {
                delete (*it);
            }
        }

        void State::pause() {
            this->paused = true;
        }

        void State::resume() {
            this->paused = false;
        }

        void State::update(float delta) {
            if (!this->paused) {
                //this->world->Step(delta, this->velocityIterations, this->positionIterations);

                for (std::vector<Contract::Entity*>::iterator it = this->entities.begin();
                     it != this->entities.end(); ++it) {
                    (*it)->update(delta);
                }
            }
        }
    }

}