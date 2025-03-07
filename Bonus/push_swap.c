/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:08 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 20:40:26 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_strct(t_argus *argus)
{
	argus->a_len = 0;
	argus->b_len = 0;
	argus->argus = NULL;
	argus->s = NULL;
	argus->instructs = NULL;
	argus->stack_a = NULL;
	argus->stack_b = NULL;
	argus->median = 0;
}

static void	check_args_and_ini_argus(char *str, t_argus *argus)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	temp = ft_strjoin(argus->s, str);
	argus->s = temp;
	temp = ft_strjoin(argus->s, " ");
	argus->s = temp;
	if (!argus->s)
	{
		ft_free_argus(argus);
		ft_putstr_fd("Error\n", 2);
	}
}

static void	init(t_argus *argus)
{
	s_convert(argus);
	if (s_check_repeat(argus) == 1)
		exit(1);
}

int	main(int ac, char **av)
{
	t_argus	argus;
	int		i;

	i = 1;
	if (ac >= 2)
	{
		init_strct(&argus);
		while (av[i])
		{
			if (av[i][0] == '\0')
			{
				ft_putstr_fd("Error\n", 2);
				ft_free_argus(&argus);
				exit(1);
			}
			check_args_and_ini_argus(av[i], &argus);
			i++;
		}
		argus.argus = ft_split(&argus, argus.s, ' ');
		if (!argus.argus)
			return (ft_putstr_fd("Error\n", 2), ft_free_argus(&argus), 1);
		init(&argus);
		ft_checker(&argus);
	}
}
