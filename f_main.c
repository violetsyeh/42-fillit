/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 13:03:20 by cweather          #+#    #+#             */
/*   Updated: 2017/07/11 16:05:41 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str2;
	int		tetri;

	if(!f_read(argc, argv))
		return (0);
	str2 = f_read(argc, argv);
	tetri = f_nb_tetri(str2);
	if(f_verify_tetri(str2) != 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	f_solve(str2);
	return (0);
}
