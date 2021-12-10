/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez-p <ire.go.pla@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:19:29 by igomez-p          #+#    #+#             */
/*   Updated: 2021/12/10 18:22:25 by igomez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

# define SA		"sa"
# define SB		"sb"
# define SS		"ss"
# define PA		"pa"
# define PB		"pb"
# define RA		"ra"
# define RB		"rb"
# define RR		"rr"
# define RRA	"rra"
# define RRB	"rrb"
# define RRR	"rrr"
# define OK		0
# define FAIL	1
# define OP_A	1
# define OP_B	2
# define OP_AB	3

typedef struct s_stack {
	int			*stack_a;
	int			*stack_b;
	int			len_a;
	int			len_b;
}				t_stack;

void	swap_a(t_stack *s);
void	swap_b(t_stack *s);
void	push_a(t_stack *s);
void	push_b(t_stack *s);
void	rotate_a(t_stack *s);
void	rotate_b(t_stack *s);
void	reverse_rotate_a(t_stack *s);
void	reverse_rotate_b(t_stack *s);

void	swap(t_stack *s, int op);
void	push(t_stack *s, int op);
void	rotate(t_stack *s, int op);
void	reverse_rotate(t_stack *s, int op);

void	init_struct(t_stack *s);
void	clean_exit(t_stack *s, int error);
void	read_stack(t_stack *s, int narg, char **arg);
int		check_digit(char *num);
int		check_is_repeated(char **num, int i);
void	sort(t_stack *s);
int		is_sorted(int *s, int len);
void	sort_stack(int *stack, int len);
int		rotate_push(t_stack *s, int n, int op);
int		reverse_rotate_push(t_stack *s, int n, int op);
int		max_number(int *s, int len);
int		midpoint(int *stack, int len);

int		ft_atoi(const char *str, t_stack *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_split(char const *s1, char c);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
