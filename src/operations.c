/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:19:15 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/07 14:38:18 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *s)
{
	int	temp;

	if (!s->stack_a)
		return ;
	temp = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = temp;
}

void	swap_b(t_stack *s)
{
	int	temp;

	if (!s->stack_b)
		return ;
	temp = s->stack_b[0];
	s->stack_b[0] = s->stack_b[1];
	s->stack_b[1] = temp;
}

void	push_a(t_stack *s)
{
	int *temp;

	if (!s->stack_b)
		return ;
	temp = (int *)malloc(sizeof(int)*(s->len_a + 1));
	if (!temp)
		return ;
	ft_memset(temp, 0, s->len_a + 1);
	ft_memcpy(&temp[1], s->stack_a, s->len_a);
	temp[0] = s->stack_b[0];
	s->len_a++;
	free(s->stack_a);
	s->stack_a = (int *)malloc(sizeof(int)*s->len_a);
	if (!s->stack_a)
		return ;
	ft_memset(s->stack_a, 0, s->len_a);
	ft_memcpy(s->stack_a, temp, s->len_a);
	ft_memcpy(s->stack_b, &s->stack_b[1], s->len_b - 1);
	s->len_b--;
	free(temp);
}

void	push_b(t_stack *s)
{
	int *temp;

	if (!s->stack_a)
		return ;
	temp = (int *)malloc(sizeof(int)*(s->len_b + 1));
	if (!temp)
		return ;
	ft_memset(temp, 0, s->len_b + 1);
	ft_memcpy(&temp[1], s->stack_b, s->len_b);
	temp[0] = s->stack_a[0];
	free(s->stack_b);
	s->stack_b = (int *)malloc(sizeof(int)*(++s->len_b));
	if (!s->stack_b)
		return ;
	ft_memset(s->stack_b, 0, s->len_b);
	ft_memcpy(s->stack_b, temp, s->len_b);
	free(temp);
	temp = (int *)malloc(sizeof(int)*(--s->len_a));
	if (!temp)
		return ;
	printf("stack a [%d %d %d %d %d]\n", s->stack_a[0], s->stack_a[1], s->stack_a[2], s->stack_a[3], s->stack_a[4]);
	ft_memset(temp, 0, s->len_a);
	ft_memcpy(temp, &s->stack_a[1], s->len_a);
	printf("temp [%d %d %d %d]\n", temp[0], temp[1], temp[2], temp[3]);
	free(s->stack_a);
	s->stack_a = temp;
	/*s->stack_a = (int *)malloc(sizeof(int)*s->len_a);
	if (!s->stack_a)
		return ;
	ft_memset(s->stack_a, 0, s->len_a);
	ft_memcpy(s->stack_a, temp, s->len_a);
	free(temp);*/
}

void	rotate_a(t_stack *s)
{
	int	*aux;
	int temp;
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
	int temp;
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
	int temp;
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
	int temp;
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