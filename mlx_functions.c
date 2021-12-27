#include "Includes/cub3d.h"

int create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	*init_mlx_img(t_data *s, char *xpm, int width, int height)
{
	t_xpm	*img;

	img = (t_xpm *)ft_calloc(1, sizeof (t_xpm));
	if (!img)
		ft_exit(strerror(errno), 1);
	if (!xpm)
		img->ptr = mlx_new_image(s->mlx.ptr, width, height);
	// else
	// 	img->ptr = mlx_xpm_file_to_image(s->mlx.ptr, xpm, &img->w, &img->h);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->ll, &img->endian);
	return (img);
}

void	my_mlx_pixel_put(t_xpm *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	pixel_get(t_xpm *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + \
		(y * data->ll + x * (data->bpp / 8))));
}

void	draw_mini_map(t_data *s, t_xpm *dest, int color)
{
	int	x;
	int	y;
	int	l;

	x = 0;
	y = 0;
	l = 100;
	while (x < l)
	{
		my_mlx_pixel_put(dest, x, y, color);
		if (++x == l && ++y)
		{
			if (y == 40)
				break ;
			x = 0;
		}
	}
}