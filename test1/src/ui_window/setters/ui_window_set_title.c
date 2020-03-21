
# include "ui_window.h"

void win_set_title(char * title)
{
	t_ui_win * win;

	win = win_storage("#get");
	if (win == NULL)
		return ;
	if (title == NULL)
		return ;
	win->setup.title = title;
}

void win_set_color(int r, int g, int b)
{
	t_ui_win * win;

	win = win_storage("#get");
	if (win == NULL)
		return ;
	win->setup.r = r;
	win->setup.b = b;
	win->setup.g = g;
}