
# include "ui_window.h"

void update_ui_win_handler(int * status)
{
	//Update all windows
	win_foreach(&win_render);
	//Application closed all windows
	if (win_all_closed())
		(*status) = 0;
}

void events_ui_win_handler(int *status, SDL_Event e)
{
	win_foreach_event(e, &win_events);
	//Pull up window
	if( e.type == SDL_KEYDOWN )
	{
		win_foreach_event(e, &win_focus_on_key);
		if (e.key.keysym.sym == SDLK_ESCAPE)
			(*status) = 0;
	}
}