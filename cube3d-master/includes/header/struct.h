/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:10:45 by home              #+#    #+#             */
/*   Updated: 2020/12/01 21:06:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "random.h"

typedef struct		s_vector
{
	double x;
	double y;
	double z;
}		t_vector;

typedef	struct		s_size_win
{
	int	x;
	int y;
}		t_size_win;

typedef struct		s_iterator
{
	int i;
	int j;
}		t_iterator;

#endif
