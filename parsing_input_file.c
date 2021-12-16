#include "Includes/cub3d.h"

int	check_resolution(char *line, t_data *s)
{
	if (s->f & R)
		ft_exit("Recurring variables!", 1);
	s->rslt = (t_resolution *)ft_calloc(1, sizeof(t_resolution));
	if (!(s->rslt))
		ft_exit(strerror(errno), 1);
	while (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (!(ft_isdigit(*line) || *line == ' ' || *line == '\t')
			|| (ft_isdigit(*line) && s->rslt->height && s->rslt->width))
			ft_exit("Incorrect resolution1!", 1);
		if (ft_isdigit(*line) && !(s->f & R))
		{
			s->rslt->height = ft_atoi_o(line);
			s->f |= R;
		}
		else if (ft_isdigit(*line) && s->f & R)
			s->rslt->width = ft_atoi_o(line);
		while (ft_isdigit(*line))
				line++;
	}
	if (!s->rslt->height || !s->rslt->width
		|| s->rslt->height > 8000 || s->rslt->width > 8000)
		ft_exit("Incorrect resolution4!", 1);
	return (1);
}

int	check_texture(char *line, t_data *s)
{
	if (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line && !(s->f >= NO))
		{
			s->txtr = (t_textures *)ft_calloc(1, sizeof(t_textures));
			if (!(s->txtr))
				ft_exit(strerror(errno), 1);
			printf("Memory allocation\n");
		}
		int mask;
		mask = s->f;
		if (!ft_strncmp(line, "NO",  2) && (line += 2))
			s->txtr->no = check_path(line, s, NO);
		else if (!ft_strncmp(line, "SO", 2) && (line += 2))
			s->txtr->so = check_path(line, s, SO);
		else if (!ft_strncmp(line, "WE", 2) && (line += 2))
			s->txtr->we = check_path(line, s, WE);
		else if (!ft_strncmp(line, "EA", 2) && (line += 2))
			s->txtr->ea = check_path(line, s, EA);
		else if (!ft_strncmp(line, "S", 1) && line++)
			s->txtr->s = check_path(line, s, S);
		if (s->f ^ mask)
			return (1);
	}
		return (0);

}