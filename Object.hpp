#pragma once
#include "Unit.hpp"
//*************************************COMMENTED***********************************//
class Object:public Unit{
    private: //draw objects
    SDL_Rect srcRect, moverRect; //used to draw objects
    SDL_Rect point = moverRect; //used to make objects jump
    SDL_Rect moverRecttt = moverRect; //used to draw objects along the taskbar
    int place_x, place_y; //used to draw objects along taskbar
    public:
    Object(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Rect mov); //default constructor
    Object(SDL_Renderer* gRend, SDL_Texture* ast, SDL_Rect mov, SDL_Rect src); //constructor
    void draw(); //drawing the object
    void jump(); //making object jump at the hint
    void taskbar(); //draws the taskbar along the screen
    void operator -- (); //minus operator removes object from the screen
    SDL_Rect check(); //used by the screen's check function
};