/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:17:44 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 06:14:57 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	checker(t_stack *s)
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
}*/

int main(int argc, char *argv[])
{
	t_stack stack;
	
	init_struct(&stack);
	read_stack(&stack, argc, argv);
	sort(&stack);
	printf("\n");
	for (int i = 0; i < stack.len_a; i++)
		printf("%d ", stack.stack_a[i]);
	printf("\n");
	clean_exit(&stack, OK);

	return (0);
}