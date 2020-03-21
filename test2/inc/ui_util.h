
#ifndef UI_UTIL_H
# define UI_UTIL_H

# include "ui_sdl.h"

typedef struct	s_ui_setup
{
	int		width;
	int		height;

	int		posx;
	int		posy;
}				t_ui_setup;

typedef struct	s_ui_color
{
	int		r;
	int		g;
	int		b;
}				t_ui_color;

t_ui_setup		ui_new_setup(int w, int h, int x, int y);
t_ui_color		ui_new_color(int r, int g, int b);
SDL_Texture *	ui_load_texture(char * path);


#endif