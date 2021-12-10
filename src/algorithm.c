/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:45:21 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 06:10:48 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	three_sort(t_stack *s)
{
	while (!is_sorted(s->stack_a, s->len_a) && s->len_a <= 3)
	{
		if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
			&& s->stack_a[1] < s->stack_a[2])
			swap(s, OP_A);
		else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2]
			&& s->stack_a[1] > s->stack_a[2])
			reverse_rotate(s, OP_A);
		else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
			&& s->stack_a[1] > s->stack_a[2])
			reverse_rotate(s, OP_A);
		else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2]
			&& s->stack_a[1] < s->stack_a[2])
			rotate(s, OP_A);
		else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2]
			&& s->stack_a[1] > s->stack_a[2])
			swap(s, OP_A);
	}
}

void	five_sort(t_stack *s)
{
	int	i;
	int	n;

	if (is_sorted(s->stack_a, s->len_a))
		return ;
	while (s->len_a > 3)
	{
		i = 0;
		n = s->stack_a[0];
		while (i < s->len_a - 1)
		{
			if (s->stack_a[i + 1] < n)
				n = s->stack_a[i + 1];
			i++;
		}
		while (s->stack_a[0] != n)
			rotate(s, OP_A);
		push(s, OP_B);
	}
	three_sort(s);
	push(s, OP_A);
	push(s, OP_A);
}

void	sort(t_stack *s)
{
	if (s->len_a <= 3)
		three_sort(s);
	else if (s->len_a <= 5)
		five_sort(s);
	else
		large_sort(s);
}
