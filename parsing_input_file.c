#include "cub3d.h"

int	get_correctly_maps_fd(int ac, char *av[])
{
	int	fd;

	if (ac != 2)
		ft_exit("Invalid argument!", 1);
	if (av[1] && !(ft_strlen(av[1]) > 3
			&& !ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub")))
		ft_exit("Incorrect map name!", 1);
	if (open(av[1], O_DIRECTORY) == 3)
	{
		close(3);
		ft_exit("This is directory!", 1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit(strerror(errno), 1);
	return (fd);
}

void	init_resolution(t_data *s, int width, int height)
{
	s->rslt.width = width;
	s->rslt.height = height;
}

void	init_file_content(int fd, t_data *s)
{
	int		ret_gnl;
	char	*line;

	ret_gnl = 1;
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		if (s->f < VLD)
		{
			line = ft_strtrim(line, "\t ");
			if (ft_isdigit(*line) && s->f < VLD)
				ft_exit("Incorrect file content", 1);
			if (init_texture(line, s))
				continue ;
		}
		if (s->f == VLD)
			init_map(line, s);
	}
}

void	parsing_start(t_data *s, int ac, char *av[])
{
	int	fd;

	ft_bzero(s, sizeof(t_data));
	fd = get_correctly_maps_fd(ac, av);
	init_file_content(fd, s);
	init_resolution(s, 1920, 1080);
	checking_boundary_symbols(s, '0');
	check_player(s);
	convert_one_dimension_map(s);
}
