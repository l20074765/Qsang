#include "clientplayer.h"
#include "client.h"
#include "engine.h"

#include <QTextDocument>
#include <QTextOption>


ClientPlayer::ClientPlayer(Client *client)
    :Player(client)
{
    mark_doc = new QTextDocument(this);
    mark_doc->setTextWidth(128);
    mark_doc->setDefaultTextOption(QTextOption(Qt::AlignRight));
}

ClientPlayer::~ClientPlayer()
{

}

