#include "People.h"
#include <iostream>

People::People()
{
	texture.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 62, 35, 124));

	people.setSize(sf::Vector2f(36, 62));
	people.setTexture(&texture);
	SetupAnimations();
	animator = new Animator(&people);
	
	texture.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 62, 35, 124));

	people.setPosition(250 - 10.0f, 600.0f - 30.0f);

}

void People::moveLeft()
{
	if (people.getPosition().x <= 0.0f)
	{
		return;
	}
	people.move(-10.0f, 0.0f);
	animator->SetAnimationClip(animations[0]);

}

void People::moveRight()
{
	if (people.getPosition().x >= 500.0f - 20.0f)
	{
		return;
	}
	people.move(10.0f, 0.0f);
	animator->SetAnimationClip(animations[1]);

}

void People::moveUp()
{
	if (people.getPosition().y <= 20.0f)
	{
		return;
	}
	people.move(0.0f, -10.0f);
	animator->SetAnimationClip(animations[2]);
}

void People::moveDown()
{
	if (people.getPosition().y >= 600.0f-30.0f)
	{
		return;
	}
	people.move(0.0f, 10.0f);
}

void People::update(Ddong_GEN& ddongs, const float& deltaTime)
{
	FloatRect pos = people.getGlobalBounds();
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


void People::SetupAnimations()
{
	//right animation
	sf::Texture r1, r2;
	//sf::Texture r1, r2,r3;
	r1.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 0, 33, 61));
	r2.loadFromFile("Resources/maincharacter.png", sf::IntRect(34, 0, 67, 61));
	//r3.loadFromFile("Resources/maincharacter.png", sf::IntRect(262, 1, 13, 13));
	//std::vector<sf::Texture> rightAnimTextures{ r1,r2,r3 };
	std::vector<sf::Texture> rightAnimTextures{ r1,r2};

	//left animation
	//sf::Texture l1, l2, l3;
	sf::Texture l1, l2;
	l1.loadFromFile("Resources/maincharacter.png", sf::IntRect(69, 1, 103, 62));
	l2.loadFromFile("Resources/maincharacter.png", sf::IntRect(104, 1, 136, 62));
	//l3.loadFromFile("Resources/maincharacter.png", sf::IntRect(262, 17, 13, 13));
	//std::vector<sf::Texture> leftAnimTextures{ l1,l2,l3 };
	std::vector<sf::Texture> leftAnimTextures{ l1,l2};

	//up animation
	sf::Texture u1, u2, u3;
	u1.loadFromFile("Resources/maincharacter.png", sf::IntRect(34, 62, 68, 124));
	u2.loadFromFile("Resources/maincharacter.png", sf::IntRect(0, 62, 33, 124));
	u3.loadFromFile("Resources/maincharacter.png", sf::IntRect(69, 62, 103, 124));
	std::vector<sf::Texture> upAnimTextures{ u1,u2,u3 };

	//down animation
	//sf::Texture d1, d2, d3;
	//d1.loadFromFile("Resources/PacManSprites.png", sf::IntRect(230, 49, 13, 13));
	//d2.loadFromFile("Resources/PacManSprites.png", sf::IntRect(246, 49, 13, 13));
	//d3.loadFromFile("Resources/PacManSprites.png", sf::IntRect(262, 49, 13, 13));
	//std::vector<sf::Texture> downAnimTextures{ d1, d2, d3 };

	animations[0] = new Animation(leftAnimTextures);
	animations[1] = new Animation(rightAnimTextures);
	animations[2] = new Animation(upAnimTextures);
	//animations[3] = new Animation(downAnimTextures);
	//animations[4] = new Animation(deathAnimTextures, false, 0.20f);
}


void People::draw(RenderWindow& _window)
{
	_window.draw(people);
}

