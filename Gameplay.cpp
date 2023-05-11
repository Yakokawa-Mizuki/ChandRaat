#include "Gameplay.hpp"
#include "Screenmaster.hpp"
#include<iostream>


void Gameplay::drawObjects(){
    // call draw functions of all the objects here
    for(Object* o: items){
        o-> draw();
    }
    for (Object* o : tasks){
        o->draw();
    }
}

Gameplay::Gameplay(){
}

Gameplay::Gameplay(SDL_Renderer* rend, SDL_Texture* ast, list<Object*> i, list<Object*> t, Customer* n):Screen(rend,ast){
    items = i;
    tasks = t;
    nilou = n;
}

//makes the items jump when h key is pressed in game.cpp
void Gameplay::fire(){
    cout<<"Hinto desu yo!!"<<endl;
    for(Object* o: items){
        o->jump();
    }
}


int objs_found=0; //number of objects found uptill now
int mitsake=0; //wrong clicks


int Gameplay::check(int x, int y){
    for(Object* o:items){

        SDL_Rect a = o->check(); // returns moverrect of obj
       
            if(x>a.x && x<a.w+a.x && y>a.y && y<a.h+a.y){ // if the mouse click position matches the object position
                -- *o; // disappear the object by operator overloading
                o = nullptr; 
                delete [] o; //delete it from memory
               
                objs_found++; //if correct click then objs found ++;
                cout<< "Number of Objects Found: "<<objs_found<<endl;
                mitsake = 0;

                if((rand() % (100 - 50 + 1) + 50)%2==1){ //50 50 chance by lower limit 100, upper limit 50
                    ++ *nilou; // randomly changes character's expressions by operator overloading
                }
                else{
                    (*nilou) ++;
                }
                
            }
            else{
                mitsake++;
                if(mitsake==9){
                    -- *nilou; //nilu becomes sad through operator overloading
                    mitsake=0;
                }
            }
        }
        //helps in changing screens in game.cpp
        if(objs_found==7){
            objs_found=0;
            return objs_found;

        }
    
    return 1;
}

