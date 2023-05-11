#include "game.hpp"
#include "Screenmaster.hpp"
#include<vector>
//#include "Gameplay.hpp"
bool Game::init()
{
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Chand Raat Chaos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				//initialize music loading
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
    gFont = TTF_OpenFont( "HoboStd.ttf", 20 );	
	assets = loadTexture("assets.png");
    gTexture = loadTexture("Untitled-1.png");
	if( gFont == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
	else
    {
        //Set text color as white
        SDL_Color textColor = { 0, 0, 0, 0};
        
        //Load prompt texture
        // if( !gPromptTextTexture.loadFromRenderedText( "Press Enter to Reset Start Time.", textColor, gRenderer, gFont) )
        // {
        //     printf( "Unable to render prompt texture!\n" );
        //     success = false;
        // }
    }
	//Clear screen
	SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( gRenderer );

	//Render textures
	gPromptTextTexture.render( ( SCREEN_WIDTH - gPromptTextTexture.getWidth() ) / 2, 0, gRenderer);
	gTimeTextTexture.render( 0, 0, gRenderer);
        
	//Update screen
	SDL_RenderPresent( gRenderer );

	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	bgMusic_l1 = Mix_LoadMUS( "line 2.wav" );
	bgMusic_l2 = Mix_LoadMUS("line 1.wav");
	bgMusic_l3 = Mix_LoadMUS("line 3.wav");
	bgM1 = Mix_LoadMUS("Supermarket.mp3");
	bgM2 = Mix_LoadMUS("Evergreen Wish.mp3");
	bgM3 = Mix_LoadMUS("Port Ormos.mp3");

	if(bgMusic_l1 == NULL){
		printf("Unable to load music: %s \n", Mix_GetError());
		success = false;
	}
	return success;
	
}

void Game::close()
{
	//Free loaded images
	gTimeTextTexture.free();
	gPromptTextTexture.free();

	//Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	//Destroy window
	TTF_CloseFont(gFont);
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	Mix_FreeMusic(bgMusic_l1);
	bgMusic_l1 = NULL;
	Mix_FreeMusic(bgMusic_l2);
	bgMusic_l2 = NULL;
	Mix_FreeMusic(bgMusic_l3);
	bgMusic_l3 = NULL;
	Mix_FreeMusic(bgM1);
	bgM1 = NULL;
	Mix_FreeMusic(bgM2);
	bgM2 = NULL;
	Mix_FreeMusic(bgM3);
	bgM3 = NULL;
	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}


void Game::run()
{
	bool quit = false;
	bool flag = false;
	SDL_Event e;
	Screenmaster Screen(gRenderer,assets);
	//Set text color as black
	SDL_Color textColor = { 0, 0, 0, 0 };

	//Current time start time
	Uint32 startTime = 0;

	int i = 1;
	//startTime = SDL_GetTicks();
	while( !quit )
	{
			//User requests quit
		Uint32 lastTick = SDL_GetTicks();
		int time_spent=(SDL_GetTicks() - startTime)/1000;
		int a=1; //set to 1 so that if no clicks are made and timer ends, player still loses
		
		while( SDL_PollEvent( &e ) != 0 )
		{

			

			if( e.type == SDL_QUIT )
			{
				quit = true;
				//Screen.~Screenmaster();
			}
			
			if(e.type == SDL_MOUSEBUTTONDOWN){
			
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				a = Screen.check(i,xMouse,yMouse); //if screen is gameplay type or filler type, it returns a accordingly

			
				cout<<"This is timespent "<<time_spent<<endl;
				
				if (a==0){  //FIXED//problem is k a hamesha 0 reh rha while this should give zero only if objs found are 7
					if (i<7){	// if screen is not winning screen	
						i++;
						Mix_HaltMusic();
						//startTime = 0;
					}
					else if (i>=7){ //if it's winning screen or losing screen and a==0;
						i=1; a= 1; // if they press play again then start again with screen 1
						Screen.reset(gRenderer,assets);
					}
				}
				
				else if (a==2){  // this is true for all filler screens 
					quit = true;
				}
				
			}
		
		
			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_h){
			//here the objects that need to be found, bounce as a hint for the player
				// Screen.draw_screen(i);
				Screen.hint(i);
			}
		}

		//mouse condition ends here
		
		if ( time_spent>=30){
					//cout<<"losing condition reached"<<endl;
					i=8; a=0;
					Mix_PlayingMusic() == 0;
				}
		
		if( Mix_PlayingMusic() == 0)
			{
				
				//Play the music
				switch (i){
				case 2:
					Mix_PlayMusic(bgM1,2);
					break;
				case 3:
					Mix_PlayMusic( bgMusic_l1, 2);
					break;
				case 4:
					Mix_PlayMusic( bgM2, 2);
					break;
				case 5:
					Mix_PlayMusic( bgMusic_l2, 2);
					break;
				case 6:
					Mix_PlayMusic( bgM3, 2);
					break;
				case 7:
					Mix_PlayMusic( bgMusic_l3, 2);
					break;
				default:
					break;
				}
				
			}

    	// Define the section of the image to display
		SDL_RenderClear(gRenderer); //removes everything from renderer
		//timeRect = { 10, 10, timeSurface->w, timeSurface->h };
		//timeTexture = SDL_CreateTextureFromSurface(gRenderer, timeSurface);
		SDL_Rect dim = Screen.give_dimensions(i);
		SDL_RenderCopy(gRenderer, gTexture, &dim, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		Screen.draw_screen(i);
		// //In memory text stream
		std::stringstream timeText;
			if (i==2 || i==4 || i==6){ 	//so the timer is only displayed on the game screen not the transition/filler screens
			timeText.str( "" );
			timeText << "Time remaining: " << 30-( (SDL_GetTicks() - startTime)/1000); 
			//why can't we use spent time here 

			//Render text
			if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor, gRenderer, gFont) )
			{
				printf( "Unable to render time texture!\n" );
			}


			gPromptTextTexture.render( 600, 574, gRenderer); //yeh rects of disyaplying timer on screen are also final 
 			gTimeTextTexture.render( 600, 574, gRenderer);
			}

			else{	//resetting the timer to 0. timer continues once we enter next game screen
 			startTime = SDL_GetTicks();
 		}   
			//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$44
			//yeh wala code is for resetting the timer to zero after every game screen
		
// 		if (i==2 || i==4 || i==6){	//so the timer is only displayed on the game screen not the transition/filler screens
// 			timeText.str( "" );
// 			timeText << "Seconds since start time " << (SDL_GetTicks() - startTime)/1000; 

// 			//Render text
// 			if( !gTimeTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor, gRenderer, gFont) )
// 			{
// 				printf( "Unable to render time texture!\n" );
// 			}


// 			gPromptTextTexture.render( 300, 470, gRenderer); //yeh rects of disyaplying timer on screen are also final 
// 			gTimeTextTexture.render( 300, 470, gRenderer);
// 		}
// 		else{	//resetting the timer to 0. timer continues once we enter next game screen
// 			startTime = SDL_GetTicks();
// 		}   
// //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$4
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer

	    SDL_Delay(300);	//causes sdl engine to delay for specified miliseconds
	}
		
	
			
}

   