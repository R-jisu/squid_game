#include "NPC4.h"
#include <iostream>
#include <random>
npc4::npc4(float x, float _speed)
{
	texture.loadFromFile("Resources/npc4.png", sf::IntRect(0, 682, 34, 62));
	texture2.loadFromFile("Resources/npc4.png", sf::IntRect(0, 682, 34, 62));
	texture1.loadFromFile("Resources/npc4.png", sf::IntRect(0, 560, 33, 62));
	NPC.setSize(sf::Vector2f(34, 62));
	NPC.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&NPC);
	speed = _speed;
	NPC.setPosition(x, 600.0f - 60.0f);
	animator->SetAnimationClip(animations[2]);

}

void npc4::Move(const float& deltaTime)
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

void npc4::update(const float& deltaTime, bool iswatching)
{
	//currentDir = nextDir;
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

bool npc4::victory()
{
	if (NPC.getPosition().y <= 100 - 62)
	{
		return true;
	}
	return false;
}


void npc4::SetupAnimations()
{
	////right animation
	//sf::Texture r1, r2,r3;
	//r1.loadFromFile("Resources/npc.png", sf::IntRect(0, 0, 33, 61));
	//r2.loadFromFile("Resources/npc.png", sf::IntRect(34, 0, 67, 61));
	//r3.loadFromFile("Resources/npc.png", sf::IntRect(262, 1, 13, 13));
	//std::vector<sf::Texture> rightAnimTextures{ r1,r2,r3 };

	////left animation
	//sf::Texture l1, l2, l3;
	//l1.loadFromFile("Resources/npc.png", sf::IntRect(69, 1, 103, 62));
	//l2.loadFromFile("Resources/npc.png", sf::IntRect(104, 1, 136, 62));
	//l3.loadFromFile("Resources/npc.png", sf::IntRect(262, 17, 13, 13));
	//std::vector<sf::Texture> leftAnimTextures{ l1,l2,l3 };

	//up animation
	sf::Texture u1, u2, u3;
	u1.loadFromFile("Resources/npc4.png", sf::IntRect(0, 620, 34, 62));
	u2.loadFromFile("Resources/npc4.png", sf::IntRect(0, 682, 34, 62));
	u3.loadFromFile("Resources/npc4.png", sf::IntRect(0, 560, 34, 62));
	std::vector<sf::Texture> upAnimTextures{ u1,u2,u3 };

	////down animation
	//sf::Texture d1, d2, d3;
	//d1.loadFromFile("Resources/npc.png", sf::IntRect(230, 49, 13, 13));
	//d2.loadFromFile("Resources/npc.png", sf::IntRect(246, 49, 13, 13));
	//d3.loadFromFile("Resources/npc.png", sf::IntRect(262, 49, 13, 13));
	//std::vector<sf::Texture> downAnimTextures{ d1, d2, d3 };

	////stop animation
	//sf::Texture s1;
	//s1.loadFromFile("Resources/npc.png", sf::IntRect(0, 682, 34, 744));
	//std::vector<sf::Texture> StopAnimTextures{ s1 };

	//animations[0] = new Animation(leftAnimTextures);
	//animations[1] = new Animation(rightAnimTextures);
	animations[2] = new Animation(upAnimTextures);
	//animations[3] = new Animation(downAnimTextures);
	//animations[4] = new Animation(StopAnimTextures, false, 0.20f);
}

void npc4::draw(RenderWindow& _window)
{
	_window.draw(NPC);
}

