/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:58:33 by cweather          #+#    #+#             */
/*   Updated: 2017/07/09 15:00:24 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstrev(t_list **alst)
{
	t_list	*p;
	t_list	*c;
	t_list	*n;

	p = NULL;
	c = *alst;
	while (c)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	*alst = p;
}
