/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:05:54 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 15:38:25 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*ptr;

	ptr = stack->top;
	while (ptr)
	{
		printf("%d ", ptr->elem);
		ptr = ptr->next;
	}
	printf("\n");
	//printf("max, min, cnt: %d %d %d\n", stack->max[0], stack->min, stack->cnt);
}

void	monitor_stack(t_stack *a, t_stack *b)
{
	t_node	*pa;
	t_node	*pb;

	pa = a->top;
	pb = b->top;
	while (pa || pb)
	{
		if (pa)
		{
			printf("%d", pa->elem);
			pa = pa->next;
		}
		printf(" : ");
		if (pb)
		{
			printf("%d", pb->elem);
			pb = pb->next;
		}
		printf("\n");
	}
}
