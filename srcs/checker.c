/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:38:03 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 19:16:17 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*ptr;

	if (!a->top)
		return (0);
	ptr = a->top;
	while (ptr->next)
	{
		if (ptr->elem > ptr->next->elem)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	handle_op(t_stack *a, t_stack *b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!do_op(a, b, (const char *)line))
		{
			free(line);
			get_next_line(-1, &line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

void	checker(t_stack *a, t_stack *b)
{
	if (!handle_op(a, b))
		handle_error();
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
