/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 18:15:00 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/02 19:14:16 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	char			*str;
	unsigned int	counter;

	str = (char *)s;
	counter = 0;
	if (str)
	{
		while (str[counter])
		{
			str[counter] = '\0';
			counter++;
		}
	}
}
