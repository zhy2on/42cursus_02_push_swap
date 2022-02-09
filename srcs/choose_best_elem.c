/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:38:14 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 19:16:23 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_op_a(t_node *node, t_stack *a, t_op_cnt *op_cnt)
{
	t_node	*ptr;

	op_cnt->ra = 0;
	if (a->cnt == 0)
		return ;
	ptr = a->top;
	while (ptr && (ptr != node))
	{
		ptr = ptr->next;
		op_cnt->ra++;
	}
	op_cnt->rra = (a->cnt - op_cnt->ra) % a->cnt;
}

void	count_op_b(t_node *node, t_stack *b, t_op_cnt *op_cnt)
{
	t_node	*ptr;
	int		tmp;
	int		i;

	if (b->cnt == 0)
		return ;
	tmp = INTG_MIN;
	i = 0;
	ptr = b->top;
	while (ptr && ++i)
	{
		if (b->min < node->elem && ptr->elem >= tmp && ptr->elem < node->elem)
		{
			tmp = ptr->elem;
			op_cnt->rb = i - 1;
		}
		if (b->min > node->elem && ptr->elem >= tmp)
		{
			tmp = ptr->elem;
			op_cnt->rb = i - 1;
		}
		ptr = ptr->next;
	}
	op_cnt->rrb = (b->cnt - op_cnt->rb) % b->cnt;
}

void	choose_min_op(t_node *node, t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	rr;
	int	rrr;
	int	r_rr;

	op_cnt->ra = 0;
	op_cnt->rb = 0;
	op_cnt->rra = 0;
	op_cnt->rrb = 0;
	op_cnt->node = node;
	count_op_a(node, a, op_cnt);
	count_op_b(node, b, op_cnt);
	rr = ft_max(op_cnt->ra, op_cnt->rb);
	rrr = ft_max(op_cnt->rra, op_cnt->rrb);
	r_rr = ft_min(op_cnt->ra, op_cnt->rra) + ft_min(op_cnt->rb, op_cnt->rrb);
	op_cnt->min_cnt = ft_min(rr, rrr);
	op_cnt->min_cnt = ft_min(op_cnt->min_cnt, r_rr);
	if (op_cnt->min_cnt == rr)
		op_cnt->min_type = 1;
	else if (op_cnt->min_cnt == rrr)
		op_cnt->min_type = 2;
	else
		op_cnt->min_type = 3;
}

void	set_a_max(t_stack *a)
{
	t_node	*ptr;
	int		tmp;

	ptr = a->top;
	tmp = INTG_MIN;
	while (ptr)
	{
		if (ptr->elem < a->max[0] && ptr->elem >= tmp)
			tmp = ptr->elem;
		ptr = ptr->next;
	}
	a->max[1] = tmp;
	ptr = a->top;
	tmp = INTG_MIN;
	while (ptr)
	{
		if (ptr->elem < a->max[1] && ptr->elem >= tmp)
			tmp = ptr->elem;
		ptr = ptr->next;
	}
	a->max[2] = tmp;
}

void	choose_best_elem(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	t_node		*ptr;
	t_op_cnt	tmp;

	set_a_max(a);
	ptr = a->top;
	while (ptr->elem == a->max[0] || ptr->elem == a->max[1]
		|| ptr->elem == a->max[2])
		ptr = ptr->next;
	choose_min_op(ptr, a, b, op_cnt);
	ptr = a->top;
	while (ptr)
	{
		choose_min_op(ptr, a, b, &tmp);
		if (tmp.min_cnt < op_cnt->min_cnt && ptr->elem != a->max[0]
			&& ptr->elem != a->max[1] && ptr->elem != a->max[2])
			*op_cnt = tmp;
		ptr = ptr->next;
	}
}
