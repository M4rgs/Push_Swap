/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:41:47 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/08 22:41:48 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_valid_inst(t_argus *argus, char *p, char *tmp)
{
	if ((ft_strncmp(p, "rra\n", 4) && ft_strncmp(p, "ra\n", 3)
			&& ft_strncmp(p, "rrb\n", 4) && ft_strncmp(p, "rb\n", 3)
			&& ft_strncmp(p, "sa\n", 3) && ft_strncmp(p, "sb\n", 3)
			&& ft_strncmp(p, "pa\n", 3) && ft_strncmp(p, "pb\n", 3)
			&& ft_strncmp(p, "ss\n", 3) && ft_strncmp(p, "rr\n", 3)
			&& ft_strncmp(p, "rrr\n", 4)) || (!p || *p == '\n'))
	{
		ft_free_argus(argus);
		free(p);
		free(tmp);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

static void	get_instruct(t_argus *argus)
{
	char	*lines;
	char	*p;
	char	*tmp;

	p = NULL;
	tmp = NULL;
	while (1)
	{
		lines = get_next_line(0);
		if (!lines)
			break ;
		check_valid_inst(argus, lines, p);
		tmp = ft_strjoin(p, lines);
		p = tmp;
		free(lines);
	}
	argus->instructs = ft_split(argus, p, '\n');
	free(p);
}

static void	finish_execute(t_argus *argus, int i)
{
	if (!ft_strncmp(argus->instructs[i], "rr", 2))
		rr(argus);
	if (!ft_strncmp(argus->instructs[i], "sa", 2))
		sa(argus);
	else if (!ft_strncmp(argus->instructs[i], "sb", 2))
		sb(argus);
	else if (!ft_strncmp(argus->instructs[i], "ss", 2))
		ss(argus);
	else if (!ft_strncmp(argus->instructs[i], "pa", 2))
		pa(argus);
	else if (!ft_strncmp(argus->instructs[i], "pb", 2))
		pb(argus);
}

static void	execute_instruct(t_argus *argus)
{
	int	i;

	i = 0;
	if (!argus->instructs)
		return ;
	while (i < argus->howmany)
	{
		if (!ft_strncmp(argus->instructs[i], "rra", 3))
			rra(argus);
		else if (!ft_strncmp(argus->instructs[i], "rrb", 3))
			rrb(argus);
		else if (!ft_strncmp(argus->instructs[i], "rrr", 3))
			rrr(argus);
		else if (!ft_strncmp(argus->instructs[i], "ra", 2))
			ra(argus);
		else if (!ft_strncmp(argus->instructs[i], "rb", 2))
			rb(argus);
		else
			finish_execute(argus, i);
		i++;
	}
}

void	ft_checker(t_argus *argus)
{
	get_instruct(argus);
	execute_instruct(argus);
	if (is_sorted(argus->stack_a, argus->a_len) && argus->b_len == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_argus(argus);
	exit(0);
}
