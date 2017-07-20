/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyeh <vyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 17:15:31 by vyeh              #+#    #+#             */
/*   Updated: 2017/07/02 19:24:11 by vyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char*)malloc((ft_strlen(s1) + 1) * (sizeof(char)));
	if (s2 == NULL)
		return (NULL);
	return (ft_strcpy(s2, s1));
}
