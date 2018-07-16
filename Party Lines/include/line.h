#ifndef LINE_H
#define LINE_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <cmath>

class line : public sf::Drawable
{
    public:
        line(int aPart);
        short getDistance();
        void increaseDistance();
        sf::FloatRect getBounds();

    private:
        sf::VertexArray* quad;
        short distance = 5;
        short fatness = 5;
        short part;

        void setPoints();
        virtual void draw(sf::RenderTarget& target,sf::RenderStates states)const;
};

#endif // LINE_H
