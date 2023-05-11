#include <iostream>
#include "Object.hpp"
using namespace std;
//********************************COMMENTED*****************************//

Object::Object(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), moverRect(mov){
    srcRect = {0,0,0,0}; //default constructor
}
Object::Object(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, SDL_Rect src): Unit(rend, ast), moverRect(mov){
    srcRect = src; //constructor which defines the source dimensions of the object
}

void Object::draw(){ 
        if(moverRect.y<point.y){ //moveRect decreases if hint function is called, which is why
        //the point object is used for comparison
                moverRect.y += 10; //if shifted bring it downwards by 10
                Unit::draw(srcRect,moverRect); //drawing the object
        }   
        else{
        Unit::draw(srcRect, moverRect); //draw object at standard position if no shift
        }
    }
void Object::taskbar(){ //to display the objects needed, at the bottom of the page
        moverRecttt.y = place_y; 
        moverRecttt.x = place_x;
        Unit::draw(srcRect, moverRecttt);
        place_x +=200; //increases so objects can be made side by side along the taskbar
}
void Object::jump(){//defining area for object rendering
        while(moverRect.y > point.y - 20){ //defining how far above the object should go
                moverRect.y -= 10; //increase y for jump
                Unit::draw(srcRect, moverRect); //draw object using Unit class
        }

}
SDL_Rect Object::check(){
        return moverRect; //used to compare the position of mouse with position of object by the gameplay screens
}

void Object::operator --(){ //functions as a deletion operator
        srcRect = {0,0,0,0}; //brings the source dimensions to 0 so object disappears.
}