
#ifndef UI_WINDOW_H
# define UI_WINDOW_H

# include "ui_sdl.h"
# include "ui_util.h"

#define TOTAL_WINDOWS 6




typedef struct	s_ui_block
{
	SDL_Rect 		setup;
	SDL_Texture* 	texture;
}				t_ui_block;




typedef struct	s_ui_win_status
{
	int		mousefocus;
	int		keyboardfocus;

	int		fullscreen;
	int		minimized;

	int		shown;
}				t_ui_win_status;

typedef struct	s_ui_win
{
	SDL_Window *	sdlwin;
	SDL_Renderer *	sdlrenderer;

	int				id;
	int				resizable;
	char *			title;
	char			focuskey;

	t_ui_setup		setup;
	t_ui_color		color;
	t_ui_win_status	status;

}				t_ui_win;

void			ui_win_destroy(t_ui_win * win);
int				ui_win_create(t_ui_win * win);
int				ui_win_new_sdlrenderer(t_ui_win * win);
int				ui_win_new_sdlwin(t_ui_win * win);
t_ui_win		ui_win_init();
t_ui_win_status	ui_winstatus_init();
void			ui_win_render(t_ui_win * win);
void			ui_win_focus(t_ui_win * win);


void			ui_win_events(t_ui_win * win, SDL_Event e);

int		ft_strequ(char const *s1, char const *s2);
#endif