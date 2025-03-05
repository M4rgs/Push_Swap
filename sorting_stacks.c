/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:45:01 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/05 22:33:26 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_b(t_argus *argus, int s)
{
	int	len;
	int	c;

	c = 0;
	len = s;
	if (is_sorted_b(argus, s))
		return (1);
	get_median(argus->stack_b, argus, s);
	while (s != (len / 2) + len % 2)
	{
		if (argus->stack_b[0] < argus->median && s--)
			pa(argus);
		else
			(rb(argus), c++);
	}
}
int	sorting_a(t_argus *argus, int s)
{
	int	len;
	int	c;

	c = 0;
	len = s;
	if (is_sorted(argus, s))
		return (1);
	if (s <= 3)
	{
		three_sort(argus);
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
	return (sorting_a(argus, (len / 2) + (len % 2)) && sorting_a(argus, len / 2));
}
