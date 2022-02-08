/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:57:18 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 02:29:36 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *a, t_stack *b)
{
	if (!b->cnt)
		return (1);
	if (add_node(a, remove_node(b)))
		handle_error();
	return (0);
}

int	swap(t_stack *a)
{
	int		tmp;

	if (a->cnt <= 1)
		return (1);
	tmp = a->top->elem;
	a->top->elem = a->top->next->elem;
	a->top->next->elem = tmp;
	return (0);
}

int	rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return (1);
	ptr = a->top;
	tmp = a->top->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = a->top;
	ptr->next->next = NULL;
	a->top = tmp;
	return (0);
}

int	reverse_rotate(t_stack *a)
{
	t_node	*ptr;
	t_node	*tmp;

	if (a->cnt <= 1)
		return (1);
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
	return (0);
}
