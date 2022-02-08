/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:47:01 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 15:43:15 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				elem;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	int		max[3];
	int		min;
	int		cnt;
}				t_stack;

typedef struct s_op
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	min_op;
}				t_op;

/*
*** main ***
*/
void	handle_error(int flag, t_stack *stack);

/*
*** simple_sort ***
*/
void	sort_3(t_stack *a, t_stack *b);
void	sort_2(t_stack *a, t_stack *b);
void	simple_sort(t_stack *a, t_stack *b);

/*
*** get_values ***
*/
char	*get_values_sub(t_stack *a, const char *str, int sign);
char	*get_values(t_stack *a, const char *str);

/*
*** do_op ***
*/
int		ft_strcmp(const char *s1, const char *s2);
void	do_op_sub_2(t_stack *a, t_stack *b, char *op);
void	do_op_sub_1(t_stack *a, t_stack *b, char *op);
void	do_op(t_stack *a, t_stack *b, char *op);

/*
*** op ***
*/
int		push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	rotate(t_stack *a);
void	reverse_rotate(t_stack *a);

/*
*** stack utils ***
*/
void	init_stack(t_stack *stack);
t_node	*getnode(t_node *prev, t_node *next, int elem);
void	free_stack(t_stack *stack);
int		add_node(t_stack *stack, int elem);
int		remove_node(t_stack *stack);

/*
*** for test ***
*/
void	print_stack(t_stack *stack);

#endif
