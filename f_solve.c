/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:40:41 by cweather          #+#    #+#             */
/*   Updated: 2017/07/14 14:13:03 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		f_is_possible(char **grid, t_position tetriminos, \
	int pos, int cut)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = pos / cut;
	j = pos % cut;
	while (c < 4)
	{
		if ((i + tetriminos.y[c] > cut - 1 ||\
			j + tetriminos.x[c] > cut - 1))
			return (0);
		if ((i + tetriminos.y[c]) < 0 || (j + tetriminos.x[c]) < 0)
			return (0);
		if ((grid[i + tetriminos.y[c]][j + tetriminos.x[c]] != '.'))
			return (0);
		c++;
	}
	return (1);
}

int		f_check_nb_tetri(char **grid, int cut)
{
	int j;
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < cut)
	{
		j = 0;
		while (j < cut)
		{
			if (grid[i][j] == 'A' + k)
			{
				k++;
				i = 0;
				j = 0;
			}
			j++;
		}
		i++;
	}
	return (k);
}

void	f_place_tetri(char **grid, t_position tetriminos, int pos, int k)
{
	int i;
	int j;
	int p;
	int cut;

	p = 0;
	cut = ft_strlen(grid[0]);
	i = pos / cut;
	j = pos % cut;
	while (p < 4)
	{
		grid[i + tetriminos.y[p]][j + tetriminos.x[p]] = 'A' + k;
		p++;
	}
}

int		f_print_tetri(char **grid, t_position *tetriminos, \
	int nb_tetri, int k)
{
	int i;
	int j;
	int pos;
	int cut;

	cut = ft_strlen(grid[0]);
	pos = 0;
	i = pos / cut;
	j = pos % cut;
	if (f_check_nb_tetri(grid, cut) == nb_tetri)
		return (1);
	while (pos <= cut * cut)
	{
		if (f_is_possible(grid, tetriminos[k], pos, cut))
		{
			f_place_tetri(grid, tetriminos[k], pos, k);
			if (f_print_tetri(grid, tetriminos, nb_tetri, k + 1))
				return (1);
			f_remove_tetri(grid, k, cut);
		}
		pos++;
	}
	return (0);
}

void	f_solve(char *str)
{
	int			cut;
	char		**grid;
	int			nb_tetri;
	int			i;
	t_position	*tetri;

	i = 1;
	tetri = f_map(str, 0, 0, 0);
	nb_tetri = f_nb_tetri(str);
	tetri = f_zero(tetri, nb_tetri);
	cut = f_sqrt(nb_tetri) * 2 - 1;
	grid = f_final_grid(cut);
	while (f_print_tetri(grid, tetri, nb_tetri, 0) == 0)
	{
		f_free_grid(grid, cut + i);
		grid = f_final_grid(cut + i);
		f_print_tetri(grid, tetri, nb_tetri, 0);
		i++;
	}
	f_display_tab(grid, cut + i - 1);
	free(grid);
}
