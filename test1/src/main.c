//ft_putstr("EXCEPTION > input > invalid argument\n");
// ft_str_contains(argv[1], ".doom\0")
//----------------------------------
//////////////////

# include "ui_window.h"

SDL_Texture * load_texture(char * path)
{
	SDL_Texture* new_texture = NULL;

	SDL_Surface* loaded_surface = IMG_Load(path);
	if( loaded_surface == NULL )
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	else
	{
        new_texture = SDL_CreateTextureFromSurface( NULL, loaded_surface );///NULL -> renderer
		if( new_texture == NULL )
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		SDL_FreeSurface( loaded_surface );
	}
	return (new_texture);
}

				// SDL_Rect bottomViewport;
				// bottomViewport.x = 0;
				// bottomViewport.y = SCREEN_HEIGHT / 2;
				// bottomViewport.w = SCREEN_WIDTH;
				// bottomViewport.h = SCREEN_HEIGHT / 2;
				// SDL_RenderSetViewport( gRenderer, &bottomViewport );

				
				// //Render texture to screen
				// SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
//----------------------------------
int sdl_init()
{
	int success = 1;

	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); //ERROR
		success = 0;
	}
	else
	{
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!"); //ERROR
		}
	}

	return success;
}

//----------------------------------


//////////////  FIND BY TITLE ??????

//////////////  create MAIN window all close; all minimize\; add more win types : main;bars;modals;draw

////////////// t_ui_window gettersss????

////////////// parser for window patterns???????

////////////// paterns with viewpoints end textures that will copy to win renderer 

int main(void)
{
	t_ui_win_handler window;

	if (sdl_init())
	{
		window = new_ui_win_handler();

		window.set_dimension(SCREEN_WIDTH, SCREEN_HEIGHT);
		window.set_position(0, 0);
		window.set_color(111, 111, 111);
		window.set_title("window A*");
		window.set_resizable();
		window.set_focus_key('1');
		window.create();

		window.set_dimension(SCREEN_WIDTH / 4, (SCREEN_HEIGHT / 2 - 10));
		window.set_position(SCREEN_WIDTH + 5, 0);
		window.set_color(211, 211, 211);
		window.set_title("window B");
		window.set_focus_key('2');
		window.create();

		window.set_dimension(SCREEN_WIDTH / 4, (SCREEN_HEIGHT / 2 - 10));
		window.set_position(SCREEN_WIDTH + 5, (SCREEN_HEIGHT / 2 + 55));
		window.set_title("window C");
		window.set_focus_key('3');
		window.create();

		// window.set_dimension(300, 200);
		// window.set_position(100, 100);
		// window.set_title("window hidden");
		// window.set_focus_key('q');
		// window.set_hidden();
		// window.create();

		// window.set_dimension(300, 200);
		// window.set_position(300, 100);
		// window.set_title("window hidden1");
		// window.set_focus_key('w');
		// window.set_hidden();
		// window.create();

		//Main loop flag
		int status = 1;
		//Event handler
		SDL_Event e;

		//While application is running
		while(status)
		{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
				window.pull_event(&status, e);
			//clears render; make update only focused?
			window.update(&status);
		}
		window.destroy();
	} 
	else 
	{
		printf( "sdl_init_status error\n" );
	}
	// system("leaks gui");
	return 0;
}