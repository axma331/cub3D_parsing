#include "Includes/cub3d.h" /* Удалить указание папки!*/

int	 check_map(char *line, t_data *s, int mask)
{
	(void)line;
	(void)s;
	(void)mask;
	return (0);
}

unsigned int	 check_color_fc(char *line, t_data *s, int mask)
{
	unsigned int *f_or_c = s->txtr->f;
	if (mask == C)
	f_or_c = s->txtr->c;
	
	while (*line == ' ' || *line == '\t')
		line++;

	int i = 0;
	int j = 0;
	int c = 0;
	int d = 0;

	
	while (*(line + i))
	{
		if (s->f & mask || !(ft_isdigit(*(line + i)) || *(line + i) == ',' || *(line + i) == ' ' || *(line + i) == '\t'|| *(line + i) == '+'))
			ft_exit("Incorrect color!", 1);
		d |= ft_isdigit(*(line + i));
		if (*(line + i) == ',')
		{
			if (c > 2 || !d)
				ft_exit("Incorrect ccccc!", 1);
			f_or_c[c] = (unsigned int)ft_atoi_o(line + i - j + c);
			j = 0;
			d = 0;
			c++;

		}
		else if (c == 2 && c++)
			f_or_c[2] = (unsigned int)ft_atoi_o(line + i - j + 2);
		i++;
		j++;
	}
	if (f_or_c[0] > 255 || f_or_c[1] > 255 || f_or_c[2] > 255)
			ft_exit("Incorrect wsfsdfgsdr!", 1);
	s->f |= mask;
	return (0);
}

int	check_color(char *line, t_data *s)
{
	printf("\033[32mCheck color ->\033[0m\n");
	// unsigned int g[3];

	if (*line)
	{
		line = ft_strtrim(line, " \t");
		if (*line && !(s->f >= NO))
		{
			s->txtr = (t_textures *)ft_calloc(1, sizeof(t_textures));
			if (!(s->txtr))
				ft_exit(strerror(errno), 1);
			printf("Memory allocation\n");
		}
		int mask;
		mask = s->f;

		if (!ft_strncmp(line, "F",  1) && line++)
		{
			check_color_fc(line, s, F);
			// printf("----\ng	%d,%d,%d\n----\n", g[0], g[1], g[2]);
			
		}
		else if (!ft_strncmp(line, "C", 1) && line++)
		{
			check_color_fc(line, s, C);

		}

		
		if (s->txtr)
			printf("----\nF	%d,%d,%d\nC	%d,%d,%d\n----\n", s->txtr->f[0], s->txtr->f[1], s->txtr->f[2], s->txtr->c[0], s->txtr->c[1], s->txtr->c[2]);
		printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
		sleep(1);

		if (s->f ^ mask)
			return (1);
	}	
	printf("\033[33mCheck color <-\033[0m\n");
	return (0);
} 
//  printf("i=%d j=%d c=%d\nF %3d,%3d,%3d\nC %3d,%3d,%3d\n\n", i, j, c, s->txtr->f[0], s->txtr->f[1], s->txtr->f[2], s->txtr->c[0], s->txtr->c[1], s->txtr->c[2]);


// char	*check_path(char *line, t_data *s, int mask)
// {
// printf("|%s|\n",line);
// 	line = ft_strtrim(line, " ");
// printf("|%s|\n",line);
// 	if (ft_strncmp(line, "./", 2) && *(line + 2))
// 		return (NULL);
// 	int i = 0;
// 	while (*(line + 2 + i) && (ft_isalnum(*(line + 2 + i)) || *(line + 2 + i) == '/' || *(line + 2 + i) == '_' || *(line + 2 + i) == '.')) {
// // printf("%2d|->	|%c|\n", i + 1, *(line + 2 + i));
// 		if (*(line + 2 + i) == '.')
// 		{
// 			if (!((!ft_strncmp(line + 2 + i, ".png", 4) || !ft_strncmp(line + 2 + i, ".xmp", 4)) && ft_strlen(line + 2 + i) == 4))
// 				ft_exit("Incorrect file extension!", 1);
// 			if (!ft_isalnum(*(line + 1 + i)))
// 				ft_exit("Incorrect path!", 1);
// 		}
// 		i++;
// 	}
// 	if (ft_strchr(line + 2, '.') == NULL || ft_strlen(line + 2 + i))
// 		ft_exit("Incorrect path!", 1);
// 	s->f |= mask;
// 	// if (open(ft_substr(line, 0, i + 2), O_RDONLY) == -1)
// 	// 	ft_exit(strerror(errno), 1);
// 	return (ft_substr(line, 0, i + 2));
// }

// int	check_texture(char *line, t_data *s)
// {
// 	printf("Check textures ->\n");
// 	printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
// 	if (*line)
// 	{
// 		while (*line == ' ' || *line == '\t')
// 			line++;
// 		if (*line && !(s->f >= NO))
// 		{
// 			s->txtr = (t_textures *)ft_calloc(1, sizeof(t_textures));
// 			if (!(s->txtr))
// 				ft_exit(strerror(errno), 1);
// 			printf("Memory allocation\n");
// 		}
// 		int mask;
// 		mask = s->f;
// 
// 		if (!ft_strncmp(line, "NO",  2) && (line += 2))
// 			s->txtr->no = check_path(line, s, NO);
// 		else if (!ft_strncmp(line, "SO", 2) && (line += 2))
// 			s->txtr->so = check_path(line, s, SO);
// 		else if (!ft_strncmp(line, "WE", 2) && (line += 2))
// 			s->txtr->we = check_path(line, s, WE);
// 		else if (!ft_strncmp(line, "EA", 2) && (line += 2))
// 			s->txtr->ea = check_path(line, s, EA);
// 		else if (!ft_strncmp(line, "S", 1) && line++)
// 			s->txtr->s = check_path(line, s, S);
// 
// 		if (s->txtr)
// 			printf("----\nNO\t%s\nSO\t%s\nWE\t%s\nEA\t%s\nS\t%s\n----\n", s->txtr->no, s->txtr->so, s->txtr->we, s->txtr->ea, s->txtr->s);
// 		printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
// 		sleep(1);
// 
// 		if (s->f ^ mask)
// 			return (1);
// 	}
// 		// if (s->txtr)
// 		// 	printf("----\nNO\t%s\nSO\t%s\nWE\t%s\nEA\t%s\nS\t%s\n----\n", s->txtr->no, s->txtr->so, s->txtr->we, s->txtr->ea, s->txtr->s);
// 		// printf("slen: %d	line:	|%s|	f = %d\n", (int)ft_strlen(line), line, s->f);
// 		printf("Check textures <-\n");
// 		return (0);
// }


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
		printf("=>	Start:\n");
		ret_gnl = get_next_line(fd, &line);
		if (s.f <= 254)
		line = ft_strtrim(line, "\t ");

		if ( *(line + 1) && *line == 'R' && check_resolution(++line, &s))
			continue ;
		if (*line && check_texture(line, &s))
			continue ;
		if (check_color(line, &s))
			continue ;

		// free(line);
		// line = NULL;

		printf("<=	End!\n\n\n");
		sleep(1);
	}
    return (0);
}
