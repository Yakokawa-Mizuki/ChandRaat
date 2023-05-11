#pragma once
#include <list>
#include "Filler.hpp"
#include "Gameplay.hpp"
#include "Customer.hpp"
using namespace std;
class Screenmaster{
    private:
    //objects of gameplay screens
    list<Object*> supermarket;
    list<Object*> furniture;
    list<Object*> meena;
  //objects of filler screens
    list<Object*> screen1;
    list<Object*> screen2;
    list<Object*> screen3;
    list<Object*> winning;
    list<Object*> losing;

    //task bars that show up at the bottom
    list<Object*> tasks_meena;
    list<Object*>tasks_supermarket;
    list<Object*>tasks_furniture;

   
  
    //src for all items in meena
    SDL_Rect src_meena[7] = {
    {384, 460, 341, 463},
    {921, 456, 473, 481},
    {1618, 561, 394, 287},
    {2082, 485, 741, 365},
    {2981, 501, 578, 443},
    {461, 1179, 407, 444},
    {1220, 1209, 367, 339}
};

    SDL_Rect src_supermarket[7] = {
        {3824, 2695, 356, 368},
        {2817, 2562, 675,926},
        {4391, 3644, 319,421},
        {6212, 3637, 363,412},
        {5905, 4206, 317,416},
        {6798, 4104, 521,442},
        {7263, 3632, 373,368}
    };
    SDL_Rect filler_mov[4] = {
    {500,70,300,350}, //nilou
    {30,50,480,400},//text
    {50,500,150,50}, //button1 quit
    {600,500,150,50} //button2 play/next
    };
    SDL_Rect src_furniture[7] = {
    {897, 1904, 791, 558}, // ammi k jehaz k bartan
    {1853, 1933, 451, 613}, // khoya khoya chand
    {476, 1972, 276, 557}, // parde
    {2395, 2019, 1009, 258}, // lighten jo ke k badalot nhi chalen gi
    {3639, 2077, 478, 419}, // bedsheet takiye
    {499, 2739, 790, 458}, // plates
    {1385, 2677, 931, 601} // carpet
    };
    SDL_Rect sl1[4] = {
    {6055,1415,1019,1048}, //nilou
    {216,5545,3126,2309+250}, //text
    {6835,5317,1052,333}, //quit
    {6991,4962,653,244} //play
    };
    SDL_Rect sl2[4] = {
    {6055,1415,1019,1048}, //nilou
    {3779,5090,1940,1514}, //text 
    {6835,5317,1052,333}, //quit
    {6912,5801,815,267} //next  
    };
    SDL_Rect sl3[4] = {
    {6055,1415,1019,1048}, //nilou
    {3343,6716,1533,1059}, //text  
    {6835,5317,1052,333}, //quit
    {6912,5801,815,267} //next
    }; 
    SDL_Rect game_won[4] = {
    {4502,169,838,980}, //nilou
    {4998,7219,1348,835}, //text
    {6835,5317,1052,333}, //quit
    {5084,6756,1102,314} //replay    
    };
    SDL_Rect game_lost[4] = {
    {4551,1399,940,1133}, //nilou
    {6358,6129,1829,1118}, //text
    {6835,5317,1052,333}, //quit
    {5084,6756,1102,314} //replay
    };

    //creating objects that will be used throughout the game
    SDL_Rect s_meena;
    SDL_Rect s_furniture;
    SDL_Rect s_supermarket;
    SDL_Rect s_filler;
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    //screen objects of type gameplay and filler
    Gameplay Supermarket;
    Gameplay Furniture;
    Gameplay Meena;
    Filler intro;
    Filler slide1;
    Filler slide2;
    Filler won;
    Filler lost;
    Screen* screen;

    Customer *Nilu; //character that shows on screen
    public:
    Screenmaster(SDL_Renderer*, SDL_Texture*);
    void draw_screen(int choice);
    void hint(int choice);
    void reset(SDL_Renderer* rend, SDL_Texture* ast);
    int check(int choice, int, int);
    SDL_Rect give_dimensions(int choice);
    ~Screenmaster();

};