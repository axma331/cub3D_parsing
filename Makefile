NAME				:= 	cub3d

CC					:= 	gcc
RM					:= 	rm -rf

OFLAGS				:=	-O2 -g
# OFLAGS				+=	-fsanitize=address
CFLAGS				:= 	$(OFLAGS) -Wall -Wextra -Werror
NORM				:= 	-R CheckForbiddenSourceHeader

LIBFT_DIR			:= 	../libft/
LIBFT				:= 	$(LIBFT_DIR)libft.a

INCLUDES			:= 	includes/
HEADER				:= 	$(INCLUDES)*.h

VPATH				:=	$(SRCS_DIRS)
SRCS_DIRS			:=	/
SRCS				:= 	main.c

OBJS_DIR			:=	.objs/
OBJS				:=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:%.c=%.o)))

all:				libft_make $(NAME)


$(NAME):			$(OBJS_DIR) $(OBJS) $(LIBFT) Makefile
					$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $@

$(OBJS_DIR)%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $@
clean:
					make clean -C $(LIBFT_DIR)
					$(RM) $(OBJS_DIR)
					
fclean:				clean
					make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) .gitpush

re:					fclean all

libft_make:
					@make -C $(LIBFT_DIR)

norme:
					norminette $(NORM) $(SRCS)*.c $(INCLUDES)*.h

gitpush:			fclean
					sh .gitpush || {									\
					echo '#!/bin/sh' > .gitpush;						\
					echo 'echo .gitpush >> .gitignore' >> .gitpush;		\
					echo 'git status' >> .gitpush;						\
					echo 'git add .' >> .gitpush;						\
					echo 'git status' >> .gitpush;						\
					echo 'echo Enter commits name: ' >> .gitpush;		\
					echo 'read commits_name' >> .gitpush;				\
					echo 'git commit -m "$$commits_name"' >> .gitpush;	\
					echo 'git push' >> .gitpush;						\
					sh .gitpush;}

.PHONY:				all clean fclean re libft_make
