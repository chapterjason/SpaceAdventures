/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace SoureCode {

    namespace Core {

        class DebugDraw : public b2Draw {

            protected:
                sf::RenderWindow *window;

            public:

                static const float SCALE;

                static sf::Color Box2DColorToSFML(const b2Color &color, sf::Uint8 alpha = 255);

                static sf::Vector2f Box2DVecToSFMLVec(const b2Vec2 &vector, bool scaleToPixels = true);

                DebugDraw(sf::RenderWindow *renderWindow);

                void DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;

                void DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) override;

                void DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) override;

                void DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis,
                                     const b2Color &color) override;

                void DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) override;

                void DrawTransform(const b2Transform &xf) override;
        };

    }

}