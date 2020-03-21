
# include "ui_window.h"

static void windowevent_size(t_ui_win * win, SDL_Event e)
{
	if (THIS_EVENT(SDL_WINDOWEVENT_SHOWN))// //Window appeared
		win->status.shown = 1;
	if (THIS_EVENT(SDL_WINDOWEVENT_HIDDEN))	// //Window disappeared
		win->status.shown = 0;
	if (THIS_EVENT(SDL_WINDOWEVENT_SIZE_CHANGED))// //Get new dimensions and repaint
	{
		win->setup.w = e.window.data1;
		win->setup.w = e.window.data2;
		SDL_RenderPresent( win->sdlrenderer );
	}
}

static int windowevent_focus(t_ui_win * win, SDL_Event e)
{
	if (THIS_EVENT(SDL_WINDOWEVENT_ENTER)){//Mouse enter
		win->status.mouse_focus = 1;
		return (1);
	}
	if (THIS_EVENT(SDL_WINDOWEVENT_LEAVE)){//Mouse exit
		win->status.mouse_focus = 0;
		return (1);
	}	
	if (THIS_EVENT(SDL_WINDOWEVENT_FOCUS_GAINED)){//Keyboard focus gained
		win->status.keyboard_focus = 1;
		return (1);
	}
	if (THIS_EVENT(SDL_WINDOWEVENT_FOCUS_LOST)){//Keyboard focus lost
		win->status.keyboard_focus = 0;
		return (1);
	}
	return (0);
}

static void windowevent_minimized(t_ui_win * win, SDL_Event e)
{
	if (THIS_EVENT(SDL_WINDOWEVENT_MINIMIZED))//Window minimized
		win->status.minimized = 1;
	if (THIS_EVENT(SDL_WINDOWEVENT_MAXIMIZED))//Window maxized
		win->status.minimized = 0;
	if (THIS_EVENT(SDL_WINDOWEVENT_RESTORED))//Window restored
		win->status.minimized = 0;
}

void win_events(t_ui_win * win, SDL_Event e)
{
	int update;
	//If an event was detected for this window
	if( e.type == SDL_WINDOWEVENT && e.window.windowID == win->id )
	{
		//Caption update flag
		windowevent_size(win, e);
		windowevent_minimized(win, e);
		update = windowevent_focus(win, e);

		if (THIS_EVENT(SDL_WINDOWEVENT_EXPOSED))//Repaint on expose
			SDL_RenderPresent(win->sdlrenderer);
		if (THIS_EVENT(SDL_WINDOWEVENT_CLOSE) || win->h)//Hide on close
		{
			SDL_HideWindow(win->sdlwin);// SDL_DestroyWindow(win->sdlwin);
			win->h = 1;
		}
		if( update )
		{
			printf( "id:%d  mouseFocus:%d  keyFocus:%d\n",win->id, win->status.mouse_focus, win->status.keyboard_focus);
			// SDL_SetWindowTitle( win->sdlwin, "new title" );
		}
	}
}