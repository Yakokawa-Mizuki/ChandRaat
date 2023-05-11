#include "Unit.hpp"
// Unit class is well implemented, no need to change it
//*************************COMMENTED************************//
Unit::Unit(SDL_Renderer* rend, SDL_Texture* ast): gRenderer(rend), assets(ast){
   //default constructor
}

void Unit::draw(SDL_Rect srcRect, SDL_Rect moverRect){  //draw function which draws objects
    SDL_RenderCopy(gRenderer, assets, &srcRect, &moverRect);
}