
# include "ui_window.h"

void	win_focus(t_ui_win * win)
{
	if(!(win->status.shown))
		SDL_ShowWindow(win->sdlwin);
	win->h = 0;
	SDL_RaiseWindow(win->sdlwin);
}

void	win_focus_on_key(t_ui_win * win, SDL_Event e)
{
	if (e.key.keysym.sym == win->setup.focus_key)
		win_focus(win);
}
