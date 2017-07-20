/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 19:49:00 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/03 18:08:42 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	unsigned long	nbr;
	int				sign;
	int				overflow;

	nbr = 0;
	sign = 1;
	while (ft_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		overflow = ft_check_overflow(nbr, (*str - '0'), sign);
		if (overflow != 1)
			return (overflow);
		nbr = (nbr * 10) + (*str++ - '0');
	}
	return (nbr * sign);
}
