#pragma once
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"
#include "Audio/AudioManager.h"

using namespace sf;

class npc : public Younghee
{
private:
	float speed;
	float waiting = 0;
	float stoptimer = 0;
	float dieimagetimer = 0;
	bool dying = false;
	AudioManager audio;
public:
	Animator* animator;
	Animation* animation[1];
	RectangleShape NPC;
	Texture texture;
	Texture texture1;
	Texture texture3;

	int currentDir = 1;
	int randdie = 0;
	npc(float y, float _speed);
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime, bool iswatching);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};