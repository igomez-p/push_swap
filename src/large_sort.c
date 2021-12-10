/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:39:37 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 06:13:01 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    sort_stack(int *stack, int len)
{
	int tmp;
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

int     midpoint(int *stack, int len)
{
	int *aux;
	int mid;

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

int		max_number(int *s, int len)
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

void	rotate_push(t_stack *s, int n, int op)
{
	int	i;

	i = -1;
	while (++i < n)
		rotate(s, op);
	if (op == OP_A)
		push(s, OP_B);
	else if (op == OP_B)
		push(s, OP_A);
}

void	reverse_rotate_push(t_stack *s, int n, int op)
{
	int	i;

	i = -1;
	while (++i < n)
		reverse_rotate(s, op);
	if (op == OP_A)
		push(s, OP_B);
	else if (op == OP_B)
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
				{
					rotate_push(s, i, OP_B);
					i = 0;
				}
				else if (s->stack_b[s->len_b - i - 1] == max)
				{
					reverse_rotate_push(s, i + 1, OP_B);
					i = 0;
				}
				else
					i++;
			}
		}
	}
}

void    large_sort(t_stack *s)
{
	int i;
	int mid;

	i = 0;
	if (s->len_a > 3 && !is_sorted(s->stack_a, s->len_a))
	{
		mid = midpoint(s->stack_a, s->len_a);
		while (i < s->len_a && s->len_a > 3)
		{
			if (s->stack_a[i] < mid)
			{
				rotate_push(s, i, OP_A);
				i = 0;
			}
			else if (s->stack_a[s->len_a - i - 1] < mid)
			{
				reverse_rotate_push(s, i + 1, OP_A);
				i = 0;
			}
			else
				i++;
		}
		three_sort(s);
	}
/*	printf("--- lenA %d\n", s->len_a);
	for (int i = 0; i < s->len_a; i++)
		printf("%d ", s->stack_a[i]);
	printf("\n");
	printf("--- lenB %d\n", s->len_b);
	for (int i = 0; i < s->len_b; i++)
		printf("%d ", s->stack_b[i]);
	printf("\n\n");*/
	
	large_sortb(s);

/*	printf("--- lenA %d\n", s->len_a);
	for (int i = 0; i < s->len_a; i++)
		printf("%d ", s->stack_a[i]);
	printf("\n");
	printf("--- lenB %d\n", s->len_b);
	for (int i = 0; i < s->len_b; i++)
		printf("%d ", s->stack_b[i]);
	printf("\n\n");*/

	while (s->len_b)
		large_sort(s);
}