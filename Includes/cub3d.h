#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>

static int map_width = 0; //	Перенести в одну из структур!

# define	R	0b00000001
# define	NO	0b00000010
# define	SO	0b00000100
# define	WE	0b00001000
# define	EA	0b00010000
# define	F	0b00100000
# define	C	0b01000000
# define	S	0b10000000

typedef struct		s_player
{
	unsigned int	x;			//положение игрок на карте по горизонтали
	unsigned int	y;			//положение игрок на карте по вертикали
	unsigned int	distance;	//Растояние до стены
	int				speed;		//Скорость передвижения
	int				fov;		//field of view (поле зрения)
	bool			in_zone;	//Расположение в границах карты
	bool			hit_wall;	//Ударился об стенку
}					t_player;

typedef struct		s_resolution
{
	int				height;
	int				width;
}					t_resolution;

typedef struct		s_textures
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f[3];
	int				c[3];
}					t_textures;

typedef struct		s_temp
{
	char			**mass;
	int				lines_cnt;
	int				map_width;
}					t_temp;

typedef struct		s_xpm
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	int				w;
	int				h;
}					t_xpm;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win_ptr;
	t_xpm			*img;
}					t_mlx;

typedef struct		s_data
{
	char			**map;
	unsigned char 	f;
	t_resolution	*rslt;
	t_textures		*txtr;
	t_player		*plyr;
	t_mlx			mlx;
	t_temp			t;
}					t_data;


int		init_resolution(char *line, t_data *s);
int		init_texture(char *line, t_data *s);
char	*check_path(char *line, t_data *s, int mask);
int		check_extension(const char* line, const char* ext);
void	check_color(char *line, t_data *s, int mask);
void	init_map(char *line, t_data *s);
void	checking_boundary_symbols(t_data *s, const char c);
void	check_player(t_data *s);

void	*init_mlx_img(t_data *s, char *xpm, int width, int height);
void	my_mlx_pixel_put(t_xpm *data, int x, int y, int color);
void	draw_mini_map(t_data *s, t_xpm *dest, int color);
int		create_rgb(int t, int r, int g, int b);


#endif
