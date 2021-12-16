/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:42:11 by feschall          #+#    #+#             */
/*   Updated: 2021/12/16 16:25:22 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/cub3d.h"

static int	check_resolution_values(t_data *s, int max_h, int max_w)
{
	if (!(0 < s->rslt->height && s->rslt->height <= max_h)
		|| !(0 < s->rslt->width && s->rslt->width <= max_w))
		return (false);
	return (true);
}

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
			ft_exit("Incorrect resolution!", 1);
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
	if (!check_resolution_values(s, 1920, 1080))
		ft_exit("Incorrect resolution!", 1);
	return (true);
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
		// ft_exit(strerror(errno), 1);
	}
	close (fd);
	return (true);
}

char	*check_path(char *line, t_data *s, int mask)
{
	int	i;

	i = 0;
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
	if (!(check_file(line, ".png") || check_file(line, ".xmp")))
		ft_exit("Incorrect file extension!", 1);
	s->f |= mask;
	return (ft_substr(line, 0, ft_strlen(line)));
}

int	check_texture(char *line, t_data *s)
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
	else if (!ft_strncmp(line, "S", 1))
		s->txtr->s = check_path(++line, s, S);
	if (s->f ^ mask)
		return (true);
	return (false);
}
