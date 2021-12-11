#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "Audio/AudioManager.h"

using namespace std;
using namespace sf;

enum State {
	ready,
	watch,
};

class Younhee {
private:
	int flag = 1;
	AudioManager audio;
	sf::RectangleShape younhee;
	Texture texture_front;
	Texture texture_back;
	bool iswatching = false;
public:
	State state = ready;
	float watchtimer = 0;
	Younhee();
	void Soundfun();
	bool Watching();
	//void ChangeState(const float& deltaTime); // 플레이시간 끝나면 watch로 바꾸기함수
	bool update(const float& deltaTime);
	void draw(RenderWindow& _window);
};