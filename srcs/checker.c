/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:38:03 by jihoh             #+#    #+#             */
/*   Updated: 2022/03/03 17:14:31 by jihoh            ###   ########.fr       */
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
	free(line);
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
	i = 0;
	while (++i < argc)
	{
		if (!*argv[i])
			handle_error();
		while (*argv[i])
			argv[i] = get_values(&a, argv[i]);
	}
	checker(&a, &b);
	return (0);
}
