#include "NPC1.h"
#include <iostream>
#include <random>
npc::npc(float x, float _speed)
{
	texture.loadFromFile("Resources/npc1.png", sf::IntRect(0, 682, 34, 744));

	NPC.setSize(sf::Vector2f(34, 62));
	NPC.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&NPC);
	speed = _speed;
	NPC.setPosition(x, 600.0f - 60.0f);
}

void npc::Move(const float& deltaTime)
{
	float dt = speed * deltaTime;

	switch (currentDir)
	{
	case npcNone:
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y);
		return;
	case npcUp:
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
		break;
	case npcDown:
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y + dt);
		break;
	case npcLeft:
		NPC.setPosition(NPC.getPosition().x - dt, NPC.getPosition().y);
		break;
	case npcRight:
		NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		break;
	}
}

void npc::update(const float& deltaTime)
{
	FloatRect pos = NPC.getGlobalBounds();

	currentDir = nextDir;
	animator->SetAnimationClip(animations[2]);

	// npc´Â ¼±À» ³ÑÀ¸¸é ¸ØÃá´Ù
	if (victory() == false)
		Move(deltaTime);

	animator->Update(deltaTime);

}


bool npc::victory()
{
	if (NPC.getPosition().y <= 100 - 62)
	{
		return true;
	}
	return false;
}

bool npc::Die(const float& deltaTime)
{
	if ((Younhee::update(deltaTime)) && (currentDir != npcNone))
	{
		return true;
	}
	else
		return false;
}

void npc::SetupAnimations()
{
	//right animation
	sf::Texture r1, r2,r3;
	r1.loadFromFile("Resources/npc.png", sf::IntRect(0, 0, 33, 61));
	r2.loadFromFile("Resources/npc.png", sf::IntRect(34, 0, 67, 61));
	r3.loadFromFile("Resources/npc.png", sf::IntRect(262, 1, 13, 13));
	std::vector<sf::Texture> rightAnimTextures{ r1,r2,r3 };

	//left animation
	sf::Texture l1, l2, l3;
	l1.loadFromFile("Resources/npc.png", sf::IntRect(69, 1, 103, 62));
	l2.loadFromFile("Resources/npc.png", sf::IntRect(104, 1, 136, 62));
	l3.loadFromFile("Resources/npc.png", sf::IntRect(262, 17, 13, 13));
	std::vector<sf::Texture> leftAnimTextures{ l1,l2,l3 };

	//up animation
	sf::Texture u1, u2, u3;
	u1.loadFromFile("Resources/npc.png", sf::IntRect(0, 619, 34, 681));
	u2.loadFromFile("Resources/npc.png", sf::IntRect(0, 682, 34, 744));
	u3.loadFromFile("Resources/npc.png", sf::IntRect(0, 556, 34, 618));
	std::vector<sf::Texture> upAnimTextures{ u1,u2,u3 };

	//down animation
	sf::Texture d1, d2, d3;
	d1.loadFromFile("Resources/npc.png", sf::IntRect(230, 49, 13, 13));
	d2.loadFromFile("Resources/npc.png", sf::IntRect(246, 49, 13, 13));
	d3.loadFromFile("Resources/npc.png", sf::IntRect(262, 49, 13, 13));
	std::vector<sf::Texture> downAnimTextures{ d1, d2, d3 };

	//stop animation
	sf::Texture s1;
	s1.loadFromFile("Resources/npc.png", sf::IntRect(0, 62, 33, 124));
	std::vector<sf::Texture> StopAnimTextures{ s1 };

	animations[0] = new Animation(leftAnimTextures);
	animations[1] = new Animation(rightAnimTextures);
	animations[2] = new Animation(upAnimTextures);
	animations[3] = new Animation(downAnimTextures);
	animations[4] = new Animation(StopAnimTextures, false, 0.20f);
}

void npc::draw(RenderWindow& _window)
{
	_window.draw(NPC);
}

