#pragma once
#include "Common.h"
#include "Animation/Animator.h"
#include "Animation/Animation.h"

using namespace sf;

class Rendernpc
{
private:
	Animator* animator;
	Animation* animations[5];//left, right, up, down, death
	Texture texture;
	Texture texture1;
public:
	Rendernpc();
	void SetupAnimations();
};