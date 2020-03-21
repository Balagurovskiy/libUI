
# include "ui_window.h"

void win_null(t_ui_win * win)
{
	win = win_storage("#get");
	win->sdlwin = NULL;
	win->sdlrenderer = NULL;
	win->status.mouse_focus = 0;
	win->status.keyboard_focus = 0;
	win->status.full_screen = 0;
	win->status.minimized = 0;
	win->status.shown = 0;
	win->id = -1;
	win->resizable = 0;
	win->setup.w = 0;
	win->setup.h = 0;
	win->setup.x = 0;
	win->setup.y = 0;
	win->setup.title = NULL;
	win->setup.focus_key = '#';
	win->setup.r = 0;
	win->setup.g = 0;
	win->setup.b = 0;

	win->h = 0;
}