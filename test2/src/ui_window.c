
# include "ui_window.h"

t_ui_win_status	ui_winstatus_init()
{
	t_ui_win_status status;

	status.mousefocus = 0;
	status.keyboardfocus = 0;
	status.fullscreen = 0;
	status.minimized = 0;
	status.shown = 0;
	return (status);
}

t_ui_win	ui_win_init()
{
	t_ui_win	win;

	win.sdlwin = NULL;
	win.sdlrenderer = NULL;
	win.id = -1;
	win.resizable = 0;
	win.status = ui_winstatus_init();
	win.setup = ui_new_setup(0, 0, 0, 0);
	win.color = ui_new_color(0, 0, 0);
	win.title = "#";
	win.focuskey = '#';
	return (win);
}
//#####################################################

int ui_win_new_sdlwin(t_ui_win * win)
{
	if (win == NULL)
		return (0);
	if (win->title == NULL)
		return (0);
	win->sdlwin = SDL_CreateWindow(win->title,
									win->setup.posx,
									win->setup.posy,
									win->setup.width,
									win->setup.height,
									SDL_WINDOW_SHOWN |
									win->resizable);
	if (win->sdlwin == NULL)
		return (0);
	return (1);
}

int ui_win_new_sdlrenderer(t_ui_win * win)
{
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
						win->color.r, win->color.g, win->color.b, 0xFF);
	win->id = SDL_GetWindowID(win->sdlwin);
	return (1);
}

int ui_win_create(t_ui_win * win)
{
	if (win == NULL)
		return (0);
	if(ui_win_new_sdlwin(win))
	{
		if (ui_win_new_sdlrenderer(win))
			win->status.shown = 1;
		else
			printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError());////ERROR
	}	
	else
		printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );////ERROR
	return (win->sdlwin != NULL && win->sdlrenderer != NULL);
}
//#####################################################
void	ui_win_render(t_ui_win * win)
{
	if(!(win->status.minimized))
	{
		//Clear screen
		SDL_SetRenderDrawColor(win->sdlrenderer, 
							win->color.r, win->color.g, win->color.b, 0xFF );
		SDL_RenderClear(win->sdlrenderer);
		//Update screen
		SDL_RenderPresent(win->sdlrenderer);
	}
}

void	ui_win_focus(t_ui_win * win)
{
	if(!(win->status.shown))
		SDL_ShowWindow(win->sdlwin);
	SDL_RaiseWindow(win->sdlwin);
}

void	ui_win_destroy(t_ui_win * win)
{
	if(win == NULL)
		return ; 
	if (win->sdlrenderer)
		SDL_DestroyRenderer(win->sdlrenderer);
	if (win->sdlwin)
		SDL_DestroyWindow(win->sdlwin);
	win->status.mousefocus = 0;
	win->status.keyboardfocus = 0;
	win->setup.width = 0;
	win->setup.height = 0;
}