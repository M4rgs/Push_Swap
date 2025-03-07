/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:41:47 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 04:19:12 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_instruct(t_argus *argus)
{
	char	*lines;
	char	*p;

	p = NULL;
	lines = get_next_line(0);
	if (!lines)
	{
		ft_free_argus(argus);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (lines)
	{
		if (*lines == '\n')
		{
			ft_free_argus(argus);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		p = ft_strjoin(p, lines);
		free(lines);
		lines = get_next_line(0);
	}
	argus->instructs = ft_split(p, '\n');
}

int	ft_alebhh(char *p, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p[i] && s2[j])
	{
		if (p[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	execute_instructs(char *s, t_argus *argus)
{
	if (ft_alebhh(s, "sa"))
		sa(argus);
	else if (ft_alebhh(s, "ra"))
		ra(argus);
	else if (ft_alebhh(s, "rra"))
		rra(argus);
	else if (ft_alebhh(s, "pa"))
		pa(argus);
	else if (ft_alebhh(s, "sb"))
		sb(argus);
	else if (ft_alebhh(s, "rb"))
		rb(argus);
	else if (ft_alebhh(s, "rrb"))
		rrb(argus);
	else if (ft_alebhh(s, "pb"))
		pb(argus);
	else
	{
		ft_free_argus(argus);
		printf("Error\n");
		exit(1);
	}
}

void	ft_checker(t_argus *argus)
{
	int	i;

	i = 0;
	get_instruct(argus);
	while (argus->instructs[i])
	{
		execute_instructs(argus->instructs[i], argus);
		i++;
	}
	if (is_sorted(argus->stack_a, argus->a_len) && argus->b_len == 0)
	{
		printf("OK\n");
	}
	else
		printf("KO\n");
	ft_free_argus(argus);
}
