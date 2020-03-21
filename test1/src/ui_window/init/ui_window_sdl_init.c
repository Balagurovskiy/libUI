
# include "ui_window.h"

int win_new_sdlwin()
{
	t_ui_win * win;

	win = win_storage("#get");
	if (win == NULL)
		return (0);
	if (win->setup.title == NULL)
		return (0);
	if (win->setup.w < 10 || win->setup.h < 10)
		return (0);
	win->sdlwin = SDL_CreateWindow(win->setup.title, 
									win->setup.x, 
									win->setup.y, 
									win->setup.w, 
									win->setup.h, 
									SDL_WINDOW_SHOWN | 
									win->resizable);
	if (win->sdlwin == NULL)
		return (0);
	return (1);
}

int win_new_sdlrenderer()
{
	t_ui_win * win;

	win = win_storage("#get");
	if (win == NULL)
		return (0);
	if (win->sdlwin == NULL)
		return (0);
	win->sdlrenderer = SDL_CreateRenderer(win->sdlwin, -1, 
										SDL_RENDERER_ACCELERATED |
										SDL_RENDERER_PRESENTVSYNC);
	if(win->sdlrenderer == NULL)
	{		
		SDL_DestroyWindow(win->sdlwin);
		win->sdlwin = NULL;
		return (0);
	}
	SDL_SetRenderDrawColor(win->sdlrenderer, 
						win->setup.r, win->setup.g, win->setup.b, 0xFF);
	win->id = SDL_GetWindowID(win->sdlwin);
	return (1);
}

int win_init()
{
	t_ui_win * win;

	win = win_storage("#get");
	if(win_new_sdlwin())
	{
		// win_storage("#get")->status.mouse_focus = 1;
		// win_storage("#get")->status.keyboard_focus = 1;
		if (win_new_sdlrenderer())
		{
			if (win->h)//Hide on close
			{
				SDL_HideWindow(win->sdlwin);// SDL_DestroyWindow(win->sdlwin);
				win->h = 1;
			}
			else
				win->status.shown = 1;
		}
		else
			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError());////ERROR
	}	
	else
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );////ERROR
	return (win->sdlwin != NULL &&	win->sdlrenderer != NULL);
}