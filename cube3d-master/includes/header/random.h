/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:58:07 by home              #+#    #+#             */
/*   Updated: 2021/03/22 16:15:46 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

#include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "struct.h"
# include "random.h"
# include "unistd.h"
# include <fcntl.h>
#include "libft.h"
# define PI 3.14159
# define DR 0.0174533 //one degree in radians to cast rays
# define COLOR 1832883
# define BUFFER_SIZE 32
# define mapHEIGHT 24
# define mapWIDTH 24

// define keys macos
# define ESC 53
# define FORWARD 13 //w
# define BACKWARD 1 //s
# define LEFT 0 //a
# define RIGHT 2 //d
# define ROTRIGHT 124 //right arrow key
# define ROTLEFT 123 //left arrow key

typedef struct		s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}					t_data;

t_data data;

typedef	struct		s_imgata
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_imgdata;
t_imgdata img;

typedef struct		s_mapdata
{
	int		line;
	int		column;
	int		mapHeight;
	int		mapWidth;
	int		height;
	int		width;
	int		heightM;
	int		widthM;
	int		widthF;
	int		heightF;
	int		sizeHeight;
	int		sizeWidth;
	int		tmp;
	int		size;
	char	**map;
	int		x2;
	int 	y2;
}					t_mapdata;
t_mapdata map;

typedef struct		s_parse
{
	int		rx;
	int		ry;
	int		error;
	int		i;
	int		j;
	int		c;
	int		sum;
	int		r;
	int 	b;
	int		g;
	int		resHeight;
	int		resWidth;
	char	*resParse;
	char	*colorParse;
	int		errorNumber;
}					t_parse;

t_parse parse;

typedef struct		s_rgb
{
	int		red;
	int		green;
	int		blue;
	int		res;
}					t_rgb;

typedef struct		s_pos
{
	float	px;		//player position on x axis
	float	py;		//player position on y axis
	float	tmppx;
	float	tmppy;
	float	tmppx2;
	float	tmppy2;
	float	pdx;	//player direction on x axis
	float	pdy;	//player direction on y axis
	float	pa;		//player angle
	int		x;
	int		y;
	char	forward;
	char	backward;
	char	right;
	char	left;
	char	rotright;
	char	rotleft;
	int		collisionx;
	int		collisiony;
}					t_pos;
t_pos pos;

typedef struct		s_ray
{
	int				fov;
	int				angle;
	int				max;
	int				min;
	int				wallhitdist;
	int				maxdistx;
	int				maxdisty;
}					t_ray;

t_ray ray;

typedef struct		s_param
{
	t_data			*data;
	t_pos			*pos;
	t_mapdata		*map;
	t_ray			*ray;
	t_parse			*parse;
	int				i;
	int				j;
}					t_param;

int pcolor;


void	drawPlayer(float px, float py);
void	drawRays();
void	rotation(t_pos *pos);
int		convert(int r, int g, int b);
void	size1();
void	init();
void	ft_laser();
void	drawMap();
void	drawMap2(int a, int b);
int		keypress(int key, t_param *p);
int		keyrelease(int key, t_param *p);
int		find_char(char *str, char c);
void	arg_parse(int fd, char *line);
void	resParser(int fd, char *line);
void	split_rgb(char *line);
int		get_res(char *line, int i, t_data *mlx_ptr);
int		ft_atoi_cub(char *str);
int		ft_test(int fd, char *line);
void	myPixel_put(t_imgdata *img, int x, int y, int color);
int		move(t_param *param);
int		start_it(t_param *p, int argc, char **argv);

#endif
