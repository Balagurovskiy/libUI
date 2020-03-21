
# include "ui_window.h"

void win_set_focus_key(char key)
{
	t_ui_win *	win;

	win = win_storage("#get");
	if (win == NULL)
		return ;
	if (key == '\0')
		return ;
	win->setup.focus_key = key;
}

void win_set_hidden()
{
	t_ui_win *	win;

	win = win_storage("#get");
	if (win == NULL)
		return ;
	win->h = 1;
}