//ft_putstr("EXCEPTION > input > invalid argument\n");
// ft_str_contains(argv[1], ".doom\0")
//----------------------------------
//////////////////

# include "ui_window.h"


//#####################################################
int ui_win_count(char * action)
{
	static int		size = 0;

	if (ft_strequ(action, "#add")){
		size++;
		if (size >= TOTAL_WINDOWS)
			size = TOTAL_WINDOWS - 1;
	}
	if (ft_strequ(action, "#in_bounds")){
		return (size + 1 < TOTAL_WINDOWS);
	}
	if (ft_strequ(action, "#get"))
		return (size);
	return (-1);
}

t_ui_win *	ui_win_current(char * action, t_ui_win * set_current_w)
{
	static t_ui_win *	current_w = NULL;

	if (ft_strequ(action, "#set"))
		current_w = set_current_w;
	if (ft_strequ(action, "#get"))
		return (current_w);
	return (NULL);
}

t_ui_win * ui_win_storage(char * action)
{
	int					i;
	static t_ui_win		wins[TOTAL_WINDOWS];

	if (ft_strequ(action, "#add"))
	{
		if (ui_win_count("#in_bounds"))
		{
			wins[ui_win_count("#get")] = ui_win_init();
			ui_win_current("#set", &wins[ui_win_count("#get")]);
			ui_win_count("#add");
		}
	}
	if (ft_strequ(action, "#get"))
		return (wins);
	return (NULL);
}



void	win_destroy(t_ui_win * win)
{
	if( win && win->sdlwin != NULL )
	{
		SDL_DestroyRenderer(win->sdlrenderer);
		SDL_DestroyWindow(win->sdlwin);
	}
	win->status.mousefocus = 0;
	win->status.keyboardfocus = 0;
	win->setup.width = 0;
	win->setup.height = 0;
}

//#####################################################


//#####################################################
int sdl_init()
{
	int success;

	success = 1;
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError()); //ERROR
		success = 0;
	}
	else
	{
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
			printf("Warning: Linear texture filtering not enabled!"); //ERROR
	}

	return success;
}
//#####################################################

//  void	win_focus(t_ui_win * win)
// {
// 	if(!(win->status.shown))
// 		SDL_ShowWindow(win->sdlwin);
// 	SDL_RaiseWindow(win->sdlwin);
// }

// void	win_focus_on_key(t_ui_win * win, SDL_Event e)
// {
// 	if (e.key.keysym.sym == win->focuskey)
// 		win_focus(win);
// }







int main(void)
{
 

	
	if (sdl_init())
	{

		int			status;
		SDL_Event	e;

		status = 1;
	//----------------------------------
		t_ui_win win = ui_win_init();
		win.setup = ui_new_setup(500, 400, 50, 50);
		win.color = ui_new_color(111, 11, 111);
		win.title = " window testing ";
		win.focuskey = '1';
		ui_win_create(&win);
	//----------------------------------

		while(status)
		{
			while(SDL_PollEvent(&e) != 0)
			{
				if( e.type == SDL_KEYDOWN ){
					if (e.key.keysym.sym == SDLK_ESCAPE)
						status = 0; //SDL_DestroyWindow(win->sdlwin);
					if (e.key.keysym.sym == SDLK_a){
						ui_win_destroy(&win);
						win.setup = ui_new_setup(150, 150, 300, 500);
						win.color = ui_new_color(11, 111, 111);
						win.title = " window testing 2";
						ui_win_create(&win);
					}
				}
				ui_win_events(&win, e);
			}
			// ui_win_focus(&win);
			ui_win_render(&win);

		}
		ui_win_destroy(&win);
	} 
	else 
		printf( "sdl_init_status error\n");
	
	SDL_Quit();
	system("leaks gui");
	return 0;
}
//////////////  FIND BY TITLE ??????

//////////////  create MAIN window all close; all minimize\; add more win types : main;bars;modals;draw

////////////// t_ui_window gettersss????

////////////// parser for window patterns???????

////////////// paterns with viewpoints end textures that will copy to win renderer 