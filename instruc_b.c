/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:37:33 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/03 22:56:50 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_putstr_fd("pb\n", 1);
		argus->b_len += 1;
		argus->a_len -= 1;
	}
}

void	sb(t_argus *argus)
{
	int	tmp;

	tmp = argus->stack_b[0];
	argus->stack_b[0] = argus->stack_b[1];
	argus->stack_b[1] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	rb(t_argus *argus)
{
	int	i;
	int	f;

	if (argus->b_len > 1)
	{
		i = 0;
		f = argus->stack_b[0];
		while (i < argus->b_len - 1)
		{
			argus->stack_b[i] = argus->stack_b[i + 1];
			i++;
		}
		argus->stack_b[argus->b_len - 1] = f;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rrb(t_argus *argus)
{
	int	i;
	int	l;

	if (argus->b_len > 1)
	{
		i = argus->b_len;
		l = argus->stack_b[argus->b_len - 1];
		while (i > 0)
		{
			argus->stack_b[i] = argus->stack_b[i - 1];
			i--;
		}
		argus->stack_b[0] = l;
		ft_putstr_fd("rrb\n", 1);
	}
}
