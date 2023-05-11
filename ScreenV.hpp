#pragma once
#include "Object.hpp"
//**************************COMMENTED***********************************//
class Screen{ //pure virtual class
    SDL_Renderer* gRenderer;
    SDL_Texture* assets;
    public:
    Screen(); //default constructor
    Screen(SDL_Renderer*, SDL_Texture*); //constructor
    virtual void drawObjects()=0;  //void function which draws objects   
    virtual int check(int ,int)=0; //this check whether to move the screen to the next depending on which class
    //calls it
};