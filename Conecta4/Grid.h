#pragma once
#include "Vector2D.h"
#include <SDL2/SDL.h>
#include <string>
#include "Token.h"

class SDLTexture;
 
class Grid{
private:

    SDLTexture* texture = nullptr;
    Vector2D pos;
    Vector2D offset = Vector2D(90,60);
    Vector2D size;
    Token **grid;

public:
  
    Grid();
    ~Grid();

    SDLTexture* getTexture();
    Vector2D getPos();
    Vector2D getSize();

    void setPosition(const Vector2D& newPos);
    void setSize(Vector2D newSize);
    void setTexture(SDLTexture* newTexture);
    void placeToken(const char* n, int col);

};