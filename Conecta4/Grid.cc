#include "Grid.h"
#include "Message.h"
#include "SDLTexture.h"

Grid::Grid(char n) : nick(n)
{
    pos = offset;
    grid = new Token * [7];
	for (int i = 0; i < 7; i++) {
		grid[i] = new Token[6];
	}
    size = Vector2D(640,550);
}

Grid::~Grid()
{
}

void Grid::setPosition(const Vector2D &newPos)
{
    pos = newPos;
}

void Grid::setSize(int16_t newSize)
{
    size = newSize;
}

void Grid::setTexture(SDLTexture *newTexture)
{
    texture = newTexture;
}

SDLTexture *Grid::getTexture()
{
    return texture;
}

Vector2D Grid::getPos()
{
    return pos;
}

int16_t Grid::getSize()
{
    return size;
}

void Grid::placeToken(const char* n, int col){
    //Ponemos el token en la posicion mas baja del tablero de esa columna
    int freeRow = 6;
    while(freeRow >= 0 && grid[col][freeRow] != nullptr) freeRow--;
    if(freeRow >= 0){
        Token* t = new Token(n);
        t->setPosition(offset.getX() + 45 + 90 * col, offset.getY() + 45 + 90 * freeRow);
        grid[col][freeRow] = t;
    }
}

bool checkPlayerTokens(const char* n){
    bool conecta4 = false;

    //Vertical
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 3; j++){//hasta 3 pq es de arriba a abajo
            if(!conecta4){
                if(grid[i][j] != nullptr){
                    if(grid[i][j].getColor() == n){
                        int r = j + 1;
                        int seguidos = 1;
                        while(r < 6 && grid[i][r] != nullptr){
                            if(grid[i][r].getColor() == n){
                                r++;
                                seguidos++;
                            }
                            else r = 99;
                        }
                        if(seguidos >= 4)
                                conecta4 = true;
                    }

                }
            }
        }
    }
    //Horizontal
    if(!conecta4){
        for(int i = 0; i < 4; i++){//hasta 4 pq es de izquierda a derecha
            for(int j = 0; j < 6; j++){
                if(!conecta4){
                    if(grid[i][j] != nullptr){
                        if(grid[i][j].getColor() == n){
                            int c = i + 1;
                            int seguidos = 1;
                            while(c < 6 && grid[c][j] != nullptr){
                                if(grid[c][j].getColor() == n){
                                    c++;
                                    seguidos++;
                                }
                                else c = 99;
                            }
                            if(seguidos >= 4)
                                conecta4 = true;
                        }

                    }
                }
            }
        }
    }
    //Diagonal hacia derecha
    if(!conecta4){
        for(int i = 0; i < 4; i++){//hasta 4 pq es de izquierda a derecha
            for(int j = 0; j < 3; j++){//hasta 3 pq es de arriba a abajo
                if(!conecta4){
                    if(grid[i][j] != nullptr){
                        if(grid[i][j].getColor() == n){
                            int r = j + 1;
                            int c = i + 1;
                            int seguidos = 1;
                            while((r < 6 || c < 7) && grid[c][r] != nullptr){
                                if(grid[c][r].getColor() == n){
                                    r++;
                                    c++;
                                    seguidos++;
                                }
                                else r = 99;
                            }
                            if(seguidos >= 4)
                                conecta4 = true;
                        }

                    }
                }
            }
        }
    }
    //Diagonal hacia izquierda
    if(!conecta4){
        for(int i = 6; i > 2; i--){//hasta 2 pq es de derecha a izquierda
            for(int j = 5; j > 2; j--){//hasta 2 pq es de abajo a arriba
                if(!conecta4){
                    if(grid[i][j] != nullptr){
                        if(grid[i][j].getColor() == n){
                            int r = j - 1;
                            int c = i - 1;
                            int seguidos = 1;
                            while((r >= 0 || c >= 0) && grid[c][r] != nullptr){
                                if(grid[c][r].getColor() == n){
                                    r--;
                                    c--;
                                    seguidos++;
                                }
                                else r = -99;
                            }
                            if(seguidos >= 4)
                                conecta4 = true;
                        }

                    }
                }
            }
        }
    }

    return conecta4;
}

char getNick(){
    return nick;
}