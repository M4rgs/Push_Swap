/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 02:37:33 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/17 02:39:32 by tamounir         ###   ########.fr       */
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
