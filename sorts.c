/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:49:24 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/05 02:19:56 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_argus *argus, int s)
{
	if (s == 2)
	{
		if (argus->stack_a[0] > argus->stack_a[1])
			sa(argus);
	}
	else
		return ;
}

void	three_sort(t_argus *argus)
{
	if (argus->stack_a[0] > argus->stack_a[1]
		&& argus->stack_a[0] < argus->stack_a[2])
		sa(argus);
	else if (argus->stack_a[0] > argus->stack_a[1]
		&& argus->stack_a[0] > argus->stack_a[2])
	{
		if (argus->stack_a[0] > argus->stack_a[1]
			&& argus->stack_a[1] > argus->stack_a[2])
		{
			sa(argus);
			rra(argus);
		}
		else if (argus->stack_a[0] > argus->stack_a[1]
			&& argus->stack_a[1] < argus->stack_a[2])
			ra(argus);
	}
	else if (argus->stack_a[0] < argus->stack_a[1]
		&& argus->stack_a[0] < argus->stack_a[2])
	{
		if (argus->stack_a[1] > argus->stack_a[2])
			(rra(argus), sa(argus));
	}
	else if (argus->stack_a[0] < argus->stack_a[1]
		&& argus->stack_a[0] > argus->stack_a[2])
		rra(argus);
}

void	two_or_three_sort(t_argus *argus, int s)
{
	if (s == 2)
		two_sort(argus, s);
	else if (s == 3)
		three_sort(argus);
	else
	{
		while (s != 3 || !is_sorted(argus, s))
		{
			if (s == 3 && argus->stack_a[0] > argus->stack_a[1])
				sa(argus);
			else if (s == 3 && !(argus->stack_a[2] > argus->stack_a[0]
					&& argus->stack_a[2] > argus->stack_a[1]))
				s = push(argus, s, 1);
			else if (argus->stack_a[0] > argus->stack_a[1])
				sa(argus);
			else if (s++)
				pa(argus);
		}
	}
}

void	five_sort(t_argus *argus, int s)
{
	int	j;
	int	i;

	j = s / 2;
	i = 0;
	if (is_sorted(argus, s))
		return ;
	get_median(argus, s);
	while (j != 0)
	{
		if (argus->stack_a[0] < argus->median && j--)
		{
			if (i == 2)
				break ;
			if (argus->stack_a[0] < argus->stack_b[0] && argus->b_len != 0)
				(pb(argus), sb(argus));
			else
				pb(argus);
			i++;
		}
		else
			ra(argus);
	}
	(two_or_three_sort(argus, argus->a_len), pa(argus), pa(argus));
}
