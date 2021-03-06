#include "People.h"
#include "enemy.h"
#include <iostream>

People::People()
{
	texture.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 62, 34, 62));
	texture1.loadFromFile("Resources/characterdie.png", sf::IntRect(0,0,34,62));
	//wintexture.loadFromFile("Resources/characterdie.png", sf::IntRect(0,0,34,62));

	people.setSize(sf::Vector2f(36, 62));
	people.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&people);
	
	people.setPosition(250 - 10.0f, 600.0f - 60.0f);

}

void People::Move(const float& deltaTime)
{
	float dt = 20 * deltaTime;

	switch (currentDir)
	{
	case None:
		people.setPosition(people.getPosition().x, people.getPosition().y);
		return;
	case Up:
			people.setPosition(people.getPosition().x, people.getPosition().y - dt);
		break;
	case Down:
		if (people.getPosition().y >= 600-60)
			return;
		people.setPosition(people.getPosition().x, people.getPosition().y + dt);
		break;
	case Left:
			people.setPosition(people.getPosition().x - dt, people.getPosition().y);
		break;
	case Right:
			people.setPosition(people.getPosition().x + dt, people.getPosition().y);
		break;
	}
}

void People::update(const float& deltaTime)
{
	stoptime += deltaTime;
	if (stoptime >= 180) stop = true;

	FloatRect pos = people.getGlobalBounds();
	if(victory()==false)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			nextDir = Up;
			animator->SetAnimationClip(animations[2]);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			nextDir = Down;
			animator->SetAnimationClip(animations[2]);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			nextDir = Left;
			animator->SetAnimationClip(animations[0]);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			nextDir = Right;
			animator->SetAnimationClip(animations[1]);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			nextDir = None;
			animator->SetAnimationClip(animations[4]);

		}
		
		currentDir = nextDir;
		Move(deltaTime);

	}
	animator->Update(deltaTime);

}

bool People::victory()
{
	if (people.getPosition().y <= 100 - 62)
	{

		return true;
	}
	return false;
}

bool People::Die(const float& deltaTime)
{
	if (stop == true)
	{
		if(flag == false)
			audio.PlaySound(Sounds::Gun, false, VOLUME);
		flag = true;
		people.setTexture(&texture1);
		return true;
	}

	if ((Younhee::update(deltaTime)) && (currentDir != None))
	{
		if (flag == false)
			audio.PlaySound(Sounds::Gun, false, VOLUME);
		flag = true;
		people.setTexture(&texture1);
		return true;
	}
	else
		return false;
}

void People::SetupAnimations()
{
	//right animation
	sf::Texture r1, r2;
	//sf::Texture r1, r2,r3;
	r1.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 0, 34, 62));
	r2.loadFromFile("Resources/maincharacter.png", sf::IntRect(34, 0, 34, 62));
	//r3.loadFromFile("Resources/maincharacter.png", sf::IntRect(262, 1, 13, 13));
	//std::vector<sf::Texture> rightAnimTextures{ r1,r2,r3 };
	std::vector<sf::Texture> rightAnimTextures{ r1,r2};

	//left animation
	//sf::Texture l1, l2, l3;
	sf::Texture l1, l2;
	l1.loadFromFile("Resources/maincharacter.png", sf::IntRect(69, 1, 34, 62));
	l2.loadFromFile("Resources/maincharacter.png", sf::IntRect(104, 1, 34, 62));
	//l3.loadFromFile("Resources/maincharacter.png", sf::IntRect(262, 17, 13, 13));
	//std::vector<sf::Texture> leftAnimTextures{ l1,l2,l3 };
	std::vector<sf::Texture> leftAnimTextures{ l1,l2};

	//up animation
	sf::Texture u1, u2, u3;
	u1.loadFromFile("Resources/maincharacter.png", sf::IntRect(34, 62, 34, 62));
	u2.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 62, 34, 62));
	u3.loadFromFile("Resources/maincharacter.png", sf::IntRect(69, 62, 34, 62));
	std::vector<sf::Texture> upAnimTextures{ u1,u2,u3 };

	//down animation
	//sf::Texture d1, d2, d3;
	//d1.loadFromFile("Resources/PacManSprites.png", sf::IntRect(230, 49, 13, 13));
	//d2.loadFromFile("Resources/PacManSprites.png", sf::IntRect(246, 49, 13, 13));
	//d3.loadFromFile("Resources/PacManSprites.png", sf::IntRect(262, 49, 13, 13));
	//std::vector<sf::Texture> downAnimTextures{ d1, d2, d3 };

	//stop animation
	sf::Texture s1;
	s1.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 62, 34, 62));
	std::vector<sf::Texture> StopAnimTextures{ s1 };


	animations[0] = new Animation(leftAnimTextures);
	animations[1] = new Animation(rightAnimTextures);
	animations[2] = new Animation(upAnimTextures);
	//animations[3] = new Animation(downAnimTextures);
	animations[4] = new Animation(StopAnimTextures, false, 0.20f);
}

void People::draw(RenderWindow& _window)
{
	_window.draw(people);
}

