/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_map_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:10:32 by violetyeh         #+#    #+#             */
/*   Updated: 2017/07/11 16:07:07 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		f_check_char(char *str, int i)
{
	int		multiplier;
	int		i_mul;
	int		c;

	multiplier = 1;
	i_mul = 0;
	c = 1;
	if(f_check_char_b(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if ((str[i] == '\n' && str[i + 1] == '\n'))
		{
			if (i != (19 * multiplier) + (i_mul * 2))
				return (0);
			multiplier++;
			i_mul++;
			c++;
		}
		i++;
	}
	return (1); 
}

int		f_check_char_b(char *str)
{
	if ((str[ft_strlen(str) - 1] != '\n') ||\
		((int)ft_strlen(str) / 21 + 1 > 27))
		return (0);
	if ((str[ft_strlen(str) - 1] == '\n') &&\
		(str[ft_strlen(str) - 2] == '\n'))
		return (0);
	return (1);
}

int				f_check_newline(char *str)
{
	int cmpt;

	cmpt = 20;
	while (str[cmpt] != '\0' && cmpt < (int)ft_strlen(str))
	{
		if (str[cmpt] != '\n')
			return (0);
		cmpt = cmpt + 21;
	}
	if (str[(int)ft_strlen(str)] != '\0')
		return (0);
	return (1);
}

int				f_check_sharp(char *str, int i)
{
	int sharp_counter;

	sharp_counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			sharp_counter++;
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			if (sharp_counter != 4)
				return (0);
			sharp_counter = 0;
		}
		i++;
	}
	return (1);
}

int				f_check_links(char *str, int i)
{
	int	link_counter;
	int	c;

	link_counter = 0;
	c = 20;
	while (i < (int)ft_strlen(str))
	{
		link_counter = 0;
		while ((i != c + 1) && (i < (int)ft_strlen(str)))
		{
			if (str[i] == '#' && str[i + 1] == '#' && (i + 1 < c + 1))
				link_counter++;
			if (str[i] == '#' && str[i + 5] == '#' && (i + 5 < c + 1))
				link_counter++;
			if (str[i] == '#' && str[i - 1] == '#' && (i - 1 > c - 21))
				link_counter++;
			if (str[i] == '#' && str[i - 5] == '#' && (i - 5 > c - 21))
				link_counter++;
			i++;
		}
		if (link_counter != 6 && link_counter != 8)
			return (0);
		c = c + 21;
	}
	return (1);
}
