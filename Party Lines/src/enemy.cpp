#include "enemy.h"

enemy::enemy(){
    sf::Vector2f position;
    position.x = 184 + rand() % 616;
    position.y = 84 + rand() % 516;
    distanceToCenter = sqrt( pow( abs( position.x - 400 ), 2 ) + pow( abs( position.y - 300), 2) );
    while(distanceToCenter > 216 || distanceToCenter < 146){
        position.x = 184 + rand() % 616;
        position.y = 84 + rand() % 516;
        distanceToCenter = sqrt( pow( abs( position.x - 400 ), 2 ) + pow( abs( position.y - 300), 2) );
    }
    position.x -= 3;
    circle.setPosition(position);
    circle.setRadius(2);
    movementVector.x = (position.x - 400) / ENEMYSPEED;
    movementVector.y = (position.y - 300) / ENEMYSPEED;
}

int enemy::getDistance(){ return sqrt( pow( abs( circle.getPosition().x - 400 ), 2 ) + pow( abs( circle.getPosition().y - 300), 2) ); }

void enemy::reduceDistance(){
    circle.move(-movementVector);
}

bool enemy::inside(sf::FloatRect rect){
    if(rect.contains(circle.getPosition())) return true;
    else return false;
}

void enemy::draw(sf::RenderTarget& target,sf::RenderStates states)const{
    target.draw(circle, states);
}

enemy::~enemy(){
    //dtor
}
