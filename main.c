#include "Includes/cub3d.h" /* Удалить указание папки!*/

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
	s.map = (char **)ft_calloc(2, sizeof(char *));
	while (ret_gnl)
	{
		printf("\033[32m=> Start:\033[0m\n");
		ret_gnl = get_next_line(fd, &line);
		printf("\tline:\t|%s|\t f = %d\tl = %d\n", line, s.f, (int)ft_strlen(line));

		if (s.f < 128)
		{
			line = ft_strtrim(line, "\t ");
			if (ft_isdigit(*line) && s.f < 128)
				ft_exit("incorrect content map.cub", 1);
			if ( *(line + 1) && *line == 'R' && init_resolution(++line, &s))
				continue ;
			if (init_texture(line, &s))
				continue ;
		}
		else
			init_map(line, &s);

		printf("\033[33m<= End!\n\n\033[0m");
	}
	if (!ret_gnl)
		check_map(&s);
	if (s.rslt)
		printf("\tR\t|%d %d|\n", s.rslt->height, s.rslt->width);
	if (s.txtr){
		printf("\tNO\t|%s|\n\tSO\t|%s|\n\tWE\t|%s|\n\tEA\t|%s|\n\tS\t|%s|\n", s.txtr->no, s.txtr->so, s.txtr->we, s.txtr->ea, s.txtr->s);
		printf("	F	|%d,%d,%d|\n	C	|%d,%d,%d|\n", s.txtr->f[0], s.txtr->f[1], s.txtr->f[2], s.txtr->c[0], s.txtr->c[1], s.txtr->c[2]);}
	int i = -1;
	while (s.map[++i])
		printf("\tmap[%d]\t|%s|\n", i, s.map[i]);
	// printf("\tmap[%d]\t|%s|\n", i, *s.map);

    return (0);
}
