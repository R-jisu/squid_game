#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "People.h"
#include "Ddong_GEN.h"
#include"Score.h"

using namespace sf;
using namespace std;

int main()
{

	RenderWindow window(VideoMode(360, 480), "Hello SFML");
	window.setFramerateLimit(60);



	Font font;
	font.loadFromFile("arial.ttf");
	

	People people;
	Ddong_GEN ddongs;
	Score score;
	Text text;
	text.setFont(font);
	text.setFillColor(Color::Black);
	text.setPosition(0.0f, 0.0f);
	text.setCharacterSize(15);
	int cur_score;



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

		ddongs.update(score);
		people.update(ddongs, score);

		window.clear(Color(255, 255, 255));
		people.draw(window);
		ddongs.draw(window);
		cur_score = score.update();
		text.setString(to_string(cur_score));
		window.draw(text);

		if (cur_score <= 0)
		{
			window.close();
		}

		window.display();
	}

	return 0;
}