/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:21:58 by feschall          #+#    #+#             */
/*   Updated: 2022/03/23 15:22:02 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_file_content(int fd, t_data *s)
{
	int		ret_gnl;
	char	*line;

	ret_gnl = 1;
	line = NULL;
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		if (s->f < VLD)
		{
			s->t.ptr = ft_strtrim(line, "\t ");
			free(line);
			line = s->t.ptr;
			if (ft_isdigit(*line) && s->f < VLD)
				ft_exit("Incorrect file content", 1);
			if (init_texture(line, s))
			{
				free(line);
				continue ;
			}
		}
		if (s->f == VLD)
			init_map(line, s);
		free(line);
	}
}

void	parsing_start(t_data *s, int ac, char *av[])
{
	int	fd;

	ft_bzero(s, sizeof(t_data));
	fd = get_correctly_maps_fd(ac, av);
	init_file_content(fd, s);
	checking_boundary_symbols(s, '0');
	check_player(s);
	convert_one_dimension_map(s);
}

void	free_after_parsing(t_data *s)
{
	free(s->map_str);
	free(s->txtr->no);
	free(s->txtr->so);
	free(s->txtr->we);
	free(s->txtr->ea);
	free(s->txtr);
}
