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

void	 check_map(char *line, t_data *s)
{
	printf("\033[36m=> map\033[0m\n");
	// s->t.mass = (char **)ft_calloc(1, sizeof(char *));
	// if (!(s->t.mass))
	// 	ft_exit(strerror(errno), 1);
	s->t.mass = s->map;
	s->map[s->t.line++] = line; printf("s.l = %d\n", s->t.line);
	s->t.mass = s->map;
	s->map = (char **)ft_calloc(2 + s->t.line , sizeof(char *));
	if (!(s->rslt))
		ft_exit(strerror(errno), 1);
	s->t.cnt = -1;
	while (++s->t.cnt)
		s->map[s->t.cnt] = s->t.mass[s->t.cnt];
	free(s->t.mass);


	printf("\tm\t%s\n",*s->map);
	sleep(1);
	printf("\033[36m<= map\033[0m\n");
}
