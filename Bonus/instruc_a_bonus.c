/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:00 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 23:39:46 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_argus *argus)
{
	int	tmp;

	if (argus->a_len > 1)
	{
		tmp = argus->stack_a[0];
		argus->stack_a[0] = argus->stack_a[1];
		argus->stack_a[1] = tmp;
	}
}

void	ra(t_argus *argus)
{
	int	i;
	int	f;

	i = 0;
	f = argus->stack_a[0];
	while (i < argus->a_len - 1)
	{
		argus->stack_a[i] = argus->stack_a[i + 1];
		i++;
	}
	argus->stack_a[i] = f;
}

void	rra(t_argus *argus)
{
	int	i;
	int	l;

	if (argus->a_len > 1)
	{
		i = argus->a_len - 1;
		l = argus->stack_a[argus->a_len - 1];
		while (i > 0)
		{
			argus->stack_a[i] = argus->stack_a[i - 1];
			i--;
		}
		argus->stack_a[0] = l;
	}
}

void	pa(t_argus *argus)
{
	int	i;
	int	t;

	i = 0;
	if (argus->b_len != 0)
	{
		t = argus->stack_b[0];
		while (i < argus->b_len - 1)
		{
			argus->stack_b[i] = argus->stack_b[i + 1];
			i++;
		}
		i = argus->a_len;
		while (i > 0)
		{
			argus->stack_a[i] = argus->stack_a[i - 1];
			i--;
		}
		argus->stack_a[0] = t;
		argus->a_len += 1;
		argus->b_len -= 1;
	}
}
