
#pragma once
#include "Unit.hpp"


class Button: public Unit {
    SDL_Rect srcRect, moverRect; //used to draw objects
    
    public:
    Button(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Rect mov); //default constructor
    Button(SDL_Renderer* gRend, SDL_Texture* ast, SDL_Rect mov, SDL_Rect src); //constructor
    void draw(); //drawing the object
    bool button_pressed(int x, int y);

};

