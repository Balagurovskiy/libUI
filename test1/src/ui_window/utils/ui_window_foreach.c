
# include "ui_window.h"

void	win_foreach(void (*f)(t_ui_win * win))
{
	t_ui_win * win;
	int 		i;

	win = win_storage("#");
	if (win == NULL)
		return ;
	i = -1;
	while (++i < win_storage_size("#"))
		if (*f)
			(*f)(&win[i]);
}

void	win_foreach_event(SDL_Event e, void (*f)(t_ui_win * win, SDL_Event e))
{
	t_ui_win * win;
	int 		i;

	win = win_storage("#");
	if (win == NULL)
		return ;
	i = -1;
	while (++i < win_storage_size("#"))
		if (*f)
			(*f)(&win[i], e);
}
