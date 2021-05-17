/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 23:08:08 by igomez-p          #+#    #+#             */
/*   Updated: 2021/05/18 00:07:31 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_arguments(char *arg, int i)
{
	int	num;
	int	k;

	if (!i && ft_strncmp(arg, "./push_swap", 11))
		return (FAIL);
	else if (i)
	{
		k = 0;
		while (ft_isdigit((int)arg[k]))
			k++;
		// TODO: gestionar error para el número
		if (arg[k])
			return (FAIL);
		num = ft_atoi((const char *)arg);
		if (/*num < MIN_INT || */num > MAX_INT)
			return (FAIL);
		return (num);
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

	if (!check_arguments(arg[0], 0))
		clean_exit(s);
	s->stack_a = (int *)malloc(sizeof(int) * (narg - 1));
	if (!s->stack_a)
		clean_exit(s);
	i = 0;
	while (++i < narg)
	{
		num = check_arguments(arg[i], i); 
		if (num == FAIL)
			clean_exit(s);
		s->stack_a[i - 1] = num;			
	}
}

void	write_result(t_stack *s)
{
	int	i;

	i = 0;
	while (s->stack_a[i])
	{
		printf("%d ", s->stack_a[i]);
		i++;
	}
	// TODO: Revisar: aparece en algunas ocasiones un 1041 como último número
}