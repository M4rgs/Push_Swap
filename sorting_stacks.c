/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 04:45:01 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/05 04:52:24 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_a(t_argus *argus, int s)
{
	int	len;
	int	c;

	c = 0;
	len = s;
	if (is_sorted(argus, s))
		return ;
	if (s <= 3)
	{
		three_sort(argus);
		return ;
	}
	get_median(argus, s);
	while (s != (len / 2) + len % 2)
	{
		if (argus->stack_a[0] < argus->median && s--)
			pb(argus);
		else
			(ra(argus), c++);
	}
	while (len / 2 + len % 2 != argus->a_len && c--)
		rra(argus);
}
