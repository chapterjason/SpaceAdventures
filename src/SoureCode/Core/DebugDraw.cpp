/*
 * This file is part of the SpaceAdventures package.
 *
 * (c) Jason Schilling <jason.schilling@sourecode.de>
 *
 * For the full copyright and license information, please view the LICENSE
 * File that was distributed with this source code.
 */

#include "DebugDraw.hpp"

namespace SoureCode {

    namespace Core {

        const float DebugDraw::SCALE = 32.f;

        sf::Color DebugDraw::Box2DColorToSFML(const b2Color &color, sf::Uint8 alpha) {
            return sf::Color(static_cast<sf::Uint8>(color.r * 255), static_cast<sf::Uint8>(color.g * 255),
                             static_cast<sf::Uint8>(color.b * 255), alpha);
        }

        sf::Vector2f DebugDraw::Box2DVecToSFMLVec(const b2Vec2 &vector, bool scaleToPixels) {
            return sf::Vector2f(vector.x * (scaleToPixels ? DebugDraw::SCALE : 1.f),
                                vector.y * (scaleToPixels ? DebugDraw::SCALE : 1.f));
        }

        DebugDraw::DebugDraw(sf::RenderWindow *renderWindow) {
            this->window = renderWindow;
        }

        void DebugDraw::DrawPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
            sf::ConvexShape polygon(static_cast<size_t>(vertexCount));
//            sf::Vector2f center;

            for (int i = 0; i < vertexCount; i++) {
                //polygon.setPoint(i, SFMLDraw::Box2DVecToSFMLVec(vertices[i]));
                sf::Vector2f transformedVec = DebugDraw::Box2DVecToSFMLVec(vertices[i]);
                polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(
                        transformedVec.y)));
            }

            polygon.setOutlineThickness(-1.f);
            polygon.setFillColor(sf::Color::Transparent);
            polygon.setOutlineColor(DebugDraw::Box2DColorToSFML(color));

            this->window->draw(polygon);
        }

        void DebugDraw::DrawSolidPolygon(const b2Vec2 *vertices, int32 vertexCount, const b2Color &color) {
            sf::ConvexShape polygon(static_cast<size_t>(vertexCount));

            for (int i = 0; i < vertexCount; i++) {
                //polygon.setPoint(i, SFMLDraw::Box2DVecToSFMLVec(vertices[i]));
                sf::Vector2f transformedVec = DebugDraw::Box2DVecToSFMLVec(vertices[i]);
                polygon.setPoint(i, sf::Vector2f(std::floor(transformedVec.x), std::floor(
                        transformedVec.y)));
            }

            polygon.setOutlineThickness(-1.f);
            polygon.setFillColor(DebugDraw::Box2DColorToSFML(color, 60));
            polygon.setOutlineColor(DebugDraw::Box2DColorToSFML(color));

            this->window->draw(polygon);
        }

        void DebugDraw::DrawCircle(const b2Vec2 &center, float32 radius, const b2Color &color) {
            sf::CircleShape circle(radius * DebugDraw::SCALE);
            circle.setOrigin(radius * DebugDraw::SCALE, radius * DebugDraw::SCALE);
            circle.setPosition(DebugDraw::Box2DVecToSFMLVec(center));
            circle.setFillColor(sf::Color::Transparent);
            circle.setOutlineThickness(-1.f);
            circle.setOutlineColor(DebugDraw::Box2DColorToSFML(color));

            this->window->draw(circle);
        }

        void
        DebugDraw::DrawSolidCircle(const b2Vec2 &center, float32 radius, const b2Vec2 &axis, const b2Color &color) {
            sf::CircleShape circle(radius * DebugDraw::SCALE);
            circle.setOrigin(radius * DebugDraw::SCALE, radius * DebugDraw::SCALE);
            circle.setPosition(DebugDraw::Box2DVecToSFMLVec(center));
            circle.setFillColor(DebugDraw::Box2DColorToSFML(color, 60));
            circle.setOutlineThickness(1.f);
            circle.setOutlineColor(DebugDraw::Box2DColorToSFML(color));

            b2Vec2 endPoint = center + radius * axis;
            sf::Vertex line[2] = {
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(center),
                               DebugDraw::Box2DColorToSFML(color)),
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(endPoint),
                               DebugDraw::Box2DColorToSFML(color)),
            };

            this->window->draw(circle);
            this->window->draw(line, 2, sf::Lines);
        }

        void DebugDraw::DrawSegment(const b2Vec2 &p1, const b2Vec2 &p2, const b2Color &color) {
            sf::Vertex line[] = {
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(p1), DebugDraw::Box2DColorToSFML(color)),
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(p2), DebugDraw::Box2DColorToSFML(color))
            };

            this->window->draw(line, 2, sf::Lines);
        }

        void DebugDraw::DrawTransform(const b2Transform &xf) {
            float lineLength = 0.5;

            b2Vec2 xAxis = xf.p + lineLength * xf.q.GetXAxis();
            sf::Vertex redLine[] = {
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(xf.p), sf::Color::Red),
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(xAxis), sf::Color::Red)
            };


            b2Vec2 yAxis = xf.p + lineLength * xf.q.GetYAxis();
            sf::Vertex greenLine[] = {
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(xf.p), sf::Color::Green),
                    sf::Vertex(DebugDraw::Box2DVecToSFMLVec(yAxis), sf::Color::Green)
            };

            this->window->draw(redLine, 2, sf::Lines);
            this->window->draw(greenLine, 2, sf::Lines);
        }
    }

}