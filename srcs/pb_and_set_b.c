/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_and_set_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:47:01 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 19:16:41 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_do_op(t_stack *a, t_stack *b, int n, const char *op)
{
	int	i;

	i = -1;
	while (++i < n)
		do_op(a, b, op);
	return (i);
}

void	set_b_max_on_top(t_stack *a, t_stack *b)
{
	int		i;
	int		idx;
	int		tmp;
	t_node	*ptr;

	i = 0;
	tmp = INTG_MIN;
	ptr = b->top;
	while (ptr)
	{
		if (ptr->elem >= tmp)
		{
			tmp = ptr->elem;
			idx = i;
		}
		i++;
		ptr = ptr->next;
	}
	if (idx < (b->cnt - idx) % b->cnt)
		loop_do_op(a, b, idx, "rb");
	else
		loop_do_op(a, b, (b->cnt - idx) % b->cnt, "rrb");
}

void	pb_best_elem_sub(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	if (op_cnt->ra < op_cnt->rra)
		loop_do_op(a, b, op_cnt->ra, "ra");
	else
		loop_do_op(a, b, op_cnt->rra, "rra");
	if (op_cnt->rb < op_cnt->rrb)
		loop_do_op(a, b, op_cnt->rb, "rb");
	else
		loop_do_op(a, b, op_cnt->rrb, "rrb");
}

void	pb_best_elem(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	i;

	if (op_cnt->min_type == 1)
	{
		i = loop_do_op(a, b, ft_min(op_cnt->ra, op_cnt->rb), "rr");
		if (op_cnt->ra > op_cnt->rb)
			loop_do_op(a, b, op_cnt->ra - i, "ra");
		else
			loop_do_op(a, b, op_cnt->rb - i, "rb");
	}
	else if (op_cnt->min_type == 2)
	{
		i = loop_do_op(a, b, ft_min(op_cnt->rra, op_cnt->rrb), "rrr");
		if (op_cnt->rra > op_cnt->rrb)
			loop_do_op(a, b, op_cnt->rra - i, "rra");
		else
			loop_do_op(a, b, op_cnt->rrb - i, "rrb");
	}
	else
		pb_best_elem_sub(a, b, op_cnt);
	do_op(a, b, "pb");
}
