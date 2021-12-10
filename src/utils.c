/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 07:01:19 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 07:23:28 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(int *stack, int len)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		if (stack[i] > stack[i + 1])
		{
			tmp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	rotate_push(t_stack *s, int n, int op)
{
	int	i;

	i = -1;
	while (++i < n)
		rotate(s, op);
	if (op == OP_A)
		push(s, OP_B);
	else if (op == OP_B)
		push(s, OP_A);
	return (0);
}

int	reverse_rotate_push(t_stack *s, int n, int op)
{
	int	i;

	i = -1;
	while (++i < n)
		reverse_rotate(s, op);
	if (op == OP_A)
		push(s, OP_B);
	else if (op == OP_B)
		push(s, OP_A);
	return (0);
}
