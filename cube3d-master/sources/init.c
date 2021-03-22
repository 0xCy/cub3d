/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:14:42 by home              #+#    #+#             */
/*   Updated: 2021/03/22 13:48:41 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

void	init()
{

	pcolor = 0xFFFFFF;
	pos.px = map.x2 * (parse.resHeight / map.sizeHeight);
	pos.py = map.y2 * (parse.resWidth / map.sizeWidth);
	parse.r = 0;
	parse.g = 0;
	parse.b = 0;
	pos.pdx = cos(pos.pa);
	pos.pdy = sin(pos.pa);
	pos.forward = 0;
	pos.backward = 0;
	pos.right = 0;
	pos.left = 0;
	pos.rotright = 0;
	pos.rotleft = 0;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, parse.resHeight, parse.resWidth, "title");
	img.img_ptr = mlx_new_image(data.mlx_ptr, parse.resHeight, parse.resWidth);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	//mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img_ptr, 0, 0);
}
