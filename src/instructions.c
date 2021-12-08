/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:38:51 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/08 14:17:05 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *s, int op)
{
    if (op == OP_A)
        swap_a(s);
    else if (op == OP_B)
        swap_b(s);
    else if (op == OP_AB)
    {
        swap_a(s);
        swap_b(s);
    }
}

void	push(t_stack *s, int op)
{
    if (op == OP_A)
        push_a(s);
    else if (op == OP_B)
        push_b(s);
}

void	rotate(t_stack *s, int op)
{
    if (op == OP_A)
        rotate_a(s);
    else if (op == OP_B)
        rotate_b(s);
    else if (op == OP_AB)
    {
        rotate_a(s);
        rotate_b(s);
    }
}

void	reverse_rotate(t_stack *s, int op)
{
    if (op == OP_A)
        reverse_rotate_a(s);
    else if (op == OP_B)
        reverse_rotate_b(s);
    else if (op == OP_AB)
    {
        reverse_rotate_a(s);
        reverse_rotate_b(s);
    }
}
