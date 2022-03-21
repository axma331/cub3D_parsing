# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feschall <feschall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 17:56:43 by feschall          #+#    #+#              #
#    Updated: 2022/03/21 12:06:01 by feschall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -c -g

SRCS			=	ft_atoi_o.c ft_bzero.c ft_calloc.c ft_exit.c		\
					ft_isalnum.c ft_isdigit.c ft_strchr.c ft_strcmp.c	\
					ft_strcpy.c ft_strdup.c ft_strlen.c ft_strlcpy.c	\
					ft_strjoin.c ft_strncmp.c ft_strtrim.c ft_substr.c	\
					get_next_line.c

OBJDIR			:= .objlib
OBJS			:= $(SRCS:%.c=$(OBJDIR)/%.o)
HEAD			:= libft.h

all:			$(NAME)

$(NAME):		$(OBJS) $(HEAD)
				ar rc $@ $(OBJS)
				ranlib $@
				@echo "$(CLRCY)create$(CLREL) $@$(CLRRS)"
	
$(OBJDIR)/%.o:	%.c | $(OBJDIR)
				$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR):
				@mkdir -p $@
	
clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)
				@rm -rf .gitpush

re:				fclean all

gitpush:		fclean
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

.PHONY: 		re all clean fclean

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