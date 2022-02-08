/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:59:44 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 17:35:11 by jihoh            ###   ########.fr       */
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
	stack->max[0] = INT_MIN;
	stack->min = INT_MAX;
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

int	add_node(t_stack *stack, int elem)
{
	t_node	*ptr;

	ptr = getnode(NULL, stack->top, elem);
	if (!ptr)
		handle_error(2, stack);
	ptr->next = stack->top;
	stack->top = ptr;
	if (elem > stack->max[0])
		stack->max[0] = elem;
	if (elem < stack->min)
		stack->min = elem;
	stack->cnt++;
	return (1);
}

int	remove_node(t_stack *stack)
{
	int		ret;
	int		tmp;
	t_node	*ptr;

	ptr = stack->top;
	ret = ptr->elem;
	stack->top = stack->top->next;
	free(ptr);
	stack->cnt--;
	set_stack_min_max(stack);
	return (ret);
}
