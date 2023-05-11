#include "buttons.hpp"

Button::Button(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), moverRect(mov){
    srcRect = {0,0,0,0}; //default constructor
}
Button::Button(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, SDL_Rect src): Unit(rend, ast), moverRect(mov){
    srcRect = src; //constructor which defines the source dimensions of the object
}

void Button::draw(){ 
        Unit::draw(srcRect, moverRect); //draw object at standard position if no shift
        
    }

bool Button::button_pressed(int mouseX, int mouseY ){
    if (mouseX> srcRect.x && mouseX<srcRect.x+ srcRect.w && mouseY>srcRect.y && mouseY<srcRect.y+ srcRect.h)
    {
        return true;
    }

    return false;

}

// int Filler::check(int x, int y){ //decides whether game should continue of lose
//     if(x>50 && x<50+150 && y>500 && y<500+50){
//         //quits the game
//         return 2; //0 for continue, 1 for lost (used by gameplay), 2 for quit
//     }
//     if(x>600 && x<600+150 && y>500 && y<500+50){
//         //goes to next screen
//         return 0; //0 for continue
        
//     }

// }    
//  {50,500,150,50}, //button1 quit
//     {600,500,150,50} //button2 play/next
//     };