#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "NPC.h"
#include "Common.h"
#include "Animation/Animation.h"
#include "Animation/Animator.h"

using namespace std;
using namespace sf;

class NPC_GEN
{
private:
	vector<npc> npcs;
	float speed;
public:
	//Texture texture;
	NPC_GEN();
	void update(const float& deltaTime);
	void draw(RenderWindow& _window);
};
