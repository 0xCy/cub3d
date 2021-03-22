/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:39:15 by gcyril            #+#    #+#             */
/*   Updated: 2021/03/22 13:37:08 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

void	rotation(t_pos *pos)
{
	pos->pdx = cos(pos->pa);
	pos->pdy = sin(pos->pa);
	if (pos->rotleft == 1)
	{
		pos->pa -= 0.04;
		if (pos->pa < 0)
			pos->pa += 2 * PI;
		drawPlayer(pos->px, pos->py);
	}
	if (pos->rotright == 1)
	{
		pos->pa += 0.04;
		if (pos->pa > 2 * PI)
			pos->pa -= 2 * PI;
		drawPlayer(pos->px, pos->py);
	}
}
