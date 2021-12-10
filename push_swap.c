/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:17:44 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 07:00:42 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack;

	init_struct(&stack);
	read_stack(&stack, argc, argv);
	sort(&stack);
	clean_exit(&stack, OK);
	return (0);
}
