#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "NPC.h"
#include "Common.h"
#include "Animation/Animation.h"
#include "Animation/Animator.h"
#include "enemy.h"

using namespace std;
using namespace sf;

class NPC_GEN : public Younhee
{
private:
	vector<npc> npcs;
	float speed;
public:
	//Texture texture;
	NPC_GEN();
	bool Die(const float& deltaTime);
	void update(const float& deltaTime);
	void draw(RenderWindow& _window);
};
