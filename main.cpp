#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>
#include "People.h"
#include "Common.h"
#include "NPC1.h"
#include "NPC2.h"
#include "NPC3.h"
#include "NPC4.h"
#include <Windows.h>
#include "enemy.h"


using namespace sf;
using namespace std;
float dying = 0;

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
	int start_flag = 1;
	People people;
	npc Npc1(rand() % 500, rand() % 20 + 10);
	npc2 Npc2(rand() % 500, rand() % 20 + 10);
	npc3 Npc3(rand() % 500, rand() % 20 + 10);
	npc4 Npc4(rand() % 500, rand() % 20 + 10);
	Younhee younghee;
	
	std::vector<npc> npcs;
	for (int num = 0; num < 5; num++)
	{
		npc p(rand() % 500, rand() % 20 + 10);
		npcs.push_back(p);
	}

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
			default:
				break;
			}
		}

		if (people.victory())
		{
			//�¸�
			window.clear();
			//window.draw(victorySprite);
			window.close();
		}

		if (people.Die(deltaTime))
		{
			// Ÿ�̸� 2�� �ְ� 
			dying += deltaTime;
			//���
			if (dying >= 2)
			{
				window.clear();
				window.close();
			}
		}
		else
		{
			people.update(deltaTime);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			start_flag = 0;
		}

		if (start_flag == 0)
		{
			Npc1.update(deltaTime, younghee.watching());
			Npc2.update(deltaTime, younghee.watching());
			Npc3.update(deltaTime, younghee.watching());
			Npc4.update(deltaTime, younghee.watching());


			for (auto& _e : npcs)
			{
				_e.update(deltaTime, younghee.watching());
				Npc1.animator->Update(deltaTime);
			}
		}

		younghee.update(deltaTime);
		
		
		window.clear(Color(255, 255, 255));
		
		window.draw(mapSprite);
		younghee.draw(window);

		Npc1.draw(window);
		Npc2.draw(window);
		Npc3.draw(window);
		Npc4.draw(window);
		for (auto &_e : npcs)
		{
			_e.draw(window);
			
			_e.animator->Update(deltaTime);
		}

		people.draw(window);

		window.display();
	}

	return 0;
}