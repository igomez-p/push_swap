/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:00:37 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 07:25:53 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit(char *num)
{
	int	j;

	j = 0;
	while (num[j])
	{
		if (ft_isdigit(num[j]) || (num[j] == '-' && !j))
			j++;
		else
			return (FAIL);
	}
	return (OK);
}

int	check_is_repeated(char **num, int i)
{
	int	j;
	int	len;
	int	len2;

	len = ft_strlen(num[i]);
	j = i - 1;
	while (j >= 0)
	{
		len2 = ft_strlen(num[j]);
		if (!ft_strncmp(num[i], num[j], len) && len == len2)
			return (FAIL);
		j--;
	}
	return (OK);
}

int	is_sorted(int *s, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (s[i] > s[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	midpoint(int *stack, int len)
{
	int	*aux;
	int	mid;

	aux = (int *)malloc(sizeof(int) * len);
	ft_memcpy(aux, stack, len);
	sort_stack(aux, len);
	if (len == 4)
		mid = aux[(len - 1) / 2];
	else if (len >= 9 && len <= 15)
		mid = aux[len / 3];
	else if (len <= 8)
		mid = aux[len / 2];
	else if (len == 500)
		mid = aux[len / 11];
	else if (len >= 250)
		mid = aux[len / 10];
	else if (len >= 100)
		mid = aux[len / 6];
	else
		mid = aux[len / 5];
	free(aux);
	aux = NULL;
	return (mid);
}

int	max_number(int *s, int len)
{
	int	max;
	int	i;

	i = 1;
	max = s[0];
	while (i < len)
	{
		if (s[i] > max)
			max = s[i];
		i++;
	}
	return (max);
}
