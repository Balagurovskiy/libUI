
# include "ui_window.h"

void	win_destroy(t_ui_win * win)
{
	if( win && win->sdlwin != NULL )
	{
		SDL_DestroyRenderer(win->sdlrenderer);
		SDL_DestroyWindow(win->sdlwin);
	}
	win->status.mouse_focus = 0;
	win->status.keyboard_focus = 0;
	win->setup.w = 0;
	win->setup.w = 0;
}

int		win_all_closed()
{
	int			i;
	int			closed;
	t_ui_win *	win;

	i = -1;
	closed = 1;
	win = win_storage("#");
	while (++i < win_storage_size("#"))
		if(win[i].status.shown)
			closed = 0;
		else
			if (win[i].status.minimized)
				closed = 0;
	return (closed);
}
