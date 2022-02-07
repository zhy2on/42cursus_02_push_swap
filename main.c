/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:47:27 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/07 19:58:56 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(int flag, t_stack *stack)
{
	if (flag == 2)
		free_stack(stack);
	write(2, "parameter error\n", 16);
	exit(1);
}

char	*get_values_sub(t_stack *a, const char *str, int sign)
{
	long long	num;
	t_node		*ptr;

	if (*str < '0' || *str > '9')
		handle_error(2, a);
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
		if (sign * num < -2147483648 || sign * num > 2147483647)
			handle_error(2, a);
	}
	ptr = a->top;
	while (ptr)
	{
		if (ptr->elem == sign * num)
			handle_error(2, a);
		ptr = ptr->next;
	}
	add_first(a, sign * num);
	return ((char *)str);
}

char	*get_values(t_stack *a, const char *str)
{
	int				sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		sign = -sign;
	}
	if (!*str)
		return ((char *)str);
	return (get_values_sub(a, str, sign));
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
	//print_stack(&a);
	//print_stack(&b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
