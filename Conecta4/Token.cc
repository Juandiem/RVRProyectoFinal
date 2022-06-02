#include "Token.h"
#include "Message.h"
#include "SDLTexture.h"

Token::Token(const char* n, SDLTexture * text):color(n)
{
    if(color == 'r')
        texture = app->getTextureManager()->getTexture(Resources::TextureId::RedToken);
    else
        texture = app->getTextureManager()->getTexture(Resources::TextureId::YellowToken)
}

Token::~Token()
{
}

void Token::setPosition(const Vector2D &newPos)
{
    pos = newPos;
}

void Token::setSize(int16_t newSize)
{
    size = newSize;
}

void Token::setTexture(SDLTexture *newTexture)
{
    texture = newTexture;
}

SDLTexture *Token::getTexture()
{
    return texture;
}

Vector2D Token::getPos()
{
    return pos;
}

int16_t Token::getSize()
{
    return size;
}

char Token::getColor(){
    return color;
}