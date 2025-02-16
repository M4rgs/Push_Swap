/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:46:47 by tamounir          #+#    #+#             */
/*   Updated: 2025/02/16 05:07:21 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sa(t_argus *argus)
{
	int	tmp;

	tmp = argus->stack_a[0];
	argus->stack_a[0] = argus->stack_a[1];
	argus->stack_a[1] = tmp;
	printf("first : %d\nsecond : %d", argus->stack_a[0], argus->stack_a[1]);
}
