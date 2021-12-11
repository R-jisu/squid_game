#include "enemy.h"
#include "SFML/Audio.hpp"

Younhee::Younhee()
{
	//texture.loadFromFile("Resources/0HE.png", sf::IntRect(0, 0, 39, 95));
	texture.loadFromFile("Resources/0HE.png", sf::IntRect(40, 0, 80, 95));

	younhee.setTexture(&texture);
	younhee.setSize(sf::Vector2f(40, 95));
	younhee.setPosition(220,5);
}

void Younhee::ChangeState() 
{
	if (!(audio.IsPlayingAudio(Sounds::Munch))) //무궁화 꽃이 피었습니다~
	{
		state = watch;
		texture.loadFromFile("Resources/0HE.png", sf::IntRect(40, 0, 80, 95));
	}
} 

void Younhee::update(const float& deltaTime)
{

}

void Younhee::draw(RenderWindow& _window)
{
	_window.draw(younhee);
}