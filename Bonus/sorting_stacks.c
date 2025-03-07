/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:17 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 20:40:56 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_reverse_sorted(int *stack, int s)
{
	int	i;

	i = 1;
	while (i < s)
	{
		if (stack[i - 1] < stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	push_push(t_argus *argus, int s)
{
	pa(argus);
	s--;
	return (s);
}

int	sorting_b(t_argus *argus, int s)
{
	int	len;
	int	c;

	c = 0;
	len = s;
	if (check_reverse_sorted(argus->stack_b, s))
	{
		while (s--)
			pa(argus);
	}
	if (s <= 3)
		return (sort_three_b(argus, s), 1);
	get_median(argus->stack_b, argus, s);
	while (s != len / 2)
	{
		if (argus->stack_b[0] >= argus->median && s--)
			pa(argus);
		else
			(rb(argus), c++);
	}
	while (len / 2 != argus->b_len && c--)
		rrb(argus);
	return (sorting_a(argus, (len / 2) + (len % 2))
		&& sorting_b(argus, len / 2));
}

int	sorting_a(t_argus *argus, int s)
{
	int	len;
	int	c;

	c = 0;
	len = s;
	if (is_sorted(argus->stack_a, s))
		return (1);
	if (s <= 3)
	{
		two_or_three_sort(argus, s);
		return (1);
	}
	get_median(argus->stack_a, argus, s);
	while (s != (len / 2) + len % 2)
	{
		if (argus->stack_a[0] < argus->median && s--)
			pb(argus);
		else
			(ra(argus), c++);
	}
	while (len / 2 + len % 2 != argus->a_len && c--)
		rra(argus);
	return (sorting_a(argus, (len / 2) + (len % 2))
		&& sorting_b(argus, len / 2));
}
