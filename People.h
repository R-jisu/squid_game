#pragma once
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

class People : public Younghee
{
private:
	AudioManager audio;
	Animator* animator;
	Animation* animation[5];
	float stoptime = 0;
	bool stop = false;
	bool flag = false;
public:
	RectangleShape people;
	Texture texture;
	Texture texture1;
	enum Direction nextDir = None;
	enum Direction currentDir = nextDir;
	People();
	void Move(const float& deltaTime);
	bool Die(const float& deltaTime);
	bool victory();
	float update(const float& deltaTime);
	void draw(RenderWindow& _window);
	void SetupAnimations();
};