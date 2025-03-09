/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:04 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 23:39:53 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_argus *argus)
{
	int	tmp;

	if (argus->b_len > 1)
	{
		tmp = argus->stack_b[0];
		argus->stack_b[0] = argus->stack_b[1];
		argus->stack_b[1] = tmp;
	}
}

void	rb(t_argus *argus)
{
	int	i;
	int	f;

	i = 0;
	f = argus->stack_b[0];
	while (i < argus->b_len - 1)
	{
		argus->stack_b[i] = argus->stack_b[i + 1];
		i++;
	}
	argus->stack_b[i] = f;
}

void	rrb(t_argus *argus)
{
	int	i;
	int	l;

	if (argus->b_len > 0)
	{
		i = argus->b_len - 1;
		l = argus->stack_b[argus->b_len - 1];
		while (i > 0)
		{
			argus->stack_b[i] = argus->stack_b[i - 1];
			i--;
		}
		argus->stack_b[0] = l;
	}
}

void	pb(t_argus *argus)
{
	int	i;
	int	t;

	i = 0;
	if (argus->a_len != 0)
	{
		t = argus->stack_a[0];
		while (i < argus->a_len - 1)
		{
			argus->stack_a[i] = argus->stack_a[i + 1];
			i++;
		}
		i = argus->b_len;
		while (i > 0)
		{
			argus->stack_b[i] = argus->stack_b[i - 1];
			i--;
		}
		argus->stack_b[0] = t;
		argus->b_len += 1;
		argus->a_len -= 1;
	}
}
