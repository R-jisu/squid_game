#include "AudioManager.h"

#include <iostream>
//사운드 로딩
AudioManager::AudioManager()
{

    GunBuffer.loadFromFile(AUDIO_GUN);
    GunSound.setBuffer(GunBuffer);

    youngheeBuffer.loadFromFile(AUDIO_YOUNGHEE);
    youngheeSound.setBuffer(youngheeBuffer);
}
//상황에 따라 사운드플레이
void AudioManager::PlaySound(Sounds soundType, bool loop, int volume)
{
    //new way
    switch (soundType)
    {
    case Sounds::Gun:
        GunSound.setLoop(loop);
        GunSound.setVolume(volume);
        GunSound.play();
        break;
    case Sounds::younghee:
        youngheeSound.setLoop(loop);
        youngheeSound.setVolume(volume);
        youngheeSound.play();
        break;
    }

}
//사운드멈춤
void AudioManager::StopSound(Sounds soundType)
{
    switch (soundType)
    {
    case Sounds::Gun:
        GunSound.stop();
        break;
    case Sounds::younghee:
        youngheeSound.stop();
        break;
    case Sounds::None:
        youngheeSound.stop();
        GunSound.stop();
        break;
    }
}

bool AudioManager::IsPlayingAudio(Sounds soundType)
{
    switch (soundType)
    {
    case Sounds::Gun:
        return GunSound.getStatus() == GunSound.Playing;
        break;
    case Sounds::younghee:
        return youngheeSound.getStatus() == youngheeSound.Playing;
        break;
    }
}