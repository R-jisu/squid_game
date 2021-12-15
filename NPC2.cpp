#include "NPC2.h"
#include <iostream>
#include <random>
npc2::npc2(float x, float _speed)
{
	texture.loadFromFile("Resources/npc2.png", sf::IntRect(0, 682, 34, 62));
	texture2.loadFromFile("Resources/npc2.png", sf::IntRect(0, 682, 34, 62));
	texture1.loadFromFile("Resources/npc2.png", sf::IntRect(0, 560, 34, 62));

	NPC.setSize(sf::Vector2f(34, 62));
	NPC.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&NPC);
	speed = _speed;
	NPC.setPosition(x, 600.0f - 60.0f);
	animator->SetAnimationClip(animations[2]);
}

void npc2::Move(const float& deltaTime)
{
	float dt = speed * deltaTime;
	switch (currentDir)
	{
	case 0: //stop
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y);
		return;
	case 1: //up
		if (NPC.getPosition().y > 0.0f)
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
		}
		break;
	case 2: //¿Þ
		if (NPC.getPosition().x > 150.0f)
		{
			NPC.setPosition(NPC.getPosition().x - dt, NPC.getPosition().y);
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
		}
		else
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		break;
	case 3://¿À¸¥
		if (NPC.getPosition().x < 450.0f)
		{
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
		}
		else
			NPC.setPosition(NPC.getPosition().x - dt, NPC.getPosition().y);
		break;
	case 4:
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y + dt);
		break;
	}
}

void npc2::update(const float& deltaTime, bool iswatching)
	//currentDir = nextDir;
{
	waiting += deltaTime;
	if (waiting >= 2)
	{
		currentDir = rand() % 4;
		waiting = 0;
	}

	// npc´Â ¼±À» ³ÑÀ¸¸é ¸ØÃá´Ù
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
	if (NPC.getPosition().y <= 100 - 62)
	{
		return true;
	}
	return false;
}


void npc2::SetupAnimations()
{
	//up animation
	sf::Texture u1, u2, u3;
	u1.loadFromFile("Resources/npc2.png", sf::IntRect(0, 620, 34, 62));
	u2.loadFromFile("Resources/npc2.png", sf::IntRect(0, 682, 34, 62));
	u3.loadFromFile("Resources/npc2.png", sf::IntRect(0, 560, 34, 62));
	std::vector<sf::Texture> upAnimTextures{ u1,u2,u3 };

	animations[2] = new Animation(upAnimTextures, true, 0.1f);
}

void npc2::draw(RenderWindow& _window)
{
	_window.draw(NPC);
}

