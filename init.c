/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:31:33 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 03:36:07 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argus(t_argus *argus)
{
	int	i;

	i = 0;
	if (argus->argus)
	{
		while (i < argus->a_len && argus->argus[i])
		{
			(free(argus->argus[i]), argus->argus[i] = NULL);
			i++;
		}
		free(argus->argus);
		argus->argus = NULL;
	}
	if (argus->stack_b)
		(free(argus->stack_b), argus->stack_b = NULL);
	if (argus->stack_a)
		(free(argus->stack_a), argus->stack_a = NULL);
	if (argus->s)
		(free(argus->s), argus->s = NULL);
}

void	s_convert(t_argus *argus)
{
	int	i;

	i = 0;
	while (argus->argus[i])
		i++;
	argus->a_len = i;
	argus->b_len = i;
	argus->stack_a = (int *)malloc(sizeof(int) * i);
	argus->stack_b = (int *)malloc(sizeof(int) * i);
	if (!argus->stack_a || !argus->stack_b)
	{
		ft_putstr_fd("Failed to allocate\n", 2);
		ft_free_argus(argus);
		exit(1);
	}
	i = 0;
	while (argus->argus[i])
	{
		argus->stack_a[i] = ft_atoi(argus->argus[i]);
		i++;
	}
}

int	s_check_repeat(t_argus *argus)
{
	int	i;
	int	j;

	i = 0;
	while (i < argus->a_len)
	{
		j = i + 1;
		while (j < argus->a_len)
		{
			if (argus->stack_a[i] == argus->stack_a[j])
			{
				ft_free_argus(argus);
				return (ft_putstr_fd("Error\n", 1), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	start_sorting(t_argus *argus)
{
	if (argus->a_len <= 2)
		two_sort(argus, argus->a_len);
	if (argus->a_len <= 3)
		two_or_three_sort(argus, argus->a_len);
	if (argus->a_len <= 5)
		five_sort(argus, argus->a_len);
}
