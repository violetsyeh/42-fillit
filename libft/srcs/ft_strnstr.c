/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:19:56 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/03 15:31:16 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			while (s2[j] != '\0' && s1[i + j] == s2[j] && i + j < len)
				j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
			i++;
			j = 0;
		}
		return (NULL);
	}
}
