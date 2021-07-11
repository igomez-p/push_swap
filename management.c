/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:08:08 by igomez-p          #+#    #+#             */
/*   Updated: 2021/07/11 19:11:54 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init_struct(t_stack *s)
{
	s->stack_a = NULL;
	s->stack_b = NULL;
	s->total_a = 0;
	s->total_b = 0;
}

int	check_arguments(char *arg, int i, int *num)
{
	int	k;

	if (!i && ft_strncmp(arg, "./push_swap", 11))
		return (FAIL);
	else if (i)
	{
		k = 0;
		if (arg[k] == '-')
			k++;
		while (ft_isdigit((int)arg[k]))
			k++;
		if (arg[k])
			return (FAIL);
		*num = ft_atoi((const char *)arg);
		if (*num > MAX_INT)
			return (FAIL);
	}
	return (OK);
}

void	clean_exit(t_stack *s)
{
	write(1, "Error\n", 6);
	if (s->stack_a)
		free(s->stack_a);
	if (s->stack_b)
		free(s->stack_b);
	exit(1);
}

void	read_stack(t_stack *s, int narg, char **arg)
{
	int	i;
	int	num;

	if (!check_arguments(arg[0], 0, NULL))
		clean_exit(s);
	s->stack_a = (int *)malloc(sizeof(int) * (narg - 1));
	if (!s->stack_a)
		clean_exit(s);
	ft_memset(&s->stack_a[0], 0, narg - 1);
	i = 0;
	//printf("narg: %d\n", narg);
	while (++i < narg)
	{
		if (!check_arguments(arg[i], i, &num))
			clean_exit(s);
		//printf("num: %d\n", num);
		s->stack_a[i - 1] = num;			
	}
	s->stack_a[i - 1] = 0;
	s->total_a = i - 1;
}

void	write_result(t_stack *s)
{
	int	i;

	i = 0;
	write(1, "STACK A: ", 10);
	while (i < s->total_a)
	{
		printf("%d ", s->stack_a[i]);
		i++;
	}
	i = 0;
	write(1, "STACK B: ", 10);
	while (i < s->total_b)
	{
		printf("%d ", s->stack_b[i]);
		i++;
	}
}