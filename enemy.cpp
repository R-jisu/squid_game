#include "enemy.h"
#include "SFML/Audio.hpp"
#include <iostream>

Younhee::Younhee()
{
	texture_front.loadFromFile("Resources/0HE.png", sf::IntRect(0, 0, 39, 95));
	texture_back.loadFromFile("Resources/0HE.png", sf::IntRect(40, 0, 80, 95));

	younhee.setTexture(&texture_back);
	younhee.setSize(sf::Vector2f(40, 95));
	younhee.setPosition(220,5);
}

void Younhee::Soundfun() {
	audio.PlaySound(Sounds::GameStart, false, VOLUME);
}

//void Younhee::ChangeState(const float& deltaTime)
//{
//	if (!(audio.IsPlayingAudio(Sounds::Death))) //무궁화 꽃이 피었습니다~
//	//if (state!=watch) //무궁화 꽃이 피었습니다~
//	{
//		watchtimer += deltaTime;
//
//		state = watch;
//		iswatching = true;
//		younhee.setTexture(&texture_front);
//	}
//	else
//		cout << "dmddo" << endl;
//	//else
//		//iswatchiawdng = false;
//} 

bool Younhee::Watching()
{
	cout << iswatching << endl;
	return iswatching;
}


bool Younhee::update(const float& deltaTime)
{
	if (flag == 1)
	{
		watchtimer += deltaTime;
		if (watchtimer >= 4)
		{
			state = watch;
			younhee.setTexture(&texture_front);
			watchtimer = 0;
			flag = 0;
		}

	}

	if (flag == 0 &&!(audio.IsPlayingAudio(Sounds::Death))&& !(audio.IsPlayingAudio(Sounds::GameStart)))
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
		younhee.setTexture(&texture_back);
		audio.PlaySound(Sounds::Death ,false, VOLUME);
		watchtimer = 0;
	}

	return iswatching;

}

void Younhee::draw(RenderWindow& _window)
{
	_window.draw(younhee);
}