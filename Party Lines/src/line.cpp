#include "line.h"
#include <iostream>
using namespace std;
line::line(int aPart){
    part = aPart;
    quad = new sf::VertexArray(sf::Quads, 4);
    quad->setPrimitiveType(sf::Quads);
    cout << "Created Primitive!" << endl;
    (*quad)[0].color = sf::Color::Cyan;
    (*quad)[1].color = sf::Color::Cyan;
    (*quad)[2].color = sf::Color::Cyan;
    (*quad)[3].color = sf::Color::Cyan;
    cout << "Set color!" << endl;
    setPoints();
}

void line::increaseDistance(){
    distance += 5;
    setPoints();
}

short line::getDistance(){
    return distance;
}

void line::setPoints(){
    switch(part){
        case 0:{
            (*quad)[0].position = sf::Vector2f(10, 10);
            (*quad)[1].position = sf::Vector2f(100, 10);

            (*quad)[2].position = sf::Vector2f(100, 100);
            (*quad)[3].position = sf::Vector2f(10, 100);
            break;
        }
        case 1:{
            (*quad)[0].position = sf::Vector2f(400 + round(distance * ( 1 / 0.8660254037844 ) * 0.5),
                                               300 - distance);

            (*quad)[1].position = sf::Vector2f(400 + round(distance * ( 1 / 0.8660254037844 ) ),
                                               300);

            (*quad)[2].position = sf::Vector2f(400 + round( ( distance - fatness ) * ( 1 / 0.8660254037844 ) ),
                                               300);

            (*quad)[3].position = sf::Vector2f(400 + round( ( distance - fatness ) * ( 1 / 0.8660254037844 )  * 0.5),
                                               300 - distance + fatness);
            break;
        }
        case 2:{
            (*quad)[0].position = sf::Vector2f(400 - roundf(distance * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 - distance);

            (*quad)[1].position = sf::Vector2f(400 + roundf(distance * ( 1 / 0.8660254037844 ) * 0.5),
                                               300 - distance);

            (*quad)[2].position = sf::Vector2f(400 + roundf((distance - fatness) * ( 1 / 0.8660254037844 ) * 0.5),
                                               300 - distance + fatness);

            (*quad)[3].position = sf::Vector2f(400 - roundf((distance - fatness) * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 - distance + fatness);
            break;
        }
        case 3:{
            (*quad)[0].position = sf::Vector2f(400 - roundf(distance * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 - distance);

            (*quad)[1].position = sf::Vector2f(400 - roundf((distance - fatness) * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 - distance + fatness);

            (*quad)[2].position = sf::Vector2f(400 - round( ( distance - fatness ) * ( 1 / 0.8660254037844 ) ),
                                               300);

            (*quad)[3].position = sf::Vector2f(400 - round(distance * ( 1 / 0.8660254037844 ) ),
                                               300);
            break;
        }
        case 4:{
            (*quad)[0].position = sf::Vector2f(400 - round(distance * ( 1 / 0.8660254037844 ) * 0.5),
                                               300 + distance);

            (*quad)[1].position = sf::Vector2f(400 - round(distance * ( 1 / 0.8660254037844 ) ),
                                               300);

            (*quad)[2].position = sf::Vector2f(400 - round( ( distance - fatness ) * ( 1 / 0.8660254037844 ) ),
                                               300);

            (*quad)[3].position = sf::Vector2f(400 - round( ( distance - fatness ) * ( 1 / 0.8660254037844 )  * 0.5),
                                               300 + distance - fatness);
            break;
        }
        case 5:{
            (*quad)[0].position = sf::Vector2f(400 - roundf(distance * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 + distance);

            (*quad)[1].position = sf::Vector2f(400 + roundf(distance * ( 1 / 0.8660254037844 ) * 0.5),
                                               300 + distance);

            (*quad)[2].position = sf::Vector2f(400 + roundf((distance - fatness) * ( 1 / 0.8660254037844 ) * 0.5),
                                               300 + distance - fatness);

            (*quad)[3].position = sf::Vector2f(400 - roundf((distance - fatness) * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 + distance - fatness);
            break;
        }
        case 6:{
            (*quad)[0].position = sf::Vector2f(400 + roundf(distance * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 + distance);

            (*quad)[1].position = sf::Vector2f(400 + roundf((distance - fatness) * ( 1 / 0.8660254037844 ) * 0.5) - 1,
                                               300 + distance - fatness);

            (*quad)[2].position = sf::Vector2f(400 + round( ( distance - fatness ) * ( 1 / 0.8660254037844 ) ),
                                               300);

            (*quad)[3].position = sf::Vector2f(400 + round(distance * ( 1 / 0.8660254037844 ) ),
                                               300);
            break;
        }
    }

    cout << "1st Vertice (" << (*quad)[0].position.x << ", " << (*quad)[0].position.y << ")" << endl;
    cout << "2nd Vertice (" << (*quad)[1].position.x << ", " << (*quad)[1].position.y << ")" << endl;
    cout << "3rd Vertice (" << (*quad)[2].position.x << ", " << (*quad)[2].position.y << ")" << endl;
    cout << "4th Vertice (" << (*quad)[3].position.x << ", " << (*quad)[3].position.y << ")" << endl;
}

sf::FloatRect line::getBounds(){
    return (*quad).getBounds();
}

void line::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    target.draw(*quad, states);
}
