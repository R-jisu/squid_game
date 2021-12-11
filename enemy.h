#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "Audio/AudioManager.h"

using namespace std;
using namespace sf;

enum State {
	youngheeNone,
	ready,
	watch,
};

class Younhee {
private:
	State state = youngheeNone;
	AudioManager audio;
	sf::RectangleShape younhee;
	Texture texture;
public:
	Younhee();
	void ChangeState(); // �÷��̽ð� ������ watch�� �ٲٱ��Լ�
	void update(const float& deltaTime);
	void draw(RenderWindow& _window);
};