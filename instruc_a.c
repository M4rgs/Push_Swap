/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:46:47 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/16 23:28:05 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_argus *argus)
{
	int	tmp;

	tmp = argus->stack_a[0];
	argus->stack_a[0] = argus->stack_a[1];
	argus->stack_a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	rra(t_argus *argus)
{
	int	i;
	int	l;

	if (argus->a_len > 1)
	{
		i = argus->a_len;
		l = argus->stack_a[argus->a_len - 1];
		while (i > 0)
		{
			argus->stack_a[i] = argus->stack_a[i - 1];
			i--;
		}
		argus->stack_a[0] = l;
		ft_putstr_fd("rra\n", 1);
	}
}

void	ra(t_argus *argus)
{
	int	i;
	int	f;

	if (argus->a_len > 1)
	{
		i = 0;
		f = argus->stack_a[0];
		while (i < argus->a_len - 1)
		{
			argus->stack_a[i] = argus->stack_a[i + 1];
			i++;
		}
		argus->stack_a[argus->a_len - 1] = f;
		ft_putstr_fd("ra\n", 1);
	}
}
