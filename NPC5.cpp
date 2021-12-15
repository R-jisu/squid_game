#include "NPC5.h"

npc5::npc5(float y, float _speed)
{
	texture.loadFromFile("Resources/npc3.png", sf::IntRect(0, 0, 34, 62));
	texture1.loadFromFile("Resources/npc3.png", sf::IntRect(0, 62, 34, 62));
	texture3.loadFromFile("Resources/characterdie.png", sf::IntRect(35, 0, 34, 62));

	NPC.setSize(sf::Vector2f(34, 62));
	NPC.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&NPC);
	speed = _speed;
	NPC.setPosition(0,y);
	animator->SetAnimationClip(animations[2]);
}

void npc5::Move(const float& deltaTime)
{
	float dt = speed * deltaTime;

	switch (currentDir)
	{
	case 0: //stop
		NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y);
		return;
	case 1: //up
		if (NPC.getPosition().y > 150.0f)
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y - dt);
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		}
		else
		{
			NPC.setPosition(NPC.getPosition().x, NPC.getPosition().y + dt);
		}
		break;
	case 2: //¿Þ
		if (NPC.getPosition().x > 150.0f)
		{
			NPC.setPosition(NPC.getPosition().x + dt, NPC.getPosition().y);
		}
		break;
	case 3://´Ù¿î
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

void npc5::update(const float& deltaTime, bool iswatching)
{
	waiting += deltaTime;
	if (waiting >= 2)
	{
		currentDir = rand() % 4;
		waiting = 0;
	}

	if (stoptimer >= 3)
	{
		randdie = rand() % 4 + 1;
		stoptimer = 0;
	}

	if (dying == true)
	{
		return;
	}

	// npc´Â ¼±À» ³ÑÀ¸¸é ¸ØÃá´Ù
	if (victory() == false && iswatching == false)
	{
		Move(deltaTime);
	}
	else if (iswatching == true && victory() == false)
	{
		NPC.setTexture(&texture1);

		stoptimer += deltaTime;
		if (stoptimer >= 3)
		{
			randdie = rand() % 8 + 1;
			stoptimer = 0;
		}

		if (randdie == 1 && iswatching == true)
		{
			dieimagetimer += deltaTime;
			NPC.setTexture(&texture);
			if (dieimagetimer >= 0.3)
			{
				audio.PlaySound(Sounds::Gun, false, VOLUME);
				NPC.setTexture(&texture3);
				dying = true;
				dieimagetimer = 0;
			}
		}
	}
	else if (victory() == true)
	{
		NPC.setFillColor(sf::Color(0, 0, 0, 0));
		return;
	}

	animator->Update(deltaTime);

}

bool npc5::victory()
{
	if (NPC.getPosition().x >= 500)
	{
		return true;
	}
	return false;
}

void npc5::SetupAnimations()
{
	//right animation
	sf::Texture r1, r2, r3;
	r1.loadFromFile("Resources/npc3.png", sf::IntRect(0, 0, 34, 62));
	r2.loadFromFile("Resources/npc3.png", sf::IntRect(0, 62, 34, 62));
	r3.loadFromFile("Resources/npc3.png", sf::IntRect(0, 124, 34, 62));
	std::vector<sf::Texture> rightAnimTextures{ r1,r2,r3 };
	animations[2] = new Animation(rightAnimTextures);
}

void npc5::draw(RenderWindow& _window)
{
	_window.draw(NPC);
}

