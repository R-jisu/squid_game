#include "enemy.h"
#include "SFML/Audio.hpp"
#include <iostream>

Younhee::Younhee()
{
	texture_front.loadFromFile("Resources/0HE.png", sf::IntRect(0, 0, 40, 95));
	texture_back.loadFromFile("Resources/0HE.png", sf::IntRect(40, 0, 40, 95));

	younhee.setTexture(&texture_back);
	younhee.setSize(sf::Vector2f(40, 95));
	younhee.setPosition(220,5);
}

bool Younhee::watching()
{
	return iswatching;
}

bool Younhee::update(const float& deltaTime)
{
	if (flag == 1)
	{
		watchtimer += deltaTime;
		if (watchtimer >= 5)
		{
			state = watch;
			younhee.setTexture(&texture_front);
			watchtimer = 0;
			flag = 0;
		}

	}

	if (flag == 0 &&!(audio.IsPlayingAudio(Sounds::younghee)))
	{
		watchtimer += deltaTime;
		state = watch;
		iswatching = true;
		younhee.setTexture(&texture_front);
	}
	else
	{
		iswatching = false;
	}
		

	if (watchtimer >= 5)
	{
		state = ready;
		iswatching = false;
		younhee.setTexture(&texture_back);
		audio.PlaySound(Sounds::younghee ,false, VOLUME);
		watchtimer = 0;
	}
	
	return iswatching;

}

void Younhee::draw(RenderWindow& _window)
{
	_window.draw(younhee);
}