#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>

# define	R	1
# define	NO	2
# define	SO	4
# define	WE	8
# define	EA	16
# define	S	32
# define	F	64
# define	C	128

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
	unsigned int	height;
	unsigned int 	width;
}				t_resolution;

typedef struct	s_textures
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	*f;
	unsigned int	*c;
}				t_textures;

typedef struct s_data
{
	t_resolution	*rslt;
	t_textures		*txtr;
	t_player		*plyr;
	char			**map;
	unsigned char 	f;

}				t_data;


#endif
