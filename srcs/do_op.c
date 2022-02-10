/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:09:30 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/10 18:00:11 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*ptr;

	if (!a->top)
		return (0);
	ptr = a->top;
	while (ptr->next)
	{
		if (ptr->elem > ptr->next->elem)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	print_op(const char *op, int print)
{
	if (print)
	{
		write(1, op, ft_strlen(op));
		write(1, "\n", 1);
	}
}

void	do_op_sub_2(t_stack *a, t_stack *b, const char *op, int print)
{
	if (ft_strcmp(op, "ss") == 0)
	{
		swap(a);
		swap(b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		print_op(op, print);
	}
	else
		handle_error();
}

void	do_op_sub_1(t_stack *a, t_stack *b, const char *op, int print)
{
	if (ft_strcmp(op, "ra") == 0)
	{
		rotate(a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rb") == 0)
	{
		rotate(b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rra") == 0)
	{
		reverse_rotate(a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "rrb") == 0)
	{
		reverse_rotate(b);
		print_op(op, print);
	}
	else
		do_op_sub_2(a, b, op, print);
}

void	do_op(t_stack *a, t_stack *b, const char *op, int print)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		push(a, b);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "pb") == 0)
	{
		push(b, a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "sa") == 0)
	{
		swap(a);
		print_op(op, print);
	}
	else if (ft_strcmp(op, "sb") == 0)
	{
		swap(b);
		print_op(op, print);
	}
	else
		do_op_sub_1(a, b, op, print);
}
