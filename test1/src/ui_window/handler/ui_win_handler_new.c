
# include "ui_window.h"

t_ui_win_handler new_ui_win_handler()
{
	t_ui_win_handler	w;

	win_storage("#init");
	w.set_dimension = &win_set_dimension;
	w.set_position = &win_set_position;
	w.set_title = &win_set_title;
	w.set_resizable = &win_set_resizable;
	w.set_focus_key = &win_set_focus_key;
	w.create = &create_ui_win_handler;
	w.update = &update_ui_win_handler;
	w.pull_event = &events_ui_win_handler;
	w.destroy = &destroy_ui_win_handler;
	w.set_color = &win_set_color;
	w.set_hidden = &win_set_hidden;
	return (w);
}