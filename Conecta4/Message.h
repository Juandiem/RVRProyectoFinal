#pragma once
#include "Serializable.h"
#include  <string>
#include <SDL2/SDL.h>
#include "ObjectInfo.h"


enum class MessageType: int8_t
{
    PLAYERINFO = 0,
    WIN = 1,
    LOSE = 2,
    PLACETOKEN = 3,
    GRIDFULL = 4,
    LOGIN  = 5,
    LOGOUT  = 6,
    NEWPLAYER = 7,
    UNDEFINED = 8    
};

class Message: public Serializable{
protected:
    size_t messageSize = sizeof(MessageType);
    MessageType type;
    SDL_Rect dimensions;
    char nick;
    ObjectInfo objectInfo;
    int column;

    //Metodos para la serializacion de nuestros mensajes
    void serializeTypeNick();
    void serializeObjectInfo();

    //Metodos para la construccion de los mensajes recibidos
    void constructTypeNick(char *bobj);
    void constructObjectInfo(char *bobj);

public:
    
    Message();
    Message(MessageType type_ ,char player_);
    Message(MessageType type_ ,char player_, int c);
    
    virtual ~Message();

    virtual void to_bin();
    virtual int from_bin(char * bobj);

    size_t getMessageSize();
    MessageType getMessageType();
    char getNick();
    ObjectInfo getObjectInfo()const{
        return objectInfo;
    }
    int getColumn();

    void setNick(char newNick);
    void setObjectInfo(const ObjectInfo& info){
        objectInfo= info;
    }
    void setMsgType(MessageType type);

};