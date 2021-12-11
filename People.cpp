#include "People.h"
#include <iostream>

People::People()
{
	people_texture.loadFromFile("people.PNG");
	hit_people_texture.loadFromFile("hit_people.png");
	buffer.loadFromFile("hit_sound.ogg");
	sound.setBuffer(buffer);

	people.setTexture(people_texture);

	people.setTextureRect(IntRect(0, 0, 30, 30));
	people.setPosition(180.0f - 10.0f, 480.0f - 30.0f);

	hitted = false;
	hit_time = 0;
}

void People::moveLeft()
{
	if (people.getPosition().x <= 0.0f)
	{
		return;
	}
	people.move(-10.0f, 0.0f);
}

void People::moveRight()
{
	if (people.getPosition().x >= 360.0f - 20.0f)
	{
		return;
	}
	people.move(10.0f, 0.0f);
}

void People::update(Ddong_GEN& ddongs)
{
	/*
		똥에 맞았는지 판단하는 코드와 맞았을 때 동작에 대한 코드 작성
	*/
	time = clock.getElapsedTime().asSeconds();
	FloatRect pos = people.getGlobalBounds();

	//똥젠 히트박스 bool 체크
	hitted = ddongs.checkHit(pos);

	if (time >= 1.0f)
		people.setTexture(people_texture);

	if (hitted == true)
	{

		sound.play();

		people.setTexture(hit_people_texture);

		clock.restart();

		hit_time++;
		hitted = false;
	}

}

void People::draw(RenderWindow& _window)
{
	_window.draw(people);
}