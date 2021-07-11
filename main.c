/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:17:44 by igomez-p          #+#    #+#             */
/*   Updated: 2021/07/11 19:20:45 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	checker(t_stack *s)
{
	char op[5];
	
	ft_memset(op, 0, 5);
	while (read(0, op, 5))
	{
		printf("----\n");
		if (op[0] == 's')
		{
			if (op[1] == 'a' && op[2] == 'b' && op[3] == '\n')
			{
				swap(s, OP_AB);
				write(1, "sab", 3);
			}
			else if (op[1] == 'a' && op[2] == '\n')
			{
				swap(s, OP_A);
				write(1, "sa", 2);			
			}
			else if (op[2] == 'b' && op[2] == '\n')
			{
				swap(s, OP_B);
				write(1, "sb", 2);			
			}
		}
		else if (op[0] == 'p')
		{
			if (op[1] == 'a' && op[2] == '\n')
			{
				push(s, OP_A);
				write(1, "pa", 2);
			}
			else if (op[1] == 'b' && op[2] == '\n')
			{
				push(s, OP_B);
				write(1, "pb", 2);
			}
		}
		else if (op[0] == 'r')
		{
			if (op[1] == 'r')
			{
				if (op[2] == 'a' && op[3] == '\n')
				{
					reverse_rotate(s, OP_A);
					write(1, "rra", 3);
				}
				else if (op[2] == 'b' && op[3] == '\n')
				{
					reverse_rotate(s, OP_B);
					write(1, "rrb", 3);
				}
			}
			else if (op[1] == 'a' && op[2] == '\n')
			{
				rotate(s, OP_A);
				write(1, "ra", 2);			
			}
			else if (op[1] == 'b' && op[2] == '\n')
			{
				rotate(s, OP_B);
				write(1, "rb", 2);			
			}
		}
		write_result(s);
		ft_memset(op, 0, 5);
	}
}

int main(int argc, char *argv[])
{
	t_stack stack;
	
	init_struct(&stack);
	if (argc < 3)
		clean_exit(&stack);
	read_stack(&stack, argc, argv);
	write_result(&stack);

	checker(&stack);

	return (0);
}