/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 15:11:17 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/02 19:11:02 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_words(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			w++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (w);
}

static	int		wd_len(char const *s, char c)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**p;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(p = (char**)malloc(sizeof(char *) * (num_words(s, c) + 1))))
		return (NULL);
	while (i < num_words(s, c))
	{
		if ((p[i] = (char*)malloc(sizeof(char) * (wd_len(&s[k], c) + 1))) == 0)
			return (NULL);
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
			p[i][j++] = s[k++];
		p[i][j] = '\0';
		i++;
	}
	p[i] = 0;
	return (p);
}
