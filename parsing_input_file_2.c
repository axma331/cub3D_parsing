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
	int i;
	
	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || !line[0])
		if (!line[++i])
		{
			if(*s->map)
				ft_exit("incorrect map!", 1);
			return ;
		}
	if (line[i] != '1' || line[ft_strlen(line) - 1] != '1')
		ft_exit("incorrect map borders!", 1);
		
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
