#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <stdio.h>
#include <SDL_mixer.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <ctime> 
#include <sstream>    
using namespace std;
#include <thread> 
#include "LTexture.hpp"

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    //timer font and colour
    TTF_Font* gFont;
    SDL_Color textColor;
    SDL_Surface* timeSurface;
    SDL_Texture* timeTexture;
    SDL_Rect timeRect;
    LTexture gPromptTextTexture;
    LTexture gTimeTextTexture;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    //global reference to png image sheets
    SDL_Texture* assets=NULL;
    //playing the music
    Mix_Music *bgMusic_l1 = NULL;
    Mix_Music *bgMusic_l2 = NULL;
    Mix_Music *bgMusic_l3 = NULL;
    Mix_Music *bgM1 = NULL;
    Mix_Music *bgM2 = NULL;
    Mix_Music *bgM3 = NULL;

int i;
int timeRemaining;
public:

    bool init();
    bool loadMedia();
    void close();
    SDL_Texture* loadTexture( std::string path );
    void run();
};

