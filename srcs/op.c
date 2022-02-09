/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:57:18 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 20:04:57 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *a, t_stack *b)
{
	if (!b->cnt)
		return ;
	if (add_node(a, remove_node(b)))
		handle_error();
}

void	swap(t_stack *a)
{
	int		tmp;

	if (a->cnt <= 1)
		return ;
	tmp = a->top->elem;
	a->top->elem = a->top->next->elem;
	a->top->next->elem = tmp;
}

void	rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return ;
	ptr = a->top;
	tmp = a->top->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = a->top;
	ptr->next->next = NULL;
	a->top = tmp;
}

void	reverse_rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return ;
	ptr = a->top;
	while (ptr->next)
	{
		if (ptr->next->next == NULL)
			tmp = ptr;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	ptr->next = a->top;
	a->top = ptr;
}
