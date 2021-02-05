/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:48:31 by gcyril            #+#    #+#             */
/*   Updated: 2021/01/06 10:29:22 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct		s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset;
}					t_data;

void	mypixelput(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		main(void)
{
	t_data img;
	int y;
	int x;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1440, 720, "new window");
	img.img = mlx_new_image(img.mlx, 1440, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mypixelput(&img, 5, 5, 0xFFFFFF);
	mypixelput(&img, 6, 5, 0xFFFFFF);
	mypixelput(&img, 7, 5, 0xFFFFFF);
	mypixelput(&img, 8, 5, 0xFFFFFF);
	mypixelput(&img, 9, 5, 0xFFFFFF);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	//img.offset = (y * img.line_length + x * (img.bits_per_pixel / 8));
	mlx_loop(img.mlx);
}
