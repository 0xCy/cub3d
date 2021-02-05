/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuelchetrit <samuelchetrit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:28:59 by home              #+#    #+#             */
/*   Updated: 2020/12/18 04:33:05 by samuelchetr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header/random.h"

int		ft_atoi_cub(char *str)
{
	int x;
    int res;
	
	res = 0;	
	x = 0;
	while (str[x] == ' ' || str[x] == '\t' || str[x] == '\n' || str[x] == '\r'
		 || str[x] == '\v' || str[x] == '\f' || str[x] == 'R')
    	x++;
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		res = res * 10 + (str[x] - 48);
    	x++;
    }
    return (res);
}

void		split_rgb(char *line)
{
	int x;

	x = 0;
	while (line[x])
	{
		if (line[x] > '0' && line[x] < '9')
		{
			while (line[x] && line[x] >= '0' && line[x] <= '9')
			{	
				parse.r = parse.r * 10 + (line[x] -  48);
				x++;
			}
			x++;
			while (line[x] && line[x] >= '0' && line[x] <= '9')
			{	
				parse.g = parse.g * 10 + (line[x] -  48);
				x++;
			}
			x++;
			while (line[x] && line[x] >= '0' && line[x] <= '9')
			{	
				parse.b = parse.b * 10 + (line[x] -  48);
				x++;
			}
		}
		x++;
	}
}

int	convert(int r, int g, int b)
{
	int	result;

	result = 0;
  	result += r << 16;
  	result += g << 8;
  	result += b;
  	return (result);
}