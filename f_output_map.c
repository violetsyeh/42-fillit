/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_output_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:32:27 by cweather          #+#    #+#             */
/*   Updated: 2017/07/11 15:45:57 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	f_display_tab(char **grid, int cut)
{
	int	i;

	i = 0;
	while (i < cut)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr(grid[i]);
}

void	f_free_grid(char **grid, int cut)
{
	int		i;

	i = 0;
	while (i < cut)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
