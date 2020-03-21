NAME = gui

C_FILES =  	main \
            \
            ui_window/storage/ui_window_storage \
            \
            ui_window/init/ui_window_sdl_init \
            ui_window/init/ui_window_null \
            \
            ui_window/destroy/ui_window_destroy \
            \
            ui_window/events/ui_window_events \
            \
            ui_window/utils/ui_window_focus \
            ui_window/utils/ui_window_foreach \
            ui_window/utils/ui_window_render \
            ui_window/utils/ui_window_search_byname \
            \
            ui_window/setters/ui_window_set_size \
            ui_window/setters/ui_window_set_position \
            ui_window/setters/ui_window_set_title \
            ui_window/setters/ui_window_set_fkey \
            \
            ui_window/handler/ui_win_handler_new \
            ui_window/handler/ui_win_handler_util \
            ui_window/handler/ui_win_handler_update \
            \
            \
            ft_lib/ft_strequ \
   #       	ft_lib/for_each_gnl \
   #       	ft_lib/get_next_line \
   #       	ft_lib/ft_atoi \
   #       	ft_lib/ft_lstnew \
   #       	ft_lib/ft_list_add \
   #       	ft_lib/ft_list_clear \
   #       	ft_lib/ft_lst_delone \
   #       	ft_lib/ft_memdel \
   #       	ft_lib/ft_str_contains \
   #       	ft_lib/ft_strlen \
   #       	ft_lib/ft_strjoin \
   #       	ft_lib/ft_strchr \
   #       	ft_lib/ft_strdel \
   #       	ft_lib/ft_strdup \
   #       	ft_lib/ft_splinter \
   #       	ft_lib/ft_putstr \
   #       	ft_lib/ft_memcpy \
   #       	ft_lib/ft_strsub

H_FILES = ui_window

HEADERS = -I./inc

HDRS = $(addprefix inc/, $(addsuffix .h, $(H_FILES)))
SRC = $(addprefix src/, $(addsuffix .c, $(C_FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(C_FILES)))

COMPILER = gcc
FLAGS = -Wall -Wextra -Werror 

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-F./frameworks/

FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image
 
all:  $(NAME)

$(NAME): $(OBJ)
	@$(COMPILER) -o $(NAME) $(FLAG) $(OBJ) $(FRAMEWORKS) -lncurses


$(OBJ): obj/%.o : src/%.c $(HDRS)
	@$(COMPILER) -o $@ $(HEADERS) $(INCLUDES) -c $< 

clean:
	@rm -f $(OBJ)
	 

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ)
	 
re: fclean all