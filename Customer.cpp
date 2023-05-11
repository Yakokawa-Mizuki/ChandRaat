
#include <iostream>
#include "Customer.hpp"
using namespace std;


Customer::Customer(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov): Unit(rend, ast), moverRect(mov){
    //srcRect = {91, 63, 320, 400}; //nilu clap
    srcRect= {5402+500,169, 838+500,980};
}

Customer::Customer(SDL_Renderer* rend, SDL_Texture* ast, SDL_Rect mov, SDL_Rect src): Unit(rend, ast), moverRect(mov){
    srcRect = src;
}

void Customer::draw(){ //defining the area for turret rendering
    Unit::draw(srcRect, moverRect); //draw turret at standard position if no shift
    
}

// void Customer::change_action(int mood){//defining area for turret rendering
//         if (mood == 1 || mood == 2){
//         srcRect={6055, 1415, 1019, 1048}; //happy moods
//         //Unit::draw(srcRect, moverRect); //draw turret using Unit class
//         }
//         else if(mood == 3){
//         srcRect={4551, 1399, 940, 1133}; //sad mood
//         //Unit::draw(srcRect, moverRect); //draw turret using Unit class        
//         }
// }

void Customer::operator++(){
    srcRect = {6055, 1415, 1019, 1048};
}

void Customer::operator--(){
    srcRect={4551, 1399, 940, 1133};    
}

void Customer::operator++(int c){
    srcRect = {4502,169,838,980};
}

// Customer::~Customer(){
//     cout<<"Customer deleted"<<endl;
// }