#include "Ddong.h"


Ddong::Ddong(float _x, float _speed, Texture& ddong_texture, Sprite& ddong) : x(_x), speed(_speed), ddong_texture(ddong_texture), ddong(ddong)
{
	ddong.setPosition(_x, 0);
}

void Ddong::update()
{
	if (destroyed == true)
	{
		return;
	}

	Vector2f pos = ddong.getPosition();
	if (pos.y > 480.0f)
	{
		destroyed = true;
	}
	ddong.move(0.0f, 1.0f * speed);
}

void Ddong::draw(RenderWindow& _window)
{
	if (destroyed == true)
	{
		return;
	}
	_window.draw(ddong);
}

FloatRect Ddong::getArea()
{
	return ddong.getGlobalBounds();
}