

#ifndef UI_WINDOW_H
# define UI_WINDOW_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include <stdio.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT  480

#define TOTAL_WINDOWS 6

#define THIS_EVENT(sdlevent) e.window.event == sdlevent

// typedef struct	s_ui_setup
// {
// 	int		width;
// 	int		height;

// 	int		posx;
// 	int		posy;
// }				t_ui_setup;

// typedef struct	s_ui_color
// {
// 	int		r;
// 	int		g;
// 	int		b;
// }				t_ui_color;

// typedef struct	s_ui_win_status
// {
// 	int		mousefocus;
// 	int		keyboardfocus;

// 	int		fullscreen;
// 	int		minimized;

// 	int		shown;
// }				t_ui_win_status;

typedef struct	s_ui_win_status
{
	int		mouse_focus;
	int		keyboard_focus;
	int		full_screen;
	int		minimized;
	int		shown;
}				t_ui_win_status;

typedef struct	s_ui_win_setup
{
	int		w;
	int		h;
	int		x;
	int		y;
	char *	title;
	char	focus_key;
	int		r;
	int		g;
	int		b;
}				t_ui_win_setup;

typedef struct	s_ui_win
{
	SDL_Window *	sdlwin;
	SDL_Renderer *	sdlrenderer;

	int				id;
	int				resizable;
	int				h;

	t_ui_win_setup	setup;
	t_ui_win_status	status;
}				t_ui_win;

typedef struct	s_ui_win_handler
{
	void	(*set_dimension)(int, int);
	void	(*set_position)(int, int);
	void	(*set_color)(int, int, int);
	void	(*set_title)(char *);
	void	(*set_hidden)(void);
	void	(*set_resizable)();
	void	(*set_focus_key)(char);
	void	(*create)(void);
	void	(*update)(int *);
	void	(*pull_event)(int *, SDL_Event );
	void	(*destroy)(void);
}				t_ui_win_handler;

/*
*	 ui_window/storage/ui_window_storage.c
*/
int			win_storage_size(char * action);
t_ui_win *	win_storage(char * action);
t_ui_win *	win_current(char * action, t_ui_win * set_current_w);
/*
*	 ui_window/init/ui_window_null.c
*/
void		win_null(t_ui_win * win);
/*
*	 ui_window/init/ui_window_sdl_init.c
*/
int			win_new_sdlwin();
int			win_new_sdlrenderer();
int			win_init();
/*
*	 ui_window/destroy/ui_window_destroy.c
*/
void		win_destroy(t_ui_win * win);
int			win_all_closed();
/*
*	 ui_window/utils/ui_window_focus.c
*/
void		win_focus(t_ui_win * win);
void		win_focus_on_key(t_ui_win * win, SDL_Event e);
/*
*	 ui_window/utils/ui_window_foreach.c
*/
void	win_foreach(void (*f)(t_ui_win * win));
void	win_foreach_event(SDL_Event e, void (*f)(t_ui_win * w, SDL_Event e));
/*
*	 ui_window/utils/ui_window_render.c
*/
void	win_render(t_ui_win * win);
/*
*	 ui_window/setters/ui_window_set_size.c
*/
void	win_set_dimension(int w, int h);
void	win_set_resizable();
/*
*	 ui_window/setters/ui_window_set_position.c
*/
void	win_set_position(int x, int y);
/*
*	 ui_window/setters/ui_window_set_title.c
*/
void	win_set_title(char * title);
void	win_set_color(int r, int g, int b);
/*
*	 ui_window/setters/ui_window_set_fkey.c
*/
void	win_set_focus_key(char key);
void	win_set_hidden();
/*
*	 ui_window/handler/ui_win_handler_new.c
*/
t_ui_win_handler	new_ui_win_handler();
/*
*	 ui_window/handler/ui_win_handler_util.c
*/
void 				create_ui_win_handler();
void				destroy_ui_win_handler();
/*
*	 ui_window/handler/ui_win_handler_update.c
*/
void				update_ui_win_handler(int * status);
void				events_ui_win_handler(int *status, SDL_Event e);
/*
*	 ui_window/events/ui_win_events.c
*/
void				win_events(t_ui_win * win, SDL_Event e);
///////////////////////////////////////////
/*
*	 ui_window/utils/ui_win_search_byname.c
*/
char *		win_target_name(char * target);
void		win_filter_byname(t_ui_win * win);
t_ui_win *	win_search_byname(char *	target);
///////////////////////////////////////////

int		ft_strequ(char const *s1, char const *s2);


#endif
