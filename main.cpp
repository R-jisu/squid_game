#include "People.h"
#include "Common.h"
#include "NPC1.h"
#include "NPC2.h"
#include "NPC3.h"
#include "NPC4.h"
#include "NPC5.h"
#include "enemy.h"

using namespace sf;
using namespace std;
float dying = 0;

int main()
{
	Font font;
	font.loadFromFile("Resources/arial.ttf");

	Text text;
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setPosition(0.0f, 0.0f);
	text.setCharacterSize(40);

	Text text1;
	text1.setFont(font);
	text1.setFillColor(Color::Black);
	text1.setPosition(200, 300);
	text1.setCharacterSize(100);
	int leftime;

	srand((unsigned)time(NULL));

	sf::Clock clock;
	float stoptime = 0;
	float deltaTime = 0;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Squid_Game");
	sf::Sprite mapSprite;
	sf::Texture mapTexture;

	if (mapTexture.loadFromFile("Resources/background1.png", sf::IntRect(0, 0, 600, 600)))
	{
		mapTexture.setSmooth(false);
		mapSprite.setTexture(mapTexture);
		mapSprite.move(0, 1);
	}
	else
	{
		std::cout << "texture not loaded correctly" << std::endl;
	}

	sf::Sprite gameOverTextSprite;
	sf::Texture gameOverTextTexture;

	int start_flag = 1;
	People people;
	npc Npc1(110, rand() % 20 + 10);
	npc2 Npc2(160, rand() % 20 + 10);
	npc3 Npc3(200, rand() % 20 + 10);
	npc4 Npc4(380, rand() % 20 + 10);
	npc5 Npc5(500, rand() % 20 + 10);
	Younghee younghee;
	
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
			//½Â¸®
			stoptime += deltaTime;
			if (stoptime >= 2)
			{
				window.close();
			}
		}


		if (people.Die(deltaTime)==true)
		{
			// Å¸ÀÌ¸Ó 2ÃÊ ÁÖ°í 
			dying += deltaTime;
			//»ç¸Á
			if (dying >= 2)
			{
				window.close();
			}
		}
		else
		{
			leftime = people.update(deltaTime);
		}


		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		if (leftime >=7)
		{
			start_flag = 0;
		}

		if (start_flag == 0)
		{
			Npc1.update(deltaTime, younghee.watching());
			Npc2.update(deltaTime, younghee.watching());
			Npc3.update(deltaTime, younghee.watching());
			Npc4.update(deltaTime, younghee.watching());
			Npc5.update(deltaTime, younghee.watching());

		}

		younghee.update(deltaTime);
		
		
		window.clear(Color(255, 255, 255));
		window.draw(mapSprite);

		younghee.draw(window);
		Npc1.draw(window);
		Npc2.draw(window);
		Npc3.draw(window);
		Npc4.draw(window);
		Npc5.draw(window);

		people.draw(window);

		text.setString(to_string(leftime));
		window.draw(text);
		window.display();
	}

	return 0;
}