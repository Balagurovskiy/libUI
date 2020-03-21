
# include "ui_window.h"

void win_set_position(int x, int y)
{
	t_ui_win *	win;

	win = win_storage("#get");
	if (win == NULL)
		return ;
	win->setup.x = x;
	win->setup.y = y;
}
