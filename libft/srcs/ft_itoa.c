/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 17:07:11 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/02 18:23:35 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*a;
	int				len;
	int				i;

	i = 0;
	len = get_length(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	a = ft_strnew(len);
	if (a == NULL)
		return (0);
	if (n < 0)
	{
		n *= -1;
		a[0] = '-';
	}
	a[len] = '\0';
	if (n == 0)
		a[--len] = '0';
	while (n > 0)
	{
		a[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}
