#pragma once
#include <SFML/Graphics.hpp>
#include "Score.h"

using namespace std;
using namespace sf;

class Ddong
{
private:
	float x;
	float speed;
	Texture ddong_texture;
	Sprite ddong;
public:
	bool destroyed = false;
	Ddong(float _x, float _speed, Texture& ddong_texture, Sprite& ddong);
	void update(Score& score);
	void draw(RenderWindow& _window);
	FloatRect getArea();
};