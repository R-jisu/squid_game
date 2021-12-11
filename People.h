#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "enemy.h"
#include "Animation/Animation.h"
#include "Animation/Animator.h"

using namespace sf;

enum Direction {
	None,
	Up,
	Left,
	Right,
	Down
};


class People : public Younhee
{
private:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
public:
	sf::RectangleShape people;
	Texture texture;
	Direction nextDir= None;
	Direction currentDir = nextDir;
	People();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void Move(const float& deltaTime);
	bool Die(const float& deltaTime);
	bool victory();
	void update(const float& deltaTime);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};