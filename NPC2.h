#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"
#include "Audio/AudioManager.h"

using namespace sf;

class npc2 : public Younhee
{
private:

	float speed;
	float waiting = 0;
	int isstop = 0;
	int flag = 0;
	AudioManager audio;
public:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	sf::RectangleShape NPC;
	Texture texture;
	Texture texture1;
	Texture texture2;
	Texture texture3;

	int currentDir = 1;
	int randdie = 0;
	npc2(float x, float _speed);
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime, bool iswatching);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};