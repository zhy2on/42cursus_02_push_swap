/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:47:01 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 18:00:58 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_op_cnt(t_op_cnt *op_cnt)
{
	op_cnt->ra = 0;
	op_cnt->rb = 0;
	op_cnt->rra = 0;
	op_cnt->rrb = 0;
	op_cnt->min_cnt = 0;
}

void	set_a_max(t_stack *a)
{
	t_node	*ptr;
	int		tmp;

	ptr = a->top;
	tmp = INT_MIN;
	while (ptr)
		if (ptr->elem < a->max[0] && ptr->elem >= tmp)
			tmp = ptr->elem;
	a->max[1] = tmp;
	ptr = a->top;
	tmp = INT_MIN;
	while (ptr)
		if (ptr->elem < a->max[1] && ptr->elem >= tmp)
			tmp = ptr->elem;
	a->max[2] = tmp;
}

t_op_cnt	choose_best_elem(t_stack *a, t_stack *b)
{
	t_node		*ptr;
	t_op_cnt	op_cnt;

	set_a_max(a);
	ptr = a->top;
	while (ptr->elem == a->max[0] || ptr->elem == a->max[1]
		|| ptr->elem == a->max[2])
		ptr = ptr->next;
}

void	stack_sort(t_stack *a, t_stack *b)
{
	t_op_cnt	op_cnt;

}
