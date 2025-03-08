/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:23 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/08 02:35:54 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	else if (s == 3 && argus->a_len == 3)
		three_sort(argus);
	else
	{
		while (s != 3 || !is_sorted(argus->stack_a, s))
		{
			if (s == 3 && argus->stack_a[0] > argus->stack_a[1])
				sa(argus);
			else if (s == 3 && !(argus->stack_a[2] > argus->stack_a[0]
					&& argus->stack_a[2] > argus->stack_a[1]))
				s = push_push_b(argus, s);
			else if (argus->stack_a[0] > argus->stack_a[1])
				sa(argus);
			else if (s++)
				pa(argus);
		}
	}
}

int	sort_three_b(t_argus *argus, int s)
{
	if (s == 1)
		pa(argus);
	else if (s == 2)
	{
		if (argus->stack_b[0] < argus->stack_b[1])
			sb(argus);
		while (s--)
			pa(argus);
	}
	else if (s == 3)
	{
		while (s != 0)
		{
			if (s == 1 && argus->stack_a[0] > argus->stack_a[1])
				sa(argus);
			else if (s == 1
				|| (s >= 2 && argus->stack_b[0] > argus->stack_b[1])
				|| (s == 3 && argus->stack_b[0] > argus->stack_b[2]))
				s = push_push_a(argus, s);
			else
				sb(argus);
		}
	}
	return (0);
}

void	five_sort(t_argus *argus, int s)
{
	int	j;
	int	i;

	j = s / 2;
	i = 0;
	if (is_sorted(argus->stack_a, s))
		return ;
	get_median(argus->stack_a, argus, s);
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
