#include "Includes/cub3d.h"

void	init_resolution(t_data *s, int width, int height)
{
	s->rslt.width = width; 
	s->rslt.height = height;
}

static int	check_file(const char *line, const char *ext)
{
	int	len_ext;
	int	len_str;
	int	fd;

	len_ext = ft_strlen(ext);
	len_str = ft_strlen(line);
	if (!(len_str >= len_ext && !ft_strcmp(line + len_str - len_ext, ext)))
		return (false);
	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		close (fd);
		ft_exit(strerror(errno), 1);
	}
	close (fd);
	return (true);
}

char	*check_path(char *line, t_data *s, int mask)
{
	int	i;

	i = 0;
	if (!*line)
		ft_exit("Empty variables!", 1);
	if (s->f & mask)
		ft_exit("Recurring variables!", 1);
	while (*line && (*line == ' ' || *line == '\t'))
		if (++line && !ft_strncmp(line, "./", 2))
			i = 2;
	while (i < (int)ft_strlen(line) - 4)
	{
		if (!(ft_isalnum(*(line + i)) || *(line + i) == '_')
			|| (*(line + i) == '/'
				&& (ft_isalnum(*(line + i) || *(line + i) == '_'))))
			ft_exit("Incorrect path!", 1);
		i++;
	}
	if (!(check_file(line, ".png") || check_file(line, ".xpm")))
		ft_exit("Incorrect file extension!", 1);
	s->f |= mask;
	return (ft_substr(line, 0, ft_strlen(line)));
}

int	init_texture(char *line, t_data *s)
{
	int	mask;

	if (!(s->f >= NO))
		s->txtr = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!(s->txtr))
		ft_exit(strerror(errno), 1);
	mask = s->f;
	if (!ft_strncmp(line, "NO", 2) && line++)
		s->txtr->no = check_path(++line, s, NO);
	else if (!ft_strncmp(line, "SO", 2) && line++)
		s->txtr->so = check_path(++line, s, SO);
	else if (!ft_strncmp(line, "WE", 2) && line++)
		s->txtr->we = check_path(++line, s, WE);
	else if (!ft_strncmp(line, "EA", 2) && line++)
		s->txtr->ea = check_path(++line, s, EA);
	else if (!ft_strncmp(line, "F",  1) && line++)		
		check_color(line, s, F);
	else if (!ft_strncmp(line, "C", 1) && line++)
		check_color(line, s, C);
	if (s->f ^ mask)
		return (true);
	return (false);
}
