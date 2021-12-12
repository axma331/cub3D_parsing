#include "Includes/cub3d.h"

int	check_texture(char *line, t_data *s)
{
	printf("Check textures ->\n");
	if (!(s->f >= NO))
	{
		s->txtr = (t_textures *)ft_calloc(1, sizeof(t_textures));
		if (!(s->txtr))
			ft_exit(strerror(errno), 1);
		printf("Memory allocation\n");
	}
	while (*line)
	{
		if (*line == ' ' || *line == '\t')
			line++;
		printf("line:	|%s\n", line);
		printf("->	s-f = %d\n", s->f);
		if (!ft_strncmp(line, "NO", 2) && line++ && line++)
		{
			s->f |= NO;
			printf("NO line:	|%s\n", line);			
		}
		if (!ft_strncmp(line, "SO", 2) && (line += 2))
			s->f ^= SO;
		if (!ft_strncmp(line, "WE", 2) && (line += 2))
			s->f ^= WE;
		if (!ft_strncmp(line, "EA", 2) && (line += 2))
			s->f ^= EA;
		if (!ft_strncmp(line, "S", 1) && line++)
			s->f ^= S;

		printf("<-	s-f = %d\n", s->f);
		sleep(1);
	}
		printf("Check textures <-\n");
		return (0);

}

int	check_resolution(char *line, t_data *s)
{
	if (s->f ^ R)
	{
		printf("Check resolution ->\n");
		s->rslt = (t_resolution *)ft_calloc(1, sizeof(t_resolution));
		if (!(s->rslt))
			ft_exit(strerror(errno), 1);
		while (*line)
		{
			if (*line == ' ' || *line == '\t')
				line++;
			if (*line == 'R' && line++)
			{
				if (s->f & R)
					ft_exit("Incorrect parameters!", 1);
				s->f |= R;
			}
			if (ft_isalpha(*line) || *line == '-' || (ft_isdigit(*line) && s->rslt->height && s->rslt->width))
				ft_exit("Incorrect resolution!", 1);
			if (ft_isdigit(*line) && (s->f & R))
			{
				if (!s->rslt->height)
					s->rslt->height = atoi(line);
				else if (!s->rslt->width)
					s->rslt->width = atoi(line);
				while (ft_isdigit(*line))
						line++;
			}
		}
		printf("rslt:	line:	%s	h=%d	w=%d\n", line, s->rslt->height, s->rslt->width);
		printf("Check resolution <-\n");
		return (1);
	}
	return (0);
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
	// line = (char *)malloc(sizeof(char) + 1);
	while (ret_gnl)
	{
		ret_gnl = get_next_line(fd, &line);
		printf("=>	Start:\n");
		if (check_resolution(line, &s))
			continue ;
		if (check_texture(line, &s))
			continue ;

		// free(line);
		// line = NULL;

		printf("<=	End!\n\n");
		sleep(1);
	}
    return (0);
}
