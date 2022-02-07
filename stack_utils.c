/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:44 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/07 19:57:36 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*getnode(t_node *prev, t_node *next, int elem)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	ptr->elem = elem;
	ptr->next = next;
	return (ptr);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->max[0] = -2147483648;
	stack->min = 2147483647;
	stack->cnt = 0;
}

void	free_stack(t_stack *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = stack->top;
	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
}

void	add_first(t_stack *stack, int elem)
{
	t_node	*ptr;

	ptr = getnode(NULL, stack->top, elem);
	ptr->next = stack->top;
	stack->top = ptr;
	if (elem > stack->max[0])
		stack->max[0] = elem;
	if (elem < stack->min)
		stack->min = elem;
	stack->cnt++;
}
