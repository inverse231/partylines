#include <iostream>
#include <SFML/Graphics.hpp>
#include "line.h"
#include "game.h"

using namespace std;

void generateBackground(sf::Texture* bgTexture){
    if(!(*bgTexture).loadFromFile("Background.png")){
        sf::RectangleShape line1(sf::Vector2f(495, 1));
        line1.setPosition(150, 300);

        sf::RectangleShape line2(sf::Vector2f(495, 1));
        line2.setPosition(275, 84);
        line2.rotate(60);

        sf::RectangleShape line3(sf::Vector2f(495, 1));
        line3.setPosition(525, 84);
        line3.rotate(120);

        //borders
        sf::RectangleShape line4(sf::Vector2f(250, 3));
        line4.setPosition(275, 84);

        sf::RectangleShape line5(sf::Vector2f(250, 3));
        line5.setPosition(525,84);
        line5.rotate(60);

        sf::RectangleShape line6(sf::Vector2f(250, 3));
        line6.setPosition(650,300);
        line6.rotate(120);

        sf::RectangleShape line7(sf::Vector2f(250, 3));
        line7.setPosition(525, 516);
        line7.rotate(180);

        sf::RectangleShape line8(sf::Vector2f(250, 3));
        line8.setPosition(275, 516);
        line8.rotate(240);

        sf::RectangleShape line9(sf::Vector2f(250, 3));
        line9.setPosition(150, 300);
        line9.rotate(300);

        //texture render
        sf::RenderTexture renderedTexture;
        renderedTexture.create(800,600);
        renderedTexture.clear(sf::Color::Black);
        renderedTexture.draw(line1);
        renderedTexture.draw(line2);
        renderedTexture.draw(line3);
        renderedTexture.draw(line4);
        renderedTexture.draw(line5);
        renderedTexture.draw(line6);
        renderedTexture.draw(line7);
        renderedTexture.draw(line8);
        renderedTexture.draw(line9);
        renderedTexture.display();

        renderedTexture.setSmooth(true);
        renderedTexture.getTexture().copyToImage().saveToFile("Background.png");
        (*bgTexture).loadFromFile("Background.png");
    }
}

int main(){
    sf::Texture backgroundTexture;
    generateBackground(&backgroundTexture);
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    game thisGame;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Party Lines v3");

    sf::Clock Timer;
    sf::Clock circlesTimer;

    while (window.isOpen()){
        window.setSize(sf::Vector2u(800, 600));

        if(Timer.getElapsedTime().asMilliseconds() > 40){
            thisGame.updateLines();
            thisGame.updateCircles();
            Timer.restart();
        }
        if(circlesTimer.getElapsedTime().asMilliseconds() > 800){
            thisGame.addEnemy();
            circlesTimer.restart();
        }
        thisGame.updateControls(&window);

        window.clear();
        window.draw(backgroundSprite);
        thisGame.draw(&window);
        window.display();
    }

    return 0;
}
