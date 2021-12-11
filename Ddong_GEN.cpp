#include "Ddong_GEN.h"

Ddong_GEN::Ddong_GEN()
{
	ddong_gen_period = 200.0f; //밀리초단위

	ddong_texture.loadFromFile("ddong.png");
	ddong.setTexture(ddong_texture);

}

void Ddong_GEN::update(Score& score)
{
	time = clock.getElapsedTime().asMilliseconds();

	if (time >= ddong_gen_period)
	{
		Ddong p(std::rand() % 360, std::rand() % 6 + 0.7, ddong_texture, ddong);
		ddongs.push_back(p);
		clock.restart();
	}

	for (auto& _e : ddongs)
	{
		_e.update(score);
	}
}

void Ddong_GEN::draw(RenderWindow& _window)
{
	for (auto& _e : ddongs)
	{
		_e.draw(_window);
	}
}

bool Ddong_GEN::checkHit(FloatRect _rect)
{
	for (auto& _e : ddongs)
	{
		if (_rect.intersects(_e.getArea()) == true && _e.destroyed == false)
		{
			_e.destroyed = true;
			return true;
		}
	}
	return false;
}