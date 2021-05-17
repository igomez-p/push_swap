/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:17:44 by igomez-p          #+#    #+#             */
/*   Updated: 2021/05/18 00:00:11 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char *argv[])
{
	t_stack stack;
	stack.stack_a = NULL;
	stack.stack_b = NULL;

	if (argc < 3)
		clean_exit(&stack);
	read_stack(&stack, argc, argv);
	write_result(&stack);
	return (0);
}