/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:21:38 by gcyril            #+#    #+#             */
/*   Updated: 2021/03/11 12:04:11 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

int speed = 2;

int		can_move(int position)
{
	if (position == '1')
		return (0);
	else
		return (1);
}

void	rotation(t_pos *pos)
{
	if (pos->rotleft == 1)
	{
		pos->pa -= 0.04;
		if (pos->pa < 0)
			pos->pa += 2 * PI;
		pos->pdx = cos(pos->pa);
		pos->pdy = sin(pos->pa);
		drawPlayer(pos->px, pos->py);
	}
	if (pos->rotright == 1)
	{
		pos->pa += 0.04;
		if (pos->pa > 2 * PI)
			pos->pa -= 2 * PI;
		pos->pdx = cos(pos->pa);
		pos->pdy = sin(pos->pa);
		drawPlayer(pos->px, pos->py);
	}
}

void	move_updown(t_pos *pos, t_mapdata *map)
{
	if (pos->forward)
	{
		if (map->map[(int)(map->wally + (pos->pdy * speed))][(int)map->wallx] == '0')
		{
			pos->px += pos->pdx * speed;
			drawPlayer(pos->px, pos->py);
		}
		if (map->map[(int)(map->wally)][(int)(map->wallx + (pos->pdx * speed))] == '0')
		{
			pos->py += pos->pdy * speed;
			drawPlayer(pos->px, pos->py);
		}
	}
	if (pos->backward)
	{
		if (map->map[(int)(map->wally - (pos->pdy * speed))][(int)map->wallx] == '0')
		{
			pos->px -= pos->pdx * speed;
			drawPlayer(pos->px, pos->py);
		}
		if (map->map[(int)(map->wally)][(int)(map->wallx + (pos->pdx * speed))] == '0')
		{
			pos->py -= pos->pdy * speed;
			drawPlayer(pos->px, pos->py);
		}
	}
}

void	move_leftright(t_pos *pos, t_mapdata *map)
{
	if (pos->left == 1)
	{
		if (map->map[(int)(map->wally - (-pos->pdy * speed))][(int)map->wallx] == '0')
		{
			pos->px -= -pos->pdy * speed;
			drawPlayer(pos->px, pos->py);
		}
		if (map->map[(int)(map->wally)][(int)(map->wallx - (-pos->pdy * speed))] == '0')
		{
			pos->py -= pos->pdx * speed;
			drawPlayer(pos->px, pos->py);
		}
	}
	if (pos->right == 1)
	{
		if (map->map[(int)(map->wallx)][(int)(map->wally - pos->pdx * speed)] == '0')
		{
			pos->px += -pos->pdy * speed;
			drawPlayer(pos->px, pos->py);
		}
		if (map->map[(int)(map->wally)][(int)(map->wallx + pos->pdy * speed)] == '0')
		{
			pos->py += pos->pdx * speed;
			drawPlayer(pos->px, pos->py);
		}
	}
}

int		move(t_param *param)
{
	move_updown(param->pos, param->map);
	move_leftright(param->pos, param->map);
	rotation(param->pos);
	return (0);
}
