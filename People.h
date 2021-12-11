#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ddong_GEN.h"
#include "Animation/Animation.h"
#include "Animation/Animator.h"

using namespace sf;


class People
{
private:
	Animator* animator;
	Animation* animations[4];//left, right, up, down, death
public:
	Sound sound;
	SoundBuffer buffer;
	sf::RectangleShape people;
	Texture texture;
	People();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	bool victory();
	void update(Ddong_GEN& ddongs, const float& deltaTime);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};