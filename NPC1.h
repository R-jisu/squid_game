#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"

using namespace sf;

class npc : public Younhee
{
private:
	
	float speed;
	float waiting = 0;
	float stoptimer = 0;
	float dieimagetimer = 0;
	int isstop = 0;
	int flag = 0;
	bool dying = false;
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
	npc(float x, float _speed);
	//bool Die(const float& deltaTime);
	//bool NPCDie(const float& deltaTime);
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime, bool iswatching);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};