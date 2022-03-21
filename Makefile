NAME				= 	cub3d
CC					= 	gcc
RM					= 	rm -rf

CFLAGS				=	-Wall -Wextra -Werror
CFLAGS				+=	-O2 -g
# CFLAGS				+=	-fsanitize=address

NORM				= 	-R CheckForbiddenSourceHeader

LIBFT_DIR			= 	./libft/
LIBFT				= 	$(LIBFT_DIR)libft.a
LIBFT_HED			= 	$(LIBFT_DIR)libft.h

INCLUDES			= 	./includes/
HEADER				= 	$(INCLUDES)cub3d.h

SRCS_DIR			=	./parsing/
SRCS				=	main.c	parsing_input_file.c parsing_textures.c parsing_colors_and_player.c parsing_map.c

OBJS_DIR			=	./.objs/
OBJS				=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:%.c=%.o)))

all:				Makefile libft_make $(NAME) 

$(NAME):			$(LIBFT) $(OBJS_DIR) $(OBJS) 
					$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
					@echo "$(CLRCY)create$(CLREL) $@$(CLRRS)"

$(OBJS_DIR)%.o:		$(SRCS_DIR)%.c $(HEADER)
					$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $@

clean:
					@-make clean -C $(LIBFT_DIR)
					$(RM) $(OBJS_DIR)

fclean:				clean
					@make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					@$(RM) .gitpush

re:					fclean all

libft_make:
					@make -C $(LIBFT_DIR)

norme:
					norminette $(NORM) $(SRCS)*.c $(INCLUDES)*.h

gitpush:			fclean
					sh .gitpush || {											\
					echo '#!/bin/sh'									> .gitpush;\
					echo 'grep -Fx .gitpush .gitignore > /dev/null \'	>> .gitpush;\
					echo '|| echo .gitpush >> .gitignore;'				>> .gitpush;\
					echo 'git status'									>> .gitpush;\
					echo 'git add .'									>> .gitpush;\
					echo 'git status'									>> .gitpush;\
					echo 'echo Enter commits name: '					>> .gitpush;\
					echo 'read commits_name'							>> .gitpush;\
					echo 'git commit -m "$$commits_name"'				>> .gitpush;\
					echo 'git push'										>> .gitpush;\
					sh .gitpush;}
					rm .gitpush

.PHONY:				all clean fclean re libft_make


#-c говорит не запускать линкер, потому что нет main
#-g порождает отладочную информацию в родном формате операционной системы
#включает использование дополнительной отладочной информации, 
#которую может использовать только GDB; 
#эта дополнительная отладочная информация делает работу отладки в GDB лучше, но может, 
#вероятно испортить работу других отладчиков, или помешать им прочитать программу.

CLRRS = \033[0m#сброс цвета
BOLDf = \033[1m#жирный шрифт
UNDRL = \033[4m#подчеркивание
FONGR = \033[47m#серый цвет фона
CLRGR = \033[37m#серый цвет шрифта
FONCY = \033[46m#цвет морской волны фона		
CLRCY = \033[36m#цвет морской волны шрифта
FONPR = \033[45m#фиолетовый цвет фона
CLRPR = \033[35m#фиолетовый цвет шрифта
FONBL = \033[44m#синий цвет фона
CLRBL = \033[34m#синий цвет шрифта
FONEL = \033[43m#желтый цвет фона
CLREL = \033[33m#желтый цвет шрифта
FONGR = \033[42m#зелёный цвет фона
CLRGR = \033[32m#зелёный цвет шрифта
FONRE = \033[41m#красный цвет фона
CLRRE = \033[31m#красный цвет шрифта
FONBC = \033[40m#чёрный цвет фона
CLRBC = \033[30m#чёрный цвет шрифта
#COLOR+FON = \033[6;35m - можно совмещать \033[6 - цвет шрифта ;35m - цвет фона