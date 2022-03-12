#include "Includes/cub3d.h" /* Удалить указание папки!*/

int main(int ac, char **av) {
	t_data	s;
	ft_bzero(&s, sizeof(t_data));

	int fd;
	int ret_gnl = 1;
	char *line;
/*void	check_map_file*/
    if (ac != 2)
		ft_exit("Invalid argument!", 1);
	if (av[1] && !(ft_strlen(av[1]) > 3 && !ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub")))
		ft_exit("Incorrect map name!", 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_exit(strerror(errno), 1);
/*void	check_map_file_content*/
	while (ret_gnl)
	{
		// printf("\033[32m=> Start:\033[0m\n");
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

		// printf("\033[33m<= End!\n\n\033[0m");
	}
	if (!ret_gnl)
	{
		checking_boundary_symbols(&s, '0');
		check_player(&s);

		/*prd*/

		/* Перевод в одномерный массив*/
		s.map_one_dimension = ft_calloc(s.t.map_width * s.t.lines_cnt + 1, sizeof(char));
		int i = -1;
		int x = -1;
		while (s.map[++x])
		{
			int y = -1;
			while (s.map[x][++y])
				s.map_one_dimension[++i] = s.map[x][y]; 
			while (s.t.map_width > y++)
				s.map_one_dimension[++i] = ' ';
		}
		if (!s.map[x + 1])
			s.map_one_dimension[++i] = '\0';
		
		int j = -1;
		while (s.map_one_dimension[++j])
			!(j % s.t.map_width) ? printf("\n") : printf("%c", s.map_one_dimension[j]);
		printf("\n");
		
		// printf("%s\n", s.map_one_dimension);
		free(s.map);


	}
	if (s.rslt)
		printf("\tR\t|%d %d|\n", s.rslt->height, s.rslt->width);
	if (s.txtr){
		printf("\tNO\t|%s|\n\tSO\t|%s|\n\tWE\t|%s|\n\tEA\t|%s|\n\tS\t|%s|\n", s.txtr->no, s.txtr->so, s.txtr->we, s.txtr->ea, s.txtr->s);
		printf("	F	|%d,%d,%d|\n	C	|%d,%d,%d|\n", s.txtr->f[0], s.txtr->f[1], s.txtr->f[2], s.txtr->c[0], s.txtr->c[1], s.txtr->c[2]);
		}
	int i = -1;
	while (s.map[++i])
		printf("\tmap[%d]\t|%s|\n", i, s.map[i]);
	printf("\tmap[%d]\t|%s|\n", i, s.map[i]);


	/*MLX*/
	// int g = 0;
	// g =  create_rgb(256, 25, 255, 9);
	// printf("%X\n", g);


	// s.mlx = *(t_mlx *)ft_calloc(1, sizeof(t_mlx)); /* Нужно ли выделять память динамическую память или оставить со стека*/

	// s.mlx.ptr = mlx_init();
	// s.mlx.win_ptr = mlx_new_window(s.mlx.ptr, 200, 200, "miniMap");
	// s.mlx.img = (t_xpm *)ft_calloc(1, sizeof (t_xpm));
	// s.mlx.img->ptr = mlx_new_image(s.mlx.ptr, 100, 100);
	// s.mlx.img->addr = mlx_get_data_addr(&s.mlx.img->ptr, &s.mlx.img->bpp, &s.mlx.img->ll, &s.mlx.img->endian);
	// my_mlx_pixel_put(s.mlx.img, 10, 10, 55);
	// mlx_put_image_to_window(s.mlx.ptr, s.mlx.win_ptr, s.mlx.img->ptr, 5, 5);

	// mlx_loop(s.mlx.ptr);
	return (0);
}
