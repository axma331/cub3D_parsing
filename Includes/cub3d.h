#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>

# define	R	0b00000001
# define	NO	0b00000010
# define	SO	0b00000100
# define	WE	0b00001000
# define	EA	0b00010000
# define	S	0b00100000
# define	F	0b01000000
# define	C	0b10000000

typedef struct	s_player
{
	unsigned int	x;			//положение игрок на карте по горизонтали
	unsigned int	y;			//положение игрок на карте по вертикали
	unsigned int	distance;	//Растояние до стены
	int				speed;		//Скорость передвижения
	int				fov;		//field of view (поле зрения)
	bool			in_zone;	//Расположение в границах карты
	bool			hit_wall;	//Ударился об стенку
}				t_player;

typedef struct	s_resolution
{
	int				height;
	int				width;
}				t_resolution;

typedef struct	s_textures
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	f[3];
	unsigned int	c[3];
}				t_textures;

typedef struct s_data
{
	t_resolution	*rslt;
	t_textures		*txtr;
	t_player		*plyr;
	char			**map;
	unsigned char 	f;

}				t_data;

int		check_resolution(char *line, t_data *s);
int		check_texture(char *line, t_data *s);
char	*check_path(char *line, t_data *s, int mask);
int		check_extension(const char* line, const char* ext);

#endif
