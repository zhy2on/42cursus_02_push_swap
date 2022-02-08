/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_min_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:00:15 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 18:06:54 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int n, int m)
{
	if (n < m)
		return (n);
	else
		return (m);
}

int	ft_max(int n, int m)
{
	if (n > m)
		return (n);
	else
		return (m);
}

void	count_op_a(t_node *node, t_stack *a, t_op_cnt *op_cnt)
{
	t_node	*ptr;

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
	int		cnt;
	int		i;

	if (b->cnt == 0)
		return ;
	tmp = INT_MIN;
	op_cnt->rb = -1;
	i = 0;
	ptr = b->top;
	while (ptr && ++i)
	{
		if (ptr->elem >= tmp)
		{
			tmp = ptr->elem;
			cnt = i - 1;
			if (ptr->elem < node->elem)
				op_cnt->rb = cnt;
		}
		ptr = ptr->next;
	}
	if (op_cnt->rb == -1)
		op_cnt->rb = cnt;
	op_cnt->rrb = (b->cnt - op_cnt->rb) % b->cnt;
}

void	choose_min_op(t_node *node, t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	rr;
	int	rrr;
	int	r_rr;

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
