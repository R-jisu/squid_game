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
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	float speed;
	float waiting = 0;
	float stoptimer = 0;
	int isstop = 0;
	int flag = 0;
	bool dying = false;
public:
	sf::RectangleShape NPC;
	Texture texture;
	Texture texture1;
	//NPCDirection currentDir = nextDir;
	int currentDir = 1;
	npc(float x, float _speed);
	bool Die(const float& deltaTime);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	//bool NPCDie(const float& deltaTime);
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};