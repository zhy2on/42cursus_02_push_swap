/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:06:19 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 19:29:38 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->top->elem;
	second = a->top->next->elem;
	third = a->top->next->next->elem;
	if (first > second && second > third && first > third)
	{
		do_op(a, b, "sa");
		do_op(a, b, "rra");
	}
	else if (first < second && second > third && first < third)
	{
		do_op(a, b, "rra");
		do_op(a, b, "sa");
	}
	else if (first > second && second < third && first < third)
		do_op(a, b, "sa");
	else if (first < second && second > third && first > third)
		do_op(a, b, "rra");
	else if (first > second && second < third && first > third)
		do_op(a, b, "ra");
}

void	sort_2(t_stack *a, t_stack *b)
{
	if (a->top->elem > a->top->next->elem)
		do_op(a, b, "sa");
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->cnt == 3)
		sort_3(a, b);
	else if (a->cnt == 2)
		sort_2(a, b);
	else
		return ;
}
