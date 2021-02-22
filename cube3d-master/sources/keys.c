/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:49:36 by home              #+#    #+#             */
/*   Updated: 2021/02/22 11:49:43 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

/*
** For left or right movement:
**		x = dir.x * cos(PI / 2) - dir.y * sin(PI / 2)
**		y = dir.x * sin(PI / 2) + dir.y * cos(PI / 2)
**
** But:
**		cos(PI / 2) = 0
**		sin(PI / 2) = 1
**
** So:
**		x = dir.x * 0 - dir.y * 1
**		y = dir.x * 1 + dir.y * 0
**
** Finally:
**		x = -dir.y
**		y = dir.x
**
*/

int		keypress(int key, t_param *p)
{
	if (key == FORWARD)
		p->pos->forward = 1;
	else if (key == BACKWARD)
		p->pos->backward = 1;
	else if (key == LEFT)
		p->pos->left = 1;
	else if (key == RIGHT)
		p->pos->right = 1;
	else if (key == ROTRIGHT)
		p->pos->rotright = 1;
	else if (key == ROTLEFT)
		p->pos->rotleft = 1;
	else if (key == ESC)
		exit(EXIT_SUCCESS);
	return (0);

}

int		keyrelease(int key, t_param *p)
{
	if (key == FORWARD)
		p->pos->forward = 0;
	else if (key == BACKWARD)
		p->pos->backward = 0;
	else if (key == LEFT)
		p->pos->left = 0;
	else if (key == RIGHT)
		p->pos->right = 0;
	else if (key == ROTRIGHT)
		p->pos->rotright = 0;
	else if (key == ROTLEFT)
		p->pos->rotleft = 0;
	return (0);
}
/*
void	move_updown(t_pos pos, t_mapdata map)
{
	int speed = 5;

	if (pos.forward != 0)
	{
		pos.px += pos.pdx * speed;
		pos.py += pos.pdy * speed;
	}
	if (pos.backward != 0)
	{
		pos.px -= pos.pdx * speed;
		pos.py -= pos.pdy * speed;
	}
}
int keypress(int key, t_param *p)
{
	int speed = 5;

	if (key == FORWARD)
	{
		pos.px += pos.pdx * speed;
		pos.py += pos.pdy * speed;
		drawPlayer(pos.px, pos.py);
		printf("PRESSED W\n");
	}
	if (key == LEFT)
	{
		pos.px -= -pos.pdy * speed;
		pos.py -= pos.pdx * speed;
		drawPlayer(pos.px, pos.py);
		printf("PRESSED A\n");
	}
	if (key == RIGHT)
	{
		pos.px += -pos.pdy * speed;
		pos.py += pos.pdx * speed;
		drawPlayer(pos.px, pos.py);
		printf("PRESSED D\n");
	}
	if (key == ROTLEFT)
	{
		pos.pa -= 0.05 * 2;
		if (pos.pa < 0)
			pos.pa += 2 * PI;
		pos.pdx = cos(pos.pa);
		pos.pdy = sin(pos.pa);
		drawPlayer(pos.px, pos.py);
		printf("PRESSED LEFT ARROW\n");
	}
	if (key == BACKWARD)
	{
		pos.px -= pos.pdx * speed;
		pos.py -= pos.pdy * speed;
		drawPlayer(pos.px, pos.py);
		printf("PRESSED S\n");
	}
	if (key == ROTRIGHT)
	{
		pos.pa += 0.05 * 2;
		if (pos.pa > 2 * PI)
			pos.pa -= 2 * PI;
		pos.pdx = cos(pos.pa);
		pos.pdy = sin(pos.pa);
		drawPlayer(pos.px, pos.py);
		printf("PRESSED RIGHT ARROW\n");
	}
	if (key == ESC)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		printf("BYE\n");
		exit(0);
	}
	return (0);
}

int		keyrelease(int key, t_param *p)
{
	printf("RELEASED KEY\n");
	return (0);
}
*/
