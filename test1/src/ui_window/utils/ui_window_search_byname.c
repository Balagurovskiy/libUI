
# include "ui_window.h"

char * 		win_target_name(char * target)
{
	static char *	stored_target = NULL;

	if (target)
		stored_target = target;
	return (stored_target);
}

void	win_filter_byname(t_ui_win * win)
{
	if (ft_strequ(win->setup.title, win_target_name(NULL)))
		if (win->sdlwin && win->sdlrenderer)
			win_current("#set", win);
}

t_ui_win *	win_search_byname(char * target)
{
	win_target_name(target);
	win_foreach(&win_filter_byname);
	return(win_current("#get",NULL));
}

// t_ui_win *	search = win_search_byname("window A*");
// if (search)
// 	printf("title:%s___x:%d\n", search->setup.title,search->setup.x);
// search = win_search_byname("windafsasf");
// if (search)
// 	printf("title:%s___x:%d\n", search->setup.title,search->setup.x);
// else
// 	printf("NULL\n");