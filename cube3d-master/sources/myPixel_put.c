/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myPixel_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:46:53 by gcyril            #+#    #+#             */
/*   Updated: 2021/01/06 14:44:13 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

void	myPixel_put(t_imgdata *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
