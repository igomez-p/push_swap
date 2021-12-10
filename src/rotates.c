/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 07:34:20 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 07:37:34 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack *s)
{
	int	*aux;
	int	temp;
	int	i;

	if (!s->stack_a)
		return ;
	aux = (int *)malloc(sizeof(int) * s->len_a);
	if (!aux)
		return ;
	temp = s->stack_a[0];
	i = 0;
	while (++i < s->len_a)
		aux[i - 1] = s->stack_a[i];
	aux[s->len_a - 1] = temp;
	i = -1;
	while (++i < s->len_a)
		s->stack_a[i] = aux[i];
	free(aux);
}

void	rotate_b(t_stack *s)
{
	int	*aux;
	int	temp;
	int	i;

	if (!s->stack_b)
		return ;
	aux = (int *)malloc(sizeof(int) * s->len_b);
	if (!aux)
		return ;
	temp = s->stack_b[0];
	i = 0;
	while (++i < s->len_b)
		aux[i - 1] = s->stack_b[i];
	aux[s->len_b - 1] = temp;
	i = -1;
	while (++i < s->len_b)
		s->stack_b[i] = aux[i];
	free(aux);
}

void	reverse_rotate_a(t_stack *s)
{
	int	*aux;
	int	temp;
	int	i;

	if (!s->stack_a)
		return ;
	aux = (int *)malloc(sizeof(int) * s->len_a);
	if (!aux)
		return ;
	temp = s->stack_a[s->len_a - 1];
	i = 0;
	while (++i < s->len_a)
		aux[i] = s->stack_a[i - 1];
	aux[0] = temp;
	i = -1;
	while (++i < s->len_a)
		s->stack_a[i] = aux[i];
	free(aux);
}

void	reverse_rotate_b(t_stack *s)
{
	int	*aux;
	int	temp;
	int	i;

	if (!s->stack_b)
		return ;
	aux = (int *)malloc(sizeof(int) * s->len_b);
	if (!aux)
		return ;
	temp = s->stack_b[s->len_b - 1];
	i = 0;
	while (++i < s->len_b)
		aux[i] = s->stack_b[i - 1];
	aux[0] = temp;
	i = -1;
	while (++i < s->len_b)
		s->stack_b[i] = aux[i];
	free(aux);
}
