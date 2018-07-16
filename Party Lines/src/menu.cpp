#include "menu.h"

int TMenu::showMenu(sf::RenderWindow & window){
	sf::Texture menuTexture1, menuTexture2;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/333.png");

	sf::Sprite menu1(menuTexture1), menu2(menuTexture2);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);

	//////////////////////////////МЕНЮ///////////////////
	window.clear();
	while (isMenu)
	{
		menu1.setColor(sf::Color::White);
		menu2.setColor(sf::Color::White);
		menuNum = 0;
		window.clear(sf::Color::Black);

		if (sf::IntRect(100, 30, 300, 50).contains(sf::Mouse::getPosition(window))) { menu1.setColor(sf::Color::Blue); menuNum = 1; }
		if (sf::IntRect(100, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { menu2.setColor(sf::Color::Blue); menuNum = 2; }

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1)  { isMenu = false; return 1; }//если нажали первую кнопку, то выходим из меню
			if (menuNum == 2)  { window.close(); isMenu = false; return 0; }

		}

        window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
	return 0;
	////////////////////////////////////////////////////
}

