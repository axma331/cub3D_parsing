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

# define	NO	0b00000001
# define	SO	0b00000010
# define	WE	0b00000100
# define	EA	0b00001000
# define	F	0b00010000
# define	C	0b00100000

# define	VLD	0b00111111

typedef struct		s_player
{
	char			dir;
	unsigned int	x;
	unsigned int	y;
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

typedef struct		s_data
{
	char			**map;
	char			*map_one_dimension;
	unsigned char 	f;
	t_resolution	rslt;
	t_textures		*txtr;
	t_player		*plyr;
	t_temp			t;
}					t_data;


void	init_resolution(t_data *s, int width, int height);
int		init_texture(char *line, t_data *s);
char	*check_path(char *line, t_data *s, int mask);
int		check_extension(const char* line, const char* ext);
void	check_color(char *line, t_data *s, int mask);
void	init_map(char *line, t_data *s);
void	checking_boundary_symbols(t_data *s, const char c);
void	check_player(t_data *s);

#endif
