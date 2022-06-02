#pragma once
#include "Vector2D.h"
#include <SDL2/SDL.h>
#include <string>
class SDLTexture;
 
class Token{
private:

    SDLTexture* texture = nullptr;
    Vector2D pos;
    int16_t size;
    char color;

public:
  
    Token(const char* n);
    ~Token();

    std::string getColour();

    SDLTexture* getTexture();
    Vector2D getPos();
    int16_t getSize();

    void setPosition(const Vector2D& newPos);
    void setSize(int16_t newSize);
    void setTexture(SDLTexture* newTexture);

};