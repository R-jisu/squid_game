#include "NPC_GEN.h"
#include <random>
using namespace std;
using namespace sf;

NPC_GEN::NPC_GEN() 
{
	//texture.loadFromFile("Resources/npc.png", sf::IntRect(0, 62, 35, 124));

	for(int num = 0; num < 4; num++) 
	{
		npc p(rand()%500, rand() % 20 + 10);
		npcs.push_back(p);
	}
}

bool NPC_GEN::Die(const float& deltaTime)
{
	for (auto& _e : npcs)
	{
		return _e.Die(deltaTime);
	}
}
void NPC_GEN::update(const float& deltaTime)
{
	for (auto& _e : npcs)
	{
		_e.update(deltaTime);
	}
}

void NPC_GEN::draw(RenderWindow& _window)
{
	for (auto& _e : npcs)
	{
		_e.draw(_window);
	}
}