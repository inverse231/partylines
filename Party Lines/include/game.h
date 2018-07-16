#ifndef GAME_H
#define GAME_H
#include "line.h"
#include "enemy.h"
#include "menu.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Text.hpp>

class game
{
    public:
        game();
        void updateControls(sf::RenderWindow* aWindow);
        void draw(sf::RenderWindow* aWindow);
        void addLine(int aPart);
        void addEnemy();
        void updateLines();
        void updateCircles();
        virtual ~game();

    private:
        std::vector<enemy> enemies;
        std::vector<line> lines;
        void eraseLine(int index);
        void eraseEnemy(int index);
        //sf::Text score;
        short mode = 0;
};

#endif // GAME_H
