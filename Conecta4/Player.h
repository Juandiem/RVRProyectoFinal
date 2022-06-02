#pragma once
#include "Vector2D.h"
#include <SDL2/SDL.h>
#include <string>
class SDLTexture;
 
class Player{
private:

    std::string nick;

public:
    /**
     * @param s dirección del servidor
     * @param p puerto del servidor
     * @param n nick del usuario
     */
    Player(const char * n);
    ~Player();

    std::string getNick(){return nick;}
};