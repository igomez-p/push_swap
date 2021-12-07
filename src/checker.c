/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:00:37 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/07 08:30:59 by igomez-p         ###   ########.fr       */
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