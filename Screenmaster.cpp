#include "Screenmaster.hpp"
#include <iostream>
Screenmaster::Screenmaster(SDL_Renderer* rend, SDL_Texture* ast){
    gRenderer = rend;
    assets = ast;
    int llw = 0;
    int ulw = 750;
    int llh = 0;
    int ulh = 350;
    //screen renderers
    s_supermarket = {309,0,3443,2777 };
	s_furniture = {3907,0,3435,3032};
	s_meena = {351,3032,3360,2967};
	s_filler = {4000,3172,3400,2400};
   
    Nilu = new Customer(gRenderer, assets, {42, 450, 150, 120});

    for (int i=0; i<7; i++){
        int task_barpos=80;
        //creating new object and pushing it the items list for the respective screen
        Object* m1 = new Object(gRenderer, assets,{(rand() % (ulw - llw + 1)) + llw, (rand() % (ulh - llh + 1)) + llh, 50,50},src_meena[i]);
        meena.push_back(m1);
        //creating new object(with same src as above) and pushing it the taskbar list for the respective screen
        Object* m11 = new Object(gRenderer, assets, {220+task_barpos*i, 500, 50, 50}, src_meena[i]);
        tasks_meena.push_back(m11);

        //same thing for supermarket screen
        Object* s1 = new Object(gRenderer, assets,{(rand() % (ulw - llw + 1)) + llw, (rand() % (ulh - llh + 1)) + llh, 50,50},src_supermarket[i]);
        supermarket.push_back(s1);
        Object* s11 = new Object(gRenderer, assets, {220+task_barpos*i, 500, 50, 50}, src_supermarket[i]);
        tasks_supermarket.push_back(s11);

        //same thing for furniture screen
        Object* f1 = new Object(gRenderer, assets,{(rand() % (ulw - llw + 1)) + llw, (rand() % (ulh - llh + 1)) + llh, 50,50},src_furniture[i]);
        furniture.push_back(f1);
        Object* f11 = new Object(gRenderer, assets, {220+task_barpos*i, 500, 50, 50}, src_furniture[i]);
        tasks_furniture.push_back(f11);
    }
    for (int i=0;i<4;i++){
        //creating and pushing objects into list for filler screens
        Object* sc1 = new Object(gRenderer,assets,filler_mov[i],sl1[i]);
        screen1.push_back(sc1);

        Object* sc2 = new Object(gRenderer,assets,filler_mov[i],sl2[i]);
        screen2.push_back(sc2);
        
        Object* sc3 = new Object(gRenderer,assets,filler_mov[i],sl3[i]);
        screen3.push_back(sc3);

        Object* w = new Object(gRenderer,assets, filler_mov[i], game_won[i]);
        winning.push_back(w);

        Object* l = new Object(gRenderer,assets,filler_mov[i],game_lost[i]);
        losing.push_back(l);
    }
}

void Screenmaster::draw_screen(int choice){ //draws the desired screen based on the integer input provided in game.cpp
//cases 1,3,5,7,8 are objects of filler
//cases 2,4,6 are objects of gameplay
    switch (choice)
    {
    case 1:
        intro = Filler(gRenderer,assets, screen1); //intro screen
        screen = &intro;  //current screen pointer points to reference of intro screen
        screen->drawObjects(); // objects displayed on the sceen
        break;
    case 2:
        Supermarket = Gameplay(gRenderer, assets, supermarket, tasks_supermarket,Nilu); //initializing screen using constructor
        Nilu->draw();
        screen = &Supermarket;
        screen->drawObjects();
        break;
    case 3:
        slide1 = Filler(gRenderer,assets, screen2); // filler after supermarket
        screen = &slide1;
        screen->drawObjects();
        break;
    case 4:
        Furniture = Gameplay(gRenderer, assets, furniture, tasks_furniture,Nilu);
        Nilu->draw();
        screen = &Furniture;
        screen->drawObjects();
        break;
    case 5:
        slide2 = Filler(gRenderer,assets, screen3);  // filler after furniture
        screen = &slide2;
        screen->drawObjects();
        break;
    case 6:
        Meena = Gameplay(gRenderer,assets, meena, tasks_meena,Nilu);
        Nilu->draw();
        screen = &Meena;
        screen->drawObjects();
        break;
    case 7:
        won = Filler(gRenderer,assets, winning); // filler after meena 
        screen = &won;
        screen->drawObjects();
        break;
    default:
        lost = Filler(gRenderer,assets,losing);
        lost.drawObjects();
        break;
    }

}

// calls the fire function based on case, which gives a hint to the user
void Screenmaster::hint(int choice){
    switch (choice)
    {
    case 2:
        Supermarket.fire();
        break;
    case 4:
        Furniture.fire();
        break;
    case 6:
        Meena.fire();
        break;
    default:
        slide2.fire();
        break;
    } 
}

//check functions return useful information that help in changing screens in game.cpp
//refer to gameplay and filler 
int Screenmaster::check(int choice, int x, int y){
    switch (choice)
    {
    case 2:
        return Supermarket.check(x,y); // FIXEDD NOW :: the problem is that this is always returning 0
        break;
    case 4:
        return Furniture.check(x,y);
        break;
    case 6:
        return Meena.check(x,y);
        break;
    default:
        return won.check(x,y); 
        break;
    }     
}

//returns SDL_rects
SDL_Rect Screenmaster::give_dimensions(int choice){
    switch (choice)
    {
    case 2:
        return s_supermarket;
        break;
    case 4:
        return s_furniture;
        break;
    case 6:
        return s_meena;
        break;
    default:
        return s_filler;
        break;
    }    
}


//destructor to delete all the dynamically created objects
Screenmaster::~Screenmaster(){
    cout<<"Destructor"<<endl;
    delete [] Nilu;
    Nilu = nullptr;
    for(Object* o:supermarket){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:meena){
        delete [] o;
        o = nullptr;
    } 
    for(Object* o:furniture){
        delete [] o;
        o = nullptr;
    }   
    for(Object* o:screen1){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:screen2){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:screen3){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:winning){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:losing){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:tasks_supermarket){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:tasks_meena){
        delete [] o;
        o = nullptr;
    }
    for(Object* o:tasks_furniture){
        delete [] o;
        o = nullptr;
    }
    delete [] screen;
    screen = nullptr;
}

void Screenmaster::reset(SDL_Renderer* rend, SDL_Texture* ast){
    int llw = 0;
    int ulw = 750;
    int llh = 0;
    int ulh = 350;
    for(Object* o:supermarket){
        -- *o;
        delete [] o;
        o = nullptr;
    }
    for(Object* o:meena){
        -- *o;
        delete [] o;
        o = nullptr;
    } //hello
    for(Object* o:furniture){
        -- *o;
        delete [] o;
        o = nullptr;
    } 

    for (int i=0; i<7; i++){
        //creating new object and pushing it the items list for the respective screen
        Object* m1 = new Object(rend, ast,{(rand() % (ulw - llw + 1)) + llw, (rand() % (ulh - llh + 1)) + llh, 50,50},src_meena[i]);
        meena.push_back(m1);

        //same thing for supermarket screen
        Object* s1 = new Object(rend, ast,{(rand() % (ulw - llw + 1)) + llw, (rand() % (ulh - llh + 1)) + llh, 50,50},src_supermarket[i]);
        supermarket.push_back(s1);

        //same thing for furniture screen
        Object* f1 = new Object(rend, ast,{(rand() % (ulw - llw + 1)) + llw, (rand() % (ulh - llh + 1)) + llh, 50,50},src_furniture[i]);
        furniture.push_back(f1);
    }
    
}