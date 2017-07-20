/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:31:38 by violetyeh         #+#    #+#             */
/*   Updated: 2017/07/11 16:06:36 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**f_final_grid(int cut)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	grid = (char **)malloc((cut + 1) * sizeof(*grid));
	while (i != cut + 1)
	{
		grid[i] = (char*)malloc((cut + 1) * sizeof(grid));
		i++;
	}
	i = 0;
	while (i < cut)
	{
		grid[i][j] = '.';
		j++;
		if (j == cut)
		{
			grid[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	return (grid);
}

void			f_check_l_and_k(int *l, int *k)
{
	if (*l > 3)
	{
		*l = 0;
		*k = *k + 1;
	}
}

void			f_check_i_and_c(int *i, int *j, int *cmpt, char *str)
{
	if (str[*i] == '\n' && str[*i + 1] == '\n')
	{
		*j = 0;
		*i = *i + 1;
		*cmpt = *cmpt + 1;
	}
}

t_position		*f_map(char *str, int i, int j, int k)
{
	int			l;
	int			c;
	t_position	*tetri;

	tetri = (t_position *)malloc((ft_strlen(str) / 21 + 1)\
		* sizeof(t_position));
	l = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		f_check_i_and_c(&i, &j, &c, str);
		if (str[i] == '#')
		{
			tetri[k].x[l] = i - ((21 * c) + (5 * j));
			tetri[k].y[l] = j;
			l++;
		}
		f_check_l_and_k(&l, &k);
		i++;
	}
	return (tetri);
}

void			f_remove_tetri(char **grid, int k, int cut)
{
	int i;
	int j;

	i = 0;
	while (i <= cut)
	{
		j = 0;
		while (j <= cut)
		{
			if (grid[i][j] == 'A' + k)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}
