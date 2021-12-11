/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:45:21 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/11 10:58:06 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_sort(t_stack *s)
{
	if (!is_sorted(s->stack_a, s->len_a) && s->len_a == 2)
		swap(s, OP_A);
	else if (!is_sorted(s->stack_a, s->len_a) && s->len_a == 3)
	{
		if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
			&& s->stack_a[1] < s->stack_a[2])
			swap(s, OP_A);
		else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] > s->stack_a[2]
			&& s->stack_a[1] > s->stack_a[2])
			reverse_rotate(s, OP_A);
		else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
			&& s->stack_a[1] > s->stack_a[2])
		{
			swap(s, OP_A);
			rotate(s, OP_A);
		}
		else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2]
			&& s->stack_a[1] < s->stack_a[2])
			rotate(s, OP_A);
		else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2]
			&& s->stack_a[1] > s->stack_a[2])
		{
			swap(s, OP_A);
			reverse_rotate(s, OP_A);
		}
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

static void	large_sortb(t_stack *s)
{
	int	i;
	int	max;

	if (is_sorted(s->stack_a, s->len_a))
	{
		while (s->len_b)
		{
			i = 0;
			max = max_number(s->stack_b, s->len_b);
			while (i < s->len_b)
			{
				if (s->stack_b[i] == max)
					i = rotate_push(s, i, OP_B);
				else if (s->stack_b[s->len_b - i - 1] == max)
					i = reverse_rotate_push(s, i + 1, OP_B);
				else
					i++;
			}
		}
	}
}

void	large_sort(t_stack *s)
{
	int	i;
	int	mid;

	i = 0;
	if (s->len_a > 3 && !is_sorted(s->stack_a, s->len_a))
	{
		mid = midpoint(s->stack_a, s->len_a);
		while (i < s->len_a && s->len_a > 3)
		{
			if (s->stack_a[i] < mid)
				i = rotate_push(s, i, OP_A);
			else if (s->stack_a[s->len_a - i - 1] < mid)
				i = reverse_rotate_push(s, i + 1, OP_A);
			else
				i++;
		}
		three_sort(s);
	}
	large_sortb(s);
	while (s->len_b)
		large_sort(s);
}

void	sort(t_stack *s)
{
	if (s->len_a <= 3)
	{
		while (!is_sorted(s->stack_a, s->len_a))
			three_sort(s);
	}
	else if (s->len_a <= 5)
		five_sort(s);
	else
		large_sort(s);
}
