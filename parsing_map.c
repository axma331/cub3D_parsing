#include "cub3d.h"

/*Перевести в интовый*/
void	convert_one_dimension_map(t_data *s)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = -1;
	s->map_str = ft_calloc(s->t.map_width * s->t.lines_cnt + 1, sizeof(char));
	if (!s->map_str)
		ft_exit(strerror(errno), 1);
	while (s->map[++x])
	{
		y = -1;
		while (s->map[x][++y])
			s->map_str[++i] = s->map[x][y];
		while (s->t.map_width > y++)
			s->map_str[++i] = ' ';
	}
	if (!s->map[x + 1])
		s->map_str[++i] = '\0';
	free(s->map);
}

static bool	check_boundary(char **map, char smbl, int x, int y)
{
	if (map[y][x] == smbl
		&& (!((y && map[y - 1][x] != ' ') && (map[y + 1] && map[y + 1][x]
		&& (map[y + 1][x] != ' ' || !map[y + 1][x])) && map[y][x - 1] != ' '
		&& (map[y][x + 1] != ' ' || !map[y][x + 1]) && map[y][x + 1])
		|| (map[y][x + 1] == '1' && map[y + 1][x] == '1'
		&& (map[y + 1][x + 1] == ' ' || !map[y + 1][x + 1]))
		|| (map[y][x + 1] == '1' && map[y - 1][x] == '1'
		&& (map[y - 1][x + 1] == ' ' || !map[y - 1][x + 1]))
		|| (map[y][x - 1] == '1' && map[y + 1][x] == '1'
		&& (map[y + 1][x - 1] == ' ' || !map[y + 1][x - 1]))
		|| (map[y][x - 1] == '1' && map[y - 1][x] == '1'
		&& map[y - 1][x - 1] == ' ')))
		ft_exit("Invalid map!", 1);
	return (true);
}

void	checking_boundary_symbols(t_data *s, const char c)
{
	int	y;
	int	x;

	y = -1;
	while (s->map[++y] && *s->map[y] && y < s->t.lines_cnt)
	{
		x = 0;
		while (s->map[y][x] == ' ')
			x++;
		while ((!y || y == s->t.lines_cnt - 1) && s->map[y][x])
		{
			if (!(s->map[y][x] == '1' || s->map[y][x] == ' '))
				ft_exit("incorrect first/last line of the map!", 1);
			x++;
		}
		while (s->map[y] && s->map[y][x])
			if (check_boundary(s->map, c, x, y))
				x++;
	}
}

static int	check_maps_error(const char *line, t_data *s, int i)
{
	if (!s->map)
	{
		s->map = (char **)ft_calloc(2, sizeof(char *));
		if (!s->map)
			ft_exit(strerror(errno), 1);
	}	
	while (line[i] == ' ' || line[i] == '\t' || !line[0])
	{
		if (!line[++i] && *s->map)
			ft_exit("incorrect map!", 1);
		else if (!line[++i])
			return (-1);
	}
	return (i);
}

void	init_map(char *line, t_data *s)
{
	int	i;
	int	width;

	i = check_maps_error(line, s, 0);
	if (i == -1)
		return ;
	width = ft_strlen(line);
	if (line[i] != '1' || line[width - 1] != '1')
		ft_exit("incorrect map borders!", 1);
	if (s->t.map_width < width)
		s->t.map_width = width;
	s->map[s->t.lines_cnt++] = line;
	s->t.mass = s->map;
	s->map = (char **)ft_calloc(s->t.lines_cnt + 1, sizeof(char *));
	if (!s->map)
		ft_exit(strerror(errno), 1);
	i = -1;
	while (++i < s->t.lines_cnt)
		s->map[i] = s->t.mass[i];
	free(s->t.mass);
}
