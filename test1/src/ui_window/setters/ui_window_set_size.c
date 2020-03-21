
# include "ui_window.h"

void win_set_dimension(int w, int h)
{
	t_ui_win *	win;

	win = win_storage("#get");
	if (win == NULL)
		return ;

	win->setup.w = w;
	win->setup.h = h;
}

void win_set_resizable()
{
	t_ui_win *	win;

	win = win_storage("#get");
	if (win == NULL)
		return ;
	win->resizable = SDL_WINDOW_RESIZABLE;
}
