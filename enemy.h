#pragma once
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "Audio/AudioManager.h"

using namespace std;
using namespace sf;

enum State {
	ready,
	watch,
};

class Younghee {
private:
	int flag = 1;
	AudioManager audio;
	RectangleShape younghee;
	Texture texture_front;
	Texture texture_back;
	bool iswatching = false;
public:
	enum State state = watch;
	float watchtimer = 0;
	Younghee();
	bool watching();
	bool update(const float& deltaTime);
	void draw(RenderWindow& _window);
};