
# include "ui_window.h"

void	win_render(t_ui_win * win)
{
	if(!(win->status.minimized) && !win->h)
	{
		//Clear screen
		SDL_SetRenderDrawColor(win->sdlrenderer, 
							win->setup.r, win->setup.g, win->setup.b, 0xFF );
		SDL_RenderClear( win->sdlrenderer );
		//Update screen
		SDL_RenderPresent( win->sdlrenderer );
	}
}
