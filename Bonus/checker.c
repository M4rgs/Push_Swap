/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:41:47 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/08 04:25:23 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_ok(t_argus *argus)
{
	if (is_sorted(argus->stack_a, argus->a_len) && argus->b_len == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free_argus(argus);
	exit(0);
}

static void	check_valid_inst(char *line, t_argus *argus)
{
	if (!line || *line == '\n')
	{
		free(line);
		ft_free_argus(argus);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_strncmp(line, "rra\n", 4) && ft_strncmp(line, "ra\n", 3)
		&& ft_strncmp(line, "rrb\n", 4) && ft_strncmp(line, "rb\n", 3)
		&& ft_strncmp(line, "sa\n", 3) && ft_strncmp(line, "sb\n", 3)
		&& ft_strncmp(line, "pa\n", 3) && ft_strncmp(line, "pb\n", 3)
		&& ft_strncmp(line, "ss\n", 3) && ft_strncmp(line, "rr\n", 3)
		&& ft_strncmp(line, "rrr\n", 4))
	{
		free(line);
		ft_free_argus(argus);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

static void	finish_execute(t_argus *argus, char *line)
{
	if (!ft_strncmp(line, "rr", 2))
		rr(argus);
	if (!ft_strncmp(line, "sa", 2))
		sa(argus);
	else if (!ft_strncmp(line, "sb", 2))
		sb(argus);
	else if (!ft_strncmp(line, "ss", 2))
		ss(argus);
	else if (!ft_strncmp(line, "pa", 2))
		pa(argus);
	else if (!ft_strncmp(line, "pb", 2))
		pb(argus);
	else
	{
		free(line);
		ft_free_argus(argus);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

static void	execute_instruction(t_argus *argus, char *line)
{
	if (!ft_strncmp(line, "rra", 3))
		rra(argus);
	else if (!ft_strncmp(line, "rrb", 3))
		rrb(argus);
	else if (!ft_strncmp(line, "rrr", 3))
		rrr(argus);
	else if (!ft_strncmp(line, "ra", 2))
		ra(argus);
	else if (!ft_strncmp(line, "rb", 2))
		rb(argus);
	else
		finish_execute(argus, line);
}

void	ft_checker(t_argus *argus)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		check_valid_inst(line, argus);
		execute_instruction(argus, line);
		free(line);
	}
	is_ok(argus);
}
