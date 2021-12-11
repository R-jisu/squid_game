#pragma once
#include <vector>
#include <random>
#include <SFML/Audio.hpp>
#include "Ddong.h"
#include "Score.h"

using namespace std;
using namespace sf;

class Ddong_GEN
{
private:
	vector<Ddong> ddongs;
	int ddong_gen_period;
	Texture ddong_texture;
	Sprite ddong;
public:
	Clock clock;
	float time = 0;
	Ddong_GEN();
	void update(Score& score);
	void draw(RenderWindow& _window);
	bool checkHit(FloatRect _rect);
};