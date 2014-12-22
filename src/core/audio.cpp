#include "audio.h"
#include "fmod.h"

#include <QFile>
#include <QCache>
class Sound;
static FMOD_SYSTEM *System;
static QCache<QString, Sound> SoundCache;


class Sound{
public:
    Sound(const QString fileName)
        :sound(NULL),channel(NULL)
    {
        if(System)
            FMOD_System_CreateSound(System,fileName.toLatin1(),FMOD_DEFAULT, NULL, &sound);
    }
    ~Sound()
    {
        if(sound)
            FMOD_Sound_Release(sound);
    }

    void play(){
        if(sound)
        {
            FMOD_RESULT result = FMOD_System_PlaySound(System, FMOD_CHANNEL_FREE, sound, false, &channel);
            if(result == FMOD_OK)
            {
                FMOD_Channel_SetVolume(channel, 2);
                FMOD_System_Update(System);
            }
        }
    }

    bool isPalying(){
        if(channel == NULL)
            return false;
        FMOD_BOOL is_playing = false;
        FMOD_Channel_IsPlaying(channel, &is_playing);
        return is_playing;
    }


private:
    FMOD_SOUND *sound;
    FMOD_CHANNEL *channel;

};




void Audio::init()
{
    FMOD_RESULT result = FMOD_System_Create(&System);
    if(result == FMOD_OK)
    {
        FMOD_System_Init(System, 100, 0, NULL);
    }
}


void Audio::play(const QString &filename)
{
    Sound *sound = SoundCache[filename];
    if(sound == NULL)
    {
        sound = new Sound(filename);
        SoundCache.insert(filename,sound);
    }
    if(sound->isPalying())
    {
        return;
    }
    sound->play();
}

