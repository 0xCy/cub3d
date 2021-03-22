/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:16:32 by home              #+#    #+#             */
/*   Updated: 2021/03/18 15:40:42 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header/random.h"

int		size_of_map(char *str)
{
	int y;

	y = 0;
	while(str[y])
	{
		y++;
	}
	return (y);
}

void	drawMap(void)
{
	map.line = 0;
	map.column = 0;
	while (map.line < map.sizeHeight)
	{
		while (map.map[map.line][map.column])
		{
			if (map.map[map.line][map.column] == '1')
				drawMap2(map.line,map.column);
			map.column++;
		}
		map.column = 0;
		map.line++;
	}
}

void	drawMap2(int a, int b)
{
	map.widthF = parse.resWidth / map.sizeHeight;
	map.heightF = parse.resHeight/ map.sizeWidth;
	map.mapWidth = map.widthF + (map.widthF * a);
	map.mapHeight = map.heightF + (map.heightF * b);
	map.width = 0 + (map.widthF * a);
	map.height = 0 + (map.heightF * b);
	map.tmp = map.height;
	while (map.height < map.mapHeight)
	{
		myPixel_put(&img, map.height, map.width, 0xFFFFFF);
		map.height++;
		if (map.height == map.mapHeight && map.width < map.mapWidth)
		{
			myPixel_put(&img, map.height, map.width, 0xFFFFFF);
			map.height = map.tmp;
			map.width++;
		}
	}
}
