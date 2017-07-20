/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:46:30 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/02 18:23:41 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*p;
	char	*d;

	i = 0;
	p = (char *)s1;
	d = (char *)s2;
	while (i < n)
	{
		if (*p != *d)
			return ((unsigned char)*p - (unsigned char)*d);
		i++;
		p++;
		d++;
	}
	return (0);
}
