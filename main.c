#include "Includes/cub3d.h"

// void	check_texture(char *line, t_data *s)
// {
// 	// if (!(s->f &= ))
// 	// {
// 	// 	s->rslt = (t_resolution *)ft_calloc(1, sizeof(t_resolution));
// 	// }

// }

void	check_resolution(char *line, t_data *s)
{
	if (!(s->f &= R))
	{
		s->rslt = (t_resolution *)ft_calloc(1, sizeof(t_resolution));
		while (*line)
		{
			if (*line == ' ' || *line == '\t')
				line++;
			if (*line == 'R' && line++)
			{
				if (s->f &= R)
					ft_exit("Incorrect parameters!", 1);
				s->f ^= R;
			}
			if (ft_isalpha(*line) || *line == '-' || (ft_isdigit(*line) && s->rslt->height && s->rslt->width))
				ft_exit("Incorrect resolution!", 1);
			if (ft_isdigit(*line) && (s->f &= R))
			{
				if (!s->rslt->height)
					s->rslt->height = atoi(line);
				else if (!s->rslt->width)
					s->rslt->width = atoi(line);
				while (ft_isdigit(*line))
						line++;
			}
		}
		// printf("rslt:	line:	%s	h=%d	w=%d\n", line, s->rslt->height, s->rslt->width);
	}
}

int main(int ac, char **av) {
	t_data	s;
	ft_bzero(&s, sizeof(t_data));

	int fd;
	int ret_gnl = 1;
	char *line;
	
    if (ac != 2)
		ft_exit("Invalid argument!", 1);
	if (av[1] && !(strlen(av[1]) > 3 && !strcmp(av[1] + strlen(av[1]) - 4, ".cub")))
		ft_exit("Incorrect map name!", 1);
	fd = open(av[1], O_RDONLY);
	if (errno)
		ft_exit(strerror(errno), 1);

	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		printf("%s\n", line);
		check_resolution(line, &s);
		// check_texture(line, &s);

		printf("main:	line:	%s	h=%d	w=%d\n", line, s.rslt->height, s.rslt->width);
		sleep(3);
	}
    return (0);
}
