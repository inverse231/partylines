#include "game.h"

using namespace std;

game::game(){
    /*
    sf::Font font;
    if(!font.loadFromFile("Arial.ttf")) cout << "Couldn't load font!" << endl;
    score.setString("0");
    score.setPosition(25, 25);
    score.setFont(font);
    cout << "Font loaded!" << endl;
    */
}

void game::updateControls(sf::RenderWindow* aWindow){
    sf::Event event;
    while (aWindow->pollEvent(event)){
        if (event.type == sf::Event::Closed) (*aWindow).close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) addLine(3);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) addLine(2);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) addLine(1);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) addLine(4);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) addLine(5);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) addLine(6);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            if(mode == 1) mode = 0;
            else mode = 1;
        }
    }
}

void game::draw(sf::RenderWindow* aWindow){
    switch(mode){
        case 0:{
            TMenu gameMenu;
            if(gameMenu.showMenu(*aWindow) == 1) mode = 1;
            //score.setString("0");
            break;
        }
        case 1:{
            for(unsigned int i = 0; i < lines.size(); i++){
                (*aWindow).draw(lines[i]);
            }
            for(unsigned int i = 0; i < enemies.size(); i++){
                (*aWindow).draw(enemies[i]);
            }
            //(*aWindow).draw(score);
            break;
        }
    }
}

void game::addLine(int aPart){
    line tempLine(aPart);
    lines.push_back(tempLine);
}

void game::eraseLine(int index){
    lines.erase(lines.begin() + index);
}

void game::addEnemy(){
    enemy tempEnemy;
    enemies.push_back(tempEnemy);
}

void game::eraseEnemy(int index){
    enemies.erase(enemies.begin() + index);
}

void game::updateLines(){
    for(unsigned int i = 0; i < lines.size(); i++){
        lines[i].increaseDistance();
        if(lines[i].getDistance() >= 216){
            eraseLine(i);
        }
    }
}
void game::updateCircles(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        for(unsigned int j = 0; j < lines.size(); j++){
            if(enemies[i].inside(lines[j].getBounds())){
                eraseLine(j);
                eraseEnemy(i);
                /*
                int number = stoi(score.getString().toAnsiString());
                number++;
                char temp[256];
                sprintf(temp, "%d", number);
                sf::String stringScore(temp);
                score.setString(stringScore);
                */
                break;
            }
        }
        enemies[i].reduceDistance();
        if(enemies[i].getDistance() <= 4){
            eraseEnemy(i);
        }
    }
}

game::~game(){

}
