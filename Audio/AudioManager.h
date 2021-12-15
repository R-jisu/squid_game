#pragma once

#include "SFML/Audio.hpp"
#include "AudioAssets.h"


//ATTENTION!! I know there is much better ways to do a audio manager, but i am feeling really lazy and i just want to finish this project as soon as possible, so DONT JUDGE ME...thanks
class AudioManager
{
public:
	AudioManager();
	void PlaySound(Sounds soundType, bool loop, int volume);
	void StopSound(Sounds soundType = Sounds::None);
	bool IsPlayingAudio(Sounds soundType);
private:

	sf::SoundBuffer GunBuffer;
	sf::Sound GunSound;

	sf::SoundBuffer youngheeBuffer;
	sf::Sound youngheeSound;

};

