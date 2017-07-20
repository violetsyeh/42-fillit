/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_verify_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:07:29 by violetyeh         #+#    #+#             */
/*   Updated: 2017/07/11 16:10:14 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		f_verify_tetri(char *str)
{
	int		i;

	i = 0;
	if (f_check_char(str, i) != 1)
		return (1);
	if (f_check_sharp(str, i) != 1)
		return (2);
	if (f_check_links(str, i) != 1)
	{
		return (3);
	}
	if (f_check_newline(str) != 1)
	{
		return (4);
	}
	return (0);
}