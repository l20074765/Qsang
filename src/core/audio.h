#ifndef AUDIO_H
#define AUDIO_H

#include <QString>

class Audio{
public:
    static void init();
    static void play(const QString &filename);
};

#endif // AUDIO_H
