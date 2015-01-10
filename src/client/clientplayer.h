#ifndef CLIENTPLAYER_H
#define CLIENTPLAYER_H

#include "player.h"
class Client;
class QTextDocument;



class ClientPlayer : public Player
{
public:
    explicit ClientPlayer(Client *client);
    ~ClientPlayer();


private:
    QTextDocument *mark_doc;
};

#endif // CLIENTPLAYER_H
