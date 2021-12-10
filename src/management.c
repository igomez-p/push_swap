/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:08:08 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 07:17:54 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_struct(t_stack *s)
{
	s->stack_a = NULL;
	s->stack_b = NULL;
	s->len_a = 0;
	s->len_b = 0;
}

void	clean_exit(t_stack *s, int error)
{
	if (error)
		write(1, "Error\n", 6);
	if (s->stack_a)
		free(s->stack_a);
	if (s->stack_b)
		free(s->stack_b);
	exit(1);
}

static void	save_numbers(t_stack *s, char **num)
{
	int	i;

	i = 0;
	s->stack_a = (int *)malloc(sizeof(int) * s->len_a);
	while (num[i])
	{
		s->stack_a[i] = ft_atoi(num[i]);
		if ((num[i][0] != '-' || num[i][1] != '1') && s->stack_a[i] == -1)
			clean_exit(s, FAIL);
		if (num[i][0] != '0' && !s->stack_a[i])
			clean_exit(s, FAIL);
		i++;
	}
}

void	read_stack(t_stack *s, int narg, char **arg)
{
	char	**num;
	int		i;

	i = 0;
	if (narg < 2 || ft_strncmp(arg[0], "./push_swap", 11))
		clean_exit(s, FAIL);
	num = &arg[1];
	while (num[i])
	{
		if (check_digit(num[i]) == FAIL)
			clean_exit(s, FAIL);
		if (check_is_repeated(num, i) == FAIL)
			clean_exit(s, FAIL);
		i++;
	}
	s->len_a = i;
	save_numbers(s, num);
}
