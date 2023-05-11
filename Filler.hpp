#pragma once
#include "ScreenV.hpp"
#include "Customer.hpp"
#include<list>
#include<vector>
using namespace std;
//****************************COMMENTED*******************************//

class Filler:public Screen{ //derived from virtual class screen
    list<Object*> filler; //list of objects to be drawn
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    public:
    Filler(); //default constructor
    Filler(SDL_Renderer *, SDL_Texture *,list<Object*> f); //constructor
    void drawObjects() override; //overriding the drawing function  
    void fire();
    int check(int, int) override; //checking whether any button has been pressed
    //~Filler(); //deconstructor
};