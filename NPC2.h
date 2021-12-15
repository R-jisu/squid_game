#pragma once
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"
#include "Audio/AudioManager.h"

using namespace sf;

class npc2 : public Younghee
{
private:

	float speed;
	float waiting = 0;
	AudioManager audio;
public:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	sf::RectangleShape NPC;
	Texture texture;
	Texture texture1;

	int currentDir = 1;
	int randdie = 0;
	npc2(float y, float _speed);
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime, bool iswatching);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};