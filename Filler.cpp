#include "Filler.hpp"
#include<iostream>

//**********************COMMENTED********************//
void Filler::drawObjects(){
    // callS draw functions of all the objects here
    for(Object* o: filler){
        o-> draw();
    }
}

Filler::Filler(){ //default constructor
}

Filler::Filler(SDL_Renderer* rend, SDL_Texture* ast, list<Object*>f):Screen(rend,ast){
    filler = f; //intializes the list with the list coming from the driver class
}

void Filler::fire(){
    cout <<"The Filler objects do not require hints"<<endl;
}

// Filler::~Filler(){        //deconstructor
//     for(Object* o:filler){
//         delete [] o;
//         o=nullptr;
//     }
//     delete [] nilou;
//     nilou = nullptr;
// }

int Filler::check(int x, int y){ //decides whether game should continue of lose
    if(x>50 && x<50+150 && y>500 && y<500+50){
        //quits the game
        return 2; //0 for continue, 1 for lost (used by gameplay), 2 for quit
    }
    if(x>600 && x<600+150 && y>500 && y<500+50){
        //goes to next screen
        return 0; //0 for continue
        
    }

}    
