#pragma once
#include <SDL.h>
// Unit class is well implemented, no need to change it
//*****************************COMMENTED**********************//
class Unit{
    SDL_Renderer* gRenderer; //the texture and assets used to draw the objects
    SDL_Texture* assets;
public: 
    Unit(SDL_Renderer*, SDL_Texture*); //constructor
    void draw(SDL_Rect srcRect, SDL_Rect moverRect); //draw function
};
