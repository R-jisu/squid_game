#pragma once
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"
#include "Audio/AudioManager.h"

using namespace sf;

class npc4 : public Younghee
{
private:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	float speed;
	float waiting = 0;
	bool dying = false;
	AudioManager audio;
public:
	sf::RectangleShape NPC;
	Texture texture;
	Texture texture1;

	int currentDir = 0;
	npc4(float y, float _speed);
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime, bool iswatching);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};
