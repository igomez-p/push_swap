/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:55:15 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 06:53:09 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		*d;
	int		*s;
	size_t	i;

	d = (int *)dst;
	s = (int *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	int		*b2;
	size_t	i;

	i = 0;
	b2 = (int *)b;
	while (i < len)
	{
		b2[i] = (int)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	int		*aux;
	size_t	i;

	aux = (int *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = 0;
		i++;
	}
}
