#include "cub3d.h"

static int	*use_color_for_init(t_data *s, int mask)
{
	int	i;

	i = -1;
	if (mask == C)
	{
		while (++i < 3)
			s->txtr->c[i] = -1;
		return (s->txtr->c);
	}
	while (++i < 3)
		s->txtr->f[i] = -1;
	return (s->txtr->f);
}

void	init_color(char *line, int *fc, int i, int j)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (*(line + i))
	{
		if (!(ft_isdigit(*(line + i)) || ft_strchr(" \t+,", *(line + i))))
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
			fc[2] = ft_atoi_o(line + i - j + 1);
		++i;
		++j;
	}
}

void	check_color(char *line, t_data *s, int mask)
{	
	int	*fc;
	int	i;

	if (!*line)
		ft_exit("Empty variables!", 1);
	if (s->f & mask)
		ft_exit("Recurring variables!", 1);
	fc = use_color_for_init(s, mask);
	while (*line && (*line == ' ' || *line == '\t'))
		line++;
	init_color(line, fc, 0, 0);
	i = -1;
	while (++i < 3)
		if (fc[i] < 0 || fc[i] > 255)
			ft_exit("Incorrect color value!", 1);
	s->f |= mask;
}

static int	find_position(const char *symbols, char *str)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if (ft_strchr(symbols, str[i]))
			return (i);
	}
	return (-1);
}

void check_player(t_data *s)
{
	int y;
	int pos;
	
	y = -1;
	pos = 0;
	while (s->map[++y] && *s->map[y] && y < s->t.lines_cnt)
	{
		pos = find_position("NSWE", s->map[y]);
		if (pos != -1)
		{
			if (s->plyr.dir)
				ft_exit("More than one position an player!", 1);
			s->plyr.x = pos;
			s->plyr.y = y;
			s->plyr.dir = s->map[y][pos];
			checking_boundary_symbols(s, s->plyr.dir);
			s->map[y][pos] = '0';
		}
	}
	if (!s->plyr.dir)
		ft_exit("Player is missing!", 1);
}