#include "enemy.h"

Younghee::Younghee()
{
	texture_front.loadFromFile("Resources/0HE.png", sf::IntRect(0, 0, 40, 95));
	texture_back.loadFromFile("Resources/0HE.png", sf::IntRect(40, 0, 40, 95));

	younhee.setTexture(&texture_front);
	younhee.setSize(sf::Vector2f(40, 95));
	younhee.setPosition(270,3);
}

bool Younghee::watching()
{
	return iswatching;
}

bool Younghee::update(const float& deltaTime)
{
	if (flag == 1)
	{
		watchtimer += deltaTime;
		if (watchtimer >= 2)
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

void Younghee::draw(RenderWindow& _window)
{
	_window.draw(younhee);
}