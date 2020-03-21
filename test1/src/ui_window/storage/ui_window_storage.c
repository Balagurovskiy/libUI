
# include "ui_window.h"

t_ui_win * win_storage(char * action)
{
	int					i;
	static t_ui_win		wins[TOTAL_WINDOWS];

	i = -1;
	if (ft_strequ(action, "#init"))
		while (++i < TOTAL_WINDOWS)
			win_null(&wins[i]);
	if (ft_strequ(action, "#get"))
		return (&wins[win_storage_size("#")]);
	if (ft_strequ(action, "#add"))
	{
		if (win_storage_size("#in_bounds"))
			win_init();
		win_storage_size("#add");
	}
	if (ft_strequ(action, "#close"))
	{
		while (++i < win_storage_size("#"))
			win_destroy(&wins[i]);
		SDL_Quit();
	}
	return (wins);
}

int win_storage_size(char * action)
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
	return (size);
}

t_ui_win *	win_current(char * action, t_ui_win * set_current_w)
{
	static t_ui_win *	current_w = NULL;

	if (ft_strequ(action, "#set"))
		current_w = set_current_w;
	return (current_w);
}
