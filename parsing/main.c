/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feschall <feschall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:27:29 by feschall          #+#    #+#             */
/*   Updated: 2022/03/27 18:34:27 by feschall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *s)
{
	/*player pisition*/
	printf ("\n\tdir:\t|%c|\n\tx:\t|%d|\n\ty:\t|%d|\n", s->plyr.dir, s->plyr.x, s->plyr.y);
	/*texture*/
	if (s->txtr && s->txtr->no && s->txtr->so && s->txtr->we && s->txtr->ea){
		printf("\tNO\t|%s|\n\tSO\t|%s|\n\tWE\t|%s|\n\tEA\t|%s|\n", s->txtr->no, s->txtr->so, s->txtr->we, s->txtr->ea);
		printf("	F	|%d,%d,%d|\n	C	|%d,%d,%d|\n", s->txtr->f[0], s->txtr->f[1], s->txtr->f[2], s->txtr->c[0], s->txtr->c[1], s->txtr->c[2]);
	}
	/*one dimension map*/
	int j = -1;
	if (s->map_str) {
	while (s->map_str[++j])
		!(j % s->t.map_width) ? (j != 0 ? printf("|\n\t|") : printf("\n\t|")) : printf("%c", s->map_str[j]);
	printf("|\n\n"); }
	/*two dimension map*/
	int i = -1;
	if (s->map) {
	while (s->map[++i])
		printf("\tmap[%d]\t|%s|\n", i, s->map[i]);
	printf("\tmap[%d]\t|%s|\n", i, s->map[i]); }
}

int	main(int ac, char **av)
{
	t_data	s;

	parsing_start(&s, ac, av);
	print_data(&s);
	free_after_parsing(&s);
	return (0);
}
