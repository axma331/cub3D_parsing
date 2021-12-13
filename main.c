#include "Includes/cub3d.h"

char	*check_path(char *line, t_data *s, int mask)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "./", 2) && *(line + 2))
		return (NULL);
	int i = 0;
	while (*(line + 2 + i) && (ft_isalpha(*(line + 2 + i)) || ft_isdigit(*(line + 2 + i)) || *(line + 2 + i) == '_')) {
			/* printf("%2d|->	|%c|\n", i + 1, *(line + 2 + i)); */ i++; }
	int j = i;
	while (*(line + 2 + j) && (*(line + 2 + j) == ' ' || *(line + 2 + j) == '\t')) {
		/* printf("%2d|->	|%c|\n", j + 1, *(line + 2 + j)); */ j++; }
	if ((ft_strlen(line) - 2  - j))
		ft_exit("Incorrect PATH!", 1);
	s->f |= mask;
	return (ft_substr(line, 0, i + 2));
}

int	check_texture(char *line, t_data *s)
{
	printf("Check textures ->\n");
	printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
	while (*line)
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
		int mask = 0;

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
		
		if (s->f & mask)
		{
			printf("Есть совпадения! %d\n", s->f);
			printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
			if (s->txtr)
				printf("----\nNO\t%s\nSO\t%s\nWE\t%s\nEA\t%s\nS\t%s\n----\n", s->txtr->no, s->txtr->so, s->txtr->we, s->txtr->ea, s->txtr->s);
			sleep(1);
			return (1);
		}




		printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
		if (s->txtr)
			printf("----\nNO\t%s\nSO\t%s\nWE\t%s\nEA\t%s\nS\t%s\n----\n", s->txtr->no, s->txtr->so, s->txtr->we, s->txtr->ea, s->txtr->s);
		sleep(1);
	}
		printf("Check textures <-\n");
		return (0);

}

int	check_resolution(char *line, t_data *s)
{
	if (!(s->f & R))
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
		printf("\n");
	while (ret_gnl)
	{
		printf("=>	Start:\n");
		ret_gnl = get_next_line(fd, &line);
		printf("strlen: %zu\n", ft_strlen(line));
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
