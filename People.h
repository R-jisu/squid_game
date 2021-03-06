#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "enemy.h"
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "Audio/AudioManager.h"

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
	AudioManager audio;
	Animator* animator;
	Animation* animations[6];//left, right, up, down, death
	float stoptime = 0;
	bool stop = false;
	bool flag = false;
public:
	sf::RectangleShape people;
	Texture texture;
	Texture texture1;
	Texture wintexture;
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