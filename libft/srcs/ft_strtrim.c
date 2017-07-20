/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:51:09 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/02 18:24:00 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*temp;

	i = 0;
	if (!s)
		return (NULL);
	l = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	l = ft_strlen(&s[i]) - 1;
	while (s[i] && (s[l + i] == ' ' || s[l + i] == '\t' || s[l + i] == '\n'))
		l--;
	temp = ft_strnew(l + 1);
	if (!temp)
		return (NULL);
	ft_strncpy(temp, s + i, l + 1);
	return (temp);
}
