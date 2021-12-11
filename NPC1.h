#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"

using namespace sf;

enum NPCDirection {
	npcNone,
	npcUp,
	npcLeft,
	npcRight,
	npcDown
};

class npc : public Younhee
{
private:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	float speed;
	float waiting = 0;
public:
	sf::RectangleShape NPC;
	Texture texture;
	NPCDirection nextDir = npcUp;
	NPCDirection currentDir = nextDir;
	npc(float x, float _speed);
	bool Die(const float& deltaTime);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void Move(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};