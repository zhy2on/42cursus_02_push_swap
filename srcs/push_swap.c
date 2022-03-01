/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:47:27 by jihoh             #+#    #+#             */
/*   Updated: 2022/03/01 20:49:12 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_op_cnt	op_cnt;

	if (is_sorted(a))
		return ;
	if (a->cnt <= 3)
	{
		simple_sort(a, b);
		return ;
	}
	while (a->cnt > 3)
	{
		choose_best_elem(a, b, &op_cnt);
		pb_best_elem(a, b, &op_cnt);
	}
	set_b_max_on_top(a, b);
	sort_3(a, b);
	while (b->top)
		do_op(a, b, "pa", 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_node	*ptr;
	int		i;

	init_stack(&a);
	init_stack(&b);
	i = 0;
	while (++i < argc)
	{
		if (!*argv[i])
			handle_error();
		while (*argv[i])
			argv[i] = get_values(&a, argv[i]);
	}
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
