#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ddong_GEN.h"

using namespace sf;

class People
{
private:
	Sprite people;
	bool hitted;
	int hit_time;
	Clock clock;
	float time = 0;
public:
	Sound sound;
	SoundBuffer buffer;
	Texture people_texture;
	Texture hit_people_texture;
	People();
	void moveLeft();
	void moveRight();
	void update(Ddong_GEN& ddongs);
	void draw(RenderWindow& _window);
};