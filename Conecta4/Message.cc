#include "Message.h"
#include <memory.h>
#include "Button.h"
#include <iostream>

Message::Message() : type(MessageType::UNDEFINED)
{
}
Message::Message(MessageType type_, char player_) : type(type_)
{
    nick = player_;
    objectInfo = ObjectInfo();
    //objectInfo.tam = player_->getPlayerTam();
    //objectInfo.pos = player_->getPlayerPos();
    column = -1;
}
Message::Message(MessageType type_ ,char player_, int c){
    nick = player_;
    column = c;
}

Message::~Message()
{
}

size_t Message::getMessageSize()
{
    return messageSize;
}

MessageType Message::getMessageType()
{
    return type;
}

void Message::to_bin()
{
    switch (type)
    {
    case MessageType::LOGIN:
    {
        serializeTypeNick();
        break;
    }

    case MessageType::LOGOUT:
    {
        serializeTypeNick();
        break;
    }  


     case MessageType::WIN:
    {
        serializeObjectInfo();
        break;
    }
     case MessageType::LOSE:
    {
        serializeObjectInfo();
        break;
    }

    case MessageType::PIEDRA:
    {
        serializeObjectInfo();
        break;
    }

    case MessageType::PAPEL:
    {
        serializeObjectInfo();
        break;
    }

     case MessageType::TIJERAS:
    {
        serializeObjectInfo();
        break;
    }

    case MessageType::PLAYERINFO:
    {
        serializeObjectInfo();
        break;
    }

    case MessageType::NEWPLAYER:
    {
        serializeObjectInfo();
        break;
    }
    
    }
}

int Message::from_bin(char *bobj)
{

    //reservamos memoria para coger el tipo de mensaje
    messageSize = sizeof(MessageType);
    alloc_data(messageSize);
    //coger el tipo de mensaje
    memcpy(static_cast<void *>(_data), bobj, messageSize);

    //Reconstruir la clase usando el buffer _data
    char *temp = _data;

    //Copiamos tipo
    memcpy(&type, temp, sizeof(MessageType));

    switch (type)
    {
    case MessageType::LOGIN:
    {
        std::cout << "LOGIN\n";
        constructTypeNick(bobj);
        break;
    }

    case MessageType::LOGOUT:
    {
        std::cout << "LOGOUT\n";
        constructTypeNick(bobj);
        break;
    }

    case MessageType::PLAYERINFO:
    {
        constructObjectInfo(bobj);
        break;
    }

     case MessageType::WIN:
    {
        constructObjectInfo(bobj);
        break;
    }

     case MessageType::LOSE:
    {
        constructObjectInfo(bobj);
        break;
    }


     case MessageType::PLACETOKEN:
    {
        constructObjectInfo(bobj);
        break;
    }

    case MessageType::NEWPLAYER:
    {
        std::cout << "NEWPLAYER\n";
        constructObjectInfo(bobj);
        break;
    }
 

    default:
        std::cout << "Ni LOG ni LOGOUT\n";
        break;
    }

    return 0;
}

char Message::getNick()
{
    return nick;
}

int Message::getColumn()
{
    return column;
}

void Message::setNick(char newNick)
{
    nick = newNick;
}

void Message::setMsgType(MessageType type_)
{
    type = type_;
}

void Message::serializeTypeNick()
{
    //calculamos el tamaño del mensaje

    messageSize = sizeof(MessageType) + sizeof(char) * 12;
    //reservamos la memoria
    alloc_data(messageSize);
    memset(_data, 0, messageSize);

    //Serializar los campos type
    char *temp = _data;

    //Copiamos tipo de mensaje a partir de la direccion que marca temp
    //almacenamos primero el tipo de mensaje
    memcpy(temp, &type, sizeof(MessageType));

    temp += sizeof(MessageType);

    //Copiamos el nombre a partir de la direccion que marca temp
    //despues almacenamos el resto de la informacion
    memcpy(temp, nick.c_str(), sizeof(char) * 12);
}

void Message::serializeObjectInfo()
{
    messageSize = sizeof(MessageType) + sizeof(char) * 12 + sizeof(ObjectInfo);

    //reservamos la memoria
    alloc_data(messageSize);

    memset(_data, 0, messageSize);

    //Serializar los campos type
    char *temp = _data;

    //Copiamos tipo de mensaje a partir de la direccion que marca temp
    //almacenamos primero el tipo de mensaje
    memcpy(temp, &type, sizeof(MessageType));

    temp += sizeof(MessageType);

    //Copiamos el nombre a partir de la direccion que marca temp
    //despues almacenamos el resto de la informacion
    memcpy(temp, nick.c_str(), sizeof(char) * 12);

    temp += sizeof(char) * 12;

    memcpy(temp, &objectInfo, sizeof(ObjectInfo));
}

void Message::constructTypeNick(char *bobj)
{
    messageSize = sizeof(MessageType) + sizeof(char) * 12;
    //reservamos la memoria
    alloc_data(messageSize);
    memcpy(static_cast<void *>(_data), bobj, messageSize);
    //Reconstruir la clase usando el buffer _data
    char *temp = _data;
    temp += sizeof(MessageType);
    //Se puede hacer porque es un string (\0)
    nick = temp;
}

void Message::constructObjectInfo(char *bobj)
{
    messageSize = sizeof(MessageType) + sizeof(char) * 12 + sizeof(ObjectInfo);
    //reservamos la memoria
    alloc_data(messageSize);
    memcpy(static_cast<void *>(_data), bobj, messageSize);
    //Reconstruir la clase usando el buffer _data
    char *temp = _data;
    temp += sizeof(MessageType);
    //Se puede hacer porque es un string (\0)
    nick = temp;

    temp += sizeof(char) * 12;
    memcpy(&objectInfo, temp, sizeof(ObjectInfo));
}