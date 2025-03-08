/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:30:56 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/08 22:35:12 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_free_instrucs(t_argus *argus)
{
	int	i;

	i = 0;
	if (argus->instructs)
	{
		while (argus->instructs[i])
		{
			free(argus->instructs[i]);
			argus->instructs[i] = NULL;
			i++;
		}
		free(argus->instructs);
		argus->instructs = NULL;
	}
}

void	ft_free_argus(t_argus *argus)
{
	int	i;

	i = 0;
	if (argus->argus)
	{
		while (argus->argus[i])
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
	ft_free_instrucs(argus);
}

void	s_convert(t_argus *argus)
{
	int	i;

	i = 0;
	while (argus->argus[i])
		i++;
	argus->a_len = i;
	argus->stack_a = (int *)malloc(sizeof(int) * i);
	argus->stack_b = (int *)malloc(sizeof(int) * i);
	if (!argus->stack_a || !argus->stack_b)
	{
		ft_putstr_fd("Failed to allocate\n", 2);
		ft_free_argus(argus);
		exit(1);
	}
	i = -1;
	while (argus->argus[++i])
		argus->stack_a[i] = ft_atoi(argus->argus[i], argus);
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
				return (ft_putstr_fd("Error\n", 2), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	start_sorting(t_argus *argus)
{
	if (argus->a_len == 2)
		two_sort(argus, argus->a_len);
	if (argus->a_len == 3)
		two_or_three_sort(argus, argus->a_len);
	if (argus->a_len <= 5)
		five_sort(argus, argus->a_len);
	else
		sorting_a(argus, argus->a_len);
}
