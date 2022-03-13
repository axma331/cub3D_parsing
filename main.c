#include "cub3d.h"

void	print_data(t_data *s)
{
	/*player pisition*/
	// if (s->plyr.dir)
	printf ("\n\tdir:\t|%c|\n\tx:\t|%d|\n\ty:\t|%d|\n", s->plyr.dir, s->plyr.x, s->plyr.y);
	/*resolutions*/
	printf("\tR\t|%d %d|\n", s->rslt.height, s->rslt.width);
	/*texture*/
	if (s->txtr){
		printf("\tNO\t|%s|\n\tSO\t|%s|\n\tWE\t|%s|\n\tEA\t|%s|\n", s->txtr->no, s->txtr->so, s->txtr->we, s->txtr->ea);
		printf("	F	|%d,%d,%d|\n	C	|%d,%d,%d|\n", s->txtr->f[0], s->txtr->f[1], s->txtr->f[2], s->txtr->c[0], s->txtr->c[1], s->txtr->c[2]);
	}
	/*one dimension map*/
	int j = -1;
	while (s->map_str[++j])
		!(j % s->t.map_width) ? (j != 0 ? printf("|\n\t|") : printf("\n\t|")) : printf("%c", s->map_str[j]);
	printf("|\n\n");
	/*two dimension map*/
	int i = -1;
	while (s->map[++i])
		printf("\tmap[%d]\t|%s|\n", i, s->map[i]);
	printf("\tmap[%d]\t|%s|\n", i, s->map[i]);
}

int main(int ac, char **av) {
	t_data	s;

	parsing_start(&s, ac, av);
	print_data(&s);
	return (0);
}