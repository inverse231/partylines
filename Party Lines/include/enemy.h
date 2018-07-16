#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <cstdlib>
#include <cmath>
#define ENEMYSPEED 25

class enemy : public sf::Drawable
{
    public:
        enemy();
        int getDistance();
        void reduceDistance();
        bool inside(sf::FloatRect rect);
        virtual ~enemy();

    private:
        sf::CircleShape circle;
        float distanceToCenter;
        sf::Vector2f movementVector;
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
};

#endif // ENEMY_H
