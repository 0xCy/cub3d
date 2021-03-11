/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:54:52 by home              #+#    #+#             */
/*   Updated: 2021/03/11 11:48:29 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

void	drawPlayer(double px, double py)
{
	int i = 0;
	map.wallx = (int)px / (parse.resHeight / map.sizeHeight);
	map.wally = (int)(py - 1) / (parse.resWidth / map.sizeWidth);

	printf("%c\n", map.map[map.wally][map.wallx]);
	//printf("%c\n", map.map[(int)pos.py][(int)pos.px]);
	//printf("%d\n%d\n", parse.resHeight, parse.resWidth);
	mlx_destroy_image(data.mlx_ptr, img.img_ptr);
    img.img_ptr = mlx_new_image(data.mlx_ptr, parse.resHeight, parse.resWidth);
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
    drawMap();
 	myPixel_put(&img, pos.px, pos.py, pcolor);
	while (i < 100)
	{
		myPixel_put(&img, pos.px + pos.pdx * i, pos.py + pos.pdy * i, pcolor);
		i++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img_ptr, 0, 0);
}
