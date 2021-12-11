#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "People.h"
#include "Ddong_GEN.h"
#include "Common.h"
#include <Windows.h>

using namespace sf;
using namespace std;

float aspectRatio;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Pacman");
	aspectRatio = float(window.getSize().x) / float(window.getSize().y - 100);
	sf::View v(sf::Vector2f(400, 450), sf::Vector2f(800 * aspectRatio, 900));
	window.setView(v);

	sf::Sprite mapSprite;
	sf::Texture mapTexture;


	if (mapTexture.loadFromFile("Resources/background.png", sf::IntRect(0, 0, 500, 600)))
	{
		mapTexture.setSmooth(false);
		mapSprite.setTexture(mapTexture);
		mapSprite.setScale((window.getView().getSize().x) / (mapSprite.getLocalBounds().width * aspectRatio), (window.getView().getSize().y - 100) / mapSprite.getLocalBounds().height);
		mapSprite.move(0, 1);
	}
	else
	{
		std::cout << "texture not loaded correctly" << std::endl;
	}

	People people;
	Ddong_GEN ddongs;

	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left) == true)
				{
					people.moveLeft();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right) == true)
				{
					people.moveRight();
				}
				break;
			default:
				break;
			}
		}

		ddongs.update();
		people.update(ddongs);

		window.clear(Color(255, 255, 255));
		window.draw(mapSprite);
		people.draw(window);
		ddongs.draw(window);

		/*if (cur_score <= 0)
		{
			window.close();
		}*/

		window.display();
	}

	return 0;
}