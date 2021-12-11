#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "People.h"
#include "Ddong_GEN.h"
#include "Common.h"
#include <Windows.h>

using namespace sf;
using namespace std;

int main()
{
	sf::Clock clock;
	float deltaTime = 0;

	sf::RenderWindow window(sf::VideoMode(500, 600), "Pacman");

	sf::Sprite mapSprite;
	sf::Texture mapTexture;


	if (mapTexture.loadFromFile("Resources/background.png", sf::IntRect(0, 0, 500, 600)))
	{
		mapTexture.setSmooth(false);
		mapSprite.setTexture(mapTexture);
		mapSprite.move(0, 1);
	}
	else
	{
		std::cout << "texture not loaded correctly" << std::endl;
	}

	//sf::Sprite gameOverTextSprite;
	//sf::Texture gameOverTextTexture;

	//if (gameOverTextTexture.loadFromFile("Resources/ready-gameover.png", sf::IntRect(0, 0, 175, 22)))
	//{
	//	gameOverTextTexture.setSmooth(false);
	//	gameOverTextSprite.setTexture(gameOverTextTexture);
	//	gameOverTextSprite.move(310, 438);
	//}
	//else
	//{
	//	std::cout << "texture not loaded correctly" << std::endl;
	//}

	People people;
	Ddong_GEN ddongs;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
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
				else if (Keyboard::isKeyPressed(Keyboard::Up) == true)
				{
					people.moveUp();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down) == true)
				{
					people.moveDown();
				}
				break;
			default:
				break;
			}
		}

		if (people.victory())
		{
			//½Â¸®
			window.clear();
			//window.draw(victorySprite);
			window.close();
		}

		ddongs.update();
		people.update(ddongs, deltaTime);

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