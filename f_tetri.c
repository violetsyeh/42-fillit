/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_tetri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: violetyeh <violetyeh@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:01:22 by violetyeh         #+#    #+#             */
/*   Updated: 2017/07/11 16:08:36 by violetyeh        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*f_read(int argc, char **argv)
{
	int		fd;
	char	*str1;
	char	buf[BUFFER + 1];
	int		ret;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, BUFFER)) != 0)
	{
		str1 = buf;
		buf[ret] = '\0';
	}
	if (buf[ret] == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	str1[BUFFER] = '\0';
	close (fd);
	return (str1);
}

int		f_nb_tetri(char *str1)
{
	return (ft_strlen(str1) / 21 + 1);
}
