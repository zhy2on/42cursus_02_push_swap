/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:47:27 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/08 15:32:47 by jihoh            ###   ########.fr       */
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
	simple_sort(&a, &b);
	print_stack(&a);
	//print_stack(&b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
