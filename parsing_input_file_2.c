#include "Includes/cub3d.h"

void	 check_color(char *line, t_data *s, int mask)
{	
	int *fc;
	int i;
	int j;
	int c;
	int d;
	
	i = 0;
	j = 0;
	c = 0;
	d = 0;
	
	if (!*line)
		ft_exit("Empty variables!", 1);
	if (s->f & mask)
		ft_exit("Recurring variables!", 1);
	fc = s->txtr->f;
	if (mask == C)
	fc = s->txtr->c;
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	while (*(line + i))
	{
		if (!(ft_isdigit(*(line + i)) || *(line + i) == ',' || *(line + i) == ' '
			|| *(line + i) == '\t'|| *(line + i) == '+'))
			ft_exit("Incorrect color!", 1);
		d |= ft_isdigit(*(line + i));
		if (*(line + i) == ',')
		{
			if (c > 2 || !d)
				ft_exit("Incorrect variables!", 1);
			fc[c] = ft_atoi_o(line + i - j + c);
			j = 0;
			d = 0;
			c++;
		}
		else if (c == 2 && c++)
			fc[2] = ft_atoi_o(line + i - j + 2);
		i++;
		j++;
	}
	if (fc[0] > 255 || fc[1] > 255 || fc[2] > 255)
			ft_exit("Incorrect color value!", 1);
	s->f |= mask;
}

void	 init_map(char *line, t_data *s)
{
	int i;
	int width;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || !line[0])
		if (!line[++i])
		{
			if(*s->map)
				ft_exit("incorrect map!", 1);
			return ;
		}
	width = ft_strlen(line);
	if (line[i] != '1' || line[width - 1] != '1')
		ft_exit("incorrect map borders!", 1);
	s->t.map_width < width ? s->t.map_width = width : 0;
	printf("%d", s->t.map_width);

	s->map[s->t.lines_cnt++] = line;
	s->t.mass = s->map;
	s->map = (char **)ft_calloc(1 + s->t.lines_cnt, sizeof(char *));
	if (!s->map)
		ft_exit(strerror(errno), 1);
	i = -1;
	while (++i < s->t.lines_cnt)
		s->map[i] = s->t.mass[i];
	free(s->t.mass);
}

void checking_boundary_symbols(t_data *s, const char c) /* Добавить возможность подстановки подстановки символа вместо '0'*/
{
	int y = -1;

	while (s->map[++y] && *s->map[y] && y < s->t.lines_cnt)
	{
		// printf("\tmap[%d]\t|%s|\n", y, s->map[y]);
		int x = 0;
		while (s->map[y][x] == ' ')
			x++;
		while ((!y || y == s->t.lines_cnt - 1) && s->map[y][x])
		{
			// printf("|%c|\n", s->map[y][x]);
			if (!(s->map[y][x] == '1' || s->map[y][x] == ' '))
				ft_exit("incorrect first/last line of the map!", 1);
			x++;
		}
		while (s->map[y] && s->map[y][x])
		{
			// printf("|%d||%d|\t|%c|\n", y, x, s->map[y][x]);
			if (s->map[y][x] == c
				&& (!((y && s->map[y - 1][x] != ' ') && (s->map[y + 1] && s->map[y + 1][x] && (s->map[y + 1][x] != ' ' || !s->map[y + 1][x])) && s->map[y][x - 1] != ' ' && (s->map[y][x + 1] != ' ' || !s->map[y][x + 1]) && s->map[y][x + 1])
				|| (s->map[y][x + 1] == '1' && s->map[y + 1][x] == '1' && (s->map[y + 1][x + 1] == ' ' || !s->map[y + 1][x + 1]))
				|| (s->map[y][x + 1] == '1' && s->map[y - 1][x] == '1' && (s->map[y - 1][x + 1] == ' ' || !s->map[y - 1][x + 1]))
				|| (s->map[y][x - 1] == '1' && s->map[y + 1][x] == '1' && (s->map[y + 1][x - 1] == ' ' || !s->map[y + 1][x - 1]))
				|| (s->map[y][x - 1] == '1' && s->map[y - 1][x] == '1' && s->map[y - 1][x - 1] == ' ')))
			{
				printf("Error->|%c|\n", s->map[y - 1][x + 1]);
				return ;
			}
			x++;
		}
	}
}

void check_player(t_data *s) /* Добавить возможность подстановки подстановки символа вместо '0'*/
{
	int y = -1;

	while (s->map[++y] && *s->map[y] && y < s->t.lines_cnt)
		if (ft_strchr(s->map[y], 'N') || ft_strchr(s->map[y], 'S') || ft_strchr(s->map[y], 'E') || ft_strchr(s->map[y], 'W'))
		{
			/* Установить флаг что мы нашли позицию и более не повторялось*/
			/*Оставить условие, что елли флага нет, то малочим, чтоб повторно не выделять*/
			s->plyr = (t_player *)ft_calloc(1, sizeof(t_player *));
			if (!s->plyr)
				ft_exit(strerror(errno), 1);
			// printf("|%d|\t|%s|\n", y * 100, s->map[y]);
			/*Прописать проверху окружения для позиции используя checking_boundary_symbols*/
			checking_boundary_symbols(s, 'N');
		}


}
