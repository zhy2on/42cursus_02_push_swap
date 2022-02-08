/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:09:30 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 15:43:04 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	do_op_sub_2(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "ss") == 0)
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	else if (ft_strcmp(op, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
	}
}

void	do_op_sub_1(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if (ft_strcmp(op, "rb") == 0)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	else if (ft_strcmp(op, "rra") == 0)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	else if (ft_strcmp(op, "rrb") == 0)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

void	do_op(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "pa") == 0)
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
	else if (ft_strcmp(op, "pb") == 0)
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
	else if (ft_strcmp(op, "sa") == 0)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (ft_strcmp(op, "sb") == 0)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	do_op_sub_1(a, b, op);
	do_op_sub_2(a, b, op);
}
