/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:47:27 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 19:48:32 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(int flag, t_stack *stack)
{	
	free_stack(stack);
	if (flag == 1)
		write(2, "parameter error\n", 16);
	else if (flag == 2)
		write(2, "malloc error\n", 13);
	exit(1);
}

void	stack_sort(t_stack *a, t_stack *b)
{
	t_op_cnt	op_cnt;

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
		do_op(a, b, "pa");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		handle_error(1, NULL);
	i = argc;
	while (--i >= 1)
		while (*argv[i])
			argv[i] = get_values(&a, argv[i]);
	stack_sort(&a, &b);
	print_stack(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
