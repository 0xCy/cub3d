/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:54:52 by home              #+#    #+#             */
/*   Updated: 2021/03/22 15:34:29 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"
//pdx = cos(pos->pa)
//pdy = sin(cos->pa)
void	ft_laser()
{
	ray.wallhitdist = 0;
	ray.maxdistx = (int)(pos.px + cos(pos.pa - DR * ray.angle) * ray.wallhitdist) / (parse.resWidth / map.sizeWidth);
	ray.maxdisty = (int)(pos.py + sin(pos.pa - DR * ray.angle) * ray.wallhitdist) / (parse.resHeight / map.sizeHeight);
	while (map.map[ray.maxdisty][ray.maxdistx] == '0' || map.map[ray.maxdisty][ray.maxdistx] == '2')
	{
			ray.maxdistx = (int)(pos.px + cos(pos.pa - DR * ray.angle) * ray.wallhitdist) / (parse.resWidth / map.sizeWidth);
			ray.maxdisty = (int)(pos.py + sin(pos.pa - DR * ray.angle) * ray.wallhitdist) / (parse.resHeight / map.sizeHeight);
 			myPixel_put(&img, pos.px + cos(pos.pa - DR * ray.angle) * ray.wallhitdist, pos.py + sin(pos.pa - DR * ray.angle) * ray.wallhitdist, COLOR);
			ray.wallhitdist++;
	}
}

void	drawRays()
{
	ray.fov = 60;
	ray.angle = 0;
	while (ray.angle < ray.fov / 2)
	{
		ft_laser();
		ray.angle++;
	}
	while (ray.angle > -ray.fov / 2)
	{
		ft_laser();
		ray.angle--;
	}
}

void	drawPlayer(float px, float py)
{
	int i;

	pos.px = px;
	pos.py = py;
	i = 0;
	mlx_destroy_image(data.mlx_ptr, img.img_ptr);
	img.img_ptr = mlx_new_image(data.mlx_ptr, parse.resHeight, parse.resWidth);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	//ft_laser();
	drawMap();
	drawRays();
	myPixel_put(&img, pos.px, pos.py, pcolor);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img_ptr, 0, 0);
}
