/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:34:19 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/17 01:42:44 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_argus *argus, int s)
{
	int	i;

	i = 1;
	while (i < s)
	{
		if (argus->stack_a[i - 1] > argus->stack_a[i])
			return (0);
		i++;
	}
	return (1);
}
