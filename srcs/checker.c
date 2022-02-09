/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:38:03 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 20:30:33 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		do_op(a, b, (const char *)line, 0);
		free(line);
	}
	if (is_sorted(a) && !b->top)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		handle_error();
	i = argc;
	while (--i >= 1)
		while (*argv[i])
			argv[i] = get_values(&a, argv[i]);
	checker(&a, &b);
	return (0);
}
