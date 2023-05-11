#pragma once
#include "ScreenV.hpp"
#include "Customer.hpp"
#include<list>
#include<vector>
using namespace std;

class Screenmaster;
class Gameplay:public Screen{
    list<Object*> items;
    list<Object*> tasks;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    Customer* nilou;
    public:
    Gameplay();
    Gameplay(SDL_Renderer *, SDL_Texture *,list<Object*> i,list<Object*> t, Customer* n); //constructor
    void drawObjects() override;     
    void fire();    //this functions does two things: shifts the turret back and forth and creates a new bullet to be fired
    int check(int, int y) override;
    int all_found();
    //~Gameplay(); //deconstructor

    friend class Screenmaster;

    list<Object*>::iterator iter;  //iterator for the list of Bullet* objects

};