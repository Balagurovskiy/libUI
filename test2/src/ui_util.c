
# include "ui_util.h"
# include "ui_window.h"
SDL_Texture * ui_load_texture(char * path)
{
	SDL_Texture* new_texture = NULL;
	SDL_Surface* loaded_surface;

	new_texture = NULL;
	loaded_surface = IMG_Load(path);
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

//#####################################################
t_ui_color	ui_new_color(int r, int g, int b)
{
	t_ui_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_ui_setup ui_new_setup(int w, int h, int x, int y)
{
	t_ui_setup setup;

	setup.width = w;
	setup.height = h;

	setup.posx = x;
	setup.posy = y;
	return (setup);
}

