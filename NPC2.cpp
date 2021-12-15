#include "NPC2.h"
npc2::npc2(float y, float _speed)
{
	texture.loadFromFile("Resources/npc2.png", sf::IntRect(0, 0, 34, 62));
	texture1.loadFromFile("Resources/npc2.png", sf::IntRect(0, 62, 34, 62));

	NPC.setSize(sf::Vector2f(34, 62));
	NPC.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&NPC);
	speed = _speed;
	NPC.setPosition(0, y);
	animator->SetAnimationClip(animation[0]);
}

void npc2::Move(const float& deltaTime)
{
	float dt = speed * deltaTime;
	switch (currentDir)
	{
	case 0:
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y);
		return;
	case 1:
		if (NPC.getPosition().y > 150.0f)
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		}
		else
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y + dt);
		}
	case 2:
		if (NPC.getPosition().x > 150.0f)
		{
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		}
		break;
	case 3:
		if (NPC.getPosition().y < 500.0f)
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y + dt);
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		}
		else
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
		}
		break;
	}
}

void npc2::update(const float& deltaTime, bool iswatching)
{
	waiting += deltaTime;
	if (waiting >= 2)
	{
		currentDir = rand() % 4;
		waiting = 0;
	}

	if (victory() == false && iswatching == false)
	{
		Move(deltaTime);
	}
	else if (iswatching == true && victory() == false)
	{
		NPC.setTexture(&texture1);
	}
	else if (victory() == true)
	{
		NPC.setFillColor(sf::Color(0, 0, 0, 0));
		return;
	}

	animator->Update(deltaTime);
}

bool npc2::victory()
{
	if (NPC.getPosition().x >= 500)
	{
		return true;
	}
	return false;
}

void npc2::SetupAnimations()
{
	sf::Texture r1, r2, r3;
	r1.loadFromFile("Resources/npc2.png", sf::IntRect(0, 0, 34, 62));
	r2.loadFromFile("Resources/npc2.png", sf::IntRect(0, 62, 34, 62));
	r3.loadFromFile("Resources/npc2.png", sf::IntRect(0, 124, 34, 62));
	std::vector<sf::Texture> rightAnimTextures{ r1,r2,r3 };
	animation[0] = new Animation(rightAnimTextures);
}

void npc2::draw(RenderWindow& _window)
{
	_window.draw(NPC);
}