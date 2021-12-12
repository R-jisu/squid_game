#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"

using namespace sf;

class npc3 : public Younhee
{
private:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	float speed;
	float waiting = 0;
	float stoptimer = 0;
	int isstop = 0;
public:
	sf::RectangleShape NPC;
	Texture texture;
	Texture texture1;

	int currentDir = 0;
	npc3(float x, float _speed);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime, bool iswatching);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};
