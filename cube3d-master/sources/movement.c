/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 12:21:38 by gcyril            #+#    #+#             */
/*   Updated: 2021/03/22 15:35:56 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

//ray.maxdistx = (int)(pos.px + cos(pos.pa) / (parse.resWidth / map.sizeWidth);
//ray.maxdisty = (int)(pos.py + sin(pos.pa) / (parse.resHeight / map.sizeHeight);
int speed = 2;

void	move_updown(t_pos *pos, t_mapdata *map)

{
	if (pos->forward)
	{
		pos->px += pos->pdx * speed;
		pos->py += pos->pdy * speed;
		pos->x = (int)pos->px  / (parse.resWidth / map->sizeWidth);
		pos->y = (int)pos->py / (parse.resHeight / map->sizeHeight);
		drawPlayer(pos->px, pos->py);
	}
	if (pos->backward)
	{
		pos->px -= pos->pdx * speed;
		pos->py -= pos->pdy * speed;
		pos->x = (int)pos->px  / (parse.resWidth / map->sizeWidth);
		pos->y = (int)pos->py / (parse.resHeight / map->sizeHeight);
		drawPlayer(pos->px, pos->py);
	}
}

void	move_leftright(t_pos *pos, t_mapdata *map)
{
	if (pos->left == 1)
	{
		pos->px -= -pos->pdy * speed;
		pos->py -= pos->pdx * speed;
		drawPlayer(pos->px, pos->py);
	}
	if (pos->right == 1)
	{
		pos->px += -pos->pdy * speed;
		pos->py += pos->pdx * speed;
		drawPlayer(pos->px, pos->py);
	}
}

int		move(t_param *param)
{
	move_updown(param->pos, param->map);
	move_leftright(param->pos, param->map);
	rotation(param->pos);
	return (0);
}
