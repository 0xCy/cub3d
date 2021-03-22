/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argParse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcyril <gcyril@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:53:26 by home              #+#    #+#             */
/*   Updated: 2021/03/18 15:42:46 by gcyril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header/random.h"

void		arg_parse(int fd, char *line)
{
	parse.i = 0;
	parse.j = 0;
	parse.resHeight = 0;
	parse.resWidth = 0;
	int x;
	int y;
	char **str;
	str = NULL;

	map.map = malloc(sizeof(char *) * (15));
	x = 0;
	y = 0;
	if (!(parse.resParse = malloc(sizeof(char)*100)))
	{
		printf("error with malloc size in resParse");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		parse.i = 0;
		while (line[parse.i] != '\0')
		{
			if (line[parse.i] == 'R')
			{
				while (line[parse.i] != '\0')
				{
					parse.resParse[parse.i] = line[parse.i];
					parse.i++;
				}
				parse.resHeight = ft_atoi_cub(parse.resParse);
				parse.resWidth = ft_atoi_cub(parse.resParse);
				parse.resParse = NULL;
			}
			if (line[parse.i] == 'F')
			{

				split_rgb(line);
				convert(parse.r, parse.g, parse.b);
			}
			parse.i++;
		}
		if (line[0] == '1')
		{
			map.map[x] = malloc(sizeof(char) * (ft_strlen(line) + 1));
			if (map.sizeWidth < ft_strlen(line))
				map.sizeWidth = ft_strlen(line);
			map.map[x] = line;
			while(map.map[x][y])
			{
				if (map.map[x][y] == '2')
				{
					map.x2 = x;
					map.y2 = y;
				}
				y++;
			}
			y = 0;
			x++;
		}
	}
	map.sizeHeight = x;
	map.map[x] = line;
	map.map[x + 1] = NULL;
	free(parse.resParse);
	close(fd);
}
