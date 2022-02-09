/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:42:51 by jihoh             #+#    #+#             */
/*   Updated: 2022/02/09 02:29:24 by jihoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_values_sub(t_stack *a, const char *str, int sign)
{
	long long	num;
	t_node		*ptr;

	if (*str < '0' || *str > '9')
		handle_error();
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str++ - '0');
		if (sign * num < INT_MIN || sign * num > INT_MAX)
			handle_error();
	}
	ptr = a->top;
	while (ptr)
	{
		if (ptr->elem == sign * num)
			handle_error();
		ptr = ptr->next;
	}
	if (add_node(a, sign * num))
		handle_error();
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
