#pragma once
#include "Unit.hpp"
//************************COMMENTED**********************//
class Customer:public Unit{
    private: //draw objects
    SDL_Rect srcRect, moverRect;
    public:
    Customer(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Rect mov); //default constructor
    Customer(SDL_Renderer* gRend, SDL_Texture* ast, SDL_Rect mov, SDL_Rect src); //constructor
    void draw(); //drawing the customer
    void operator ++(); //prefix operator improves Nilou's mood
    void operator --(); //decrement operator makes Nilou sed, like me when I was unable to
    //solve the publishing company question
    void operator ++(int c); //postfix operator also makes Nilou happy, using another picture
    //~Customer(); //deconstructor
};