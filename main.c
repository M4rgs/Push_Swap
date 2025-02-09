/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:50:08 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 00:30:39 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_args_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_argus	argus;
	int		i;

	i = 0;
	if (ac >= 2)
	{
		while (av[i])
		{
			if (av[i][1] == '\0')
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			is_args_valid(av[i]);
			argus.s = ft_strjoin(argus.s, av[i]);
			argus.s = ft_strjoin(argus.s, " ");
			if (!argus.s)
				return (ft_putstr_fd("Error\n", 2), free(argus.s), 1);
			i++;
		}
		argus.argus = ft_split(argus.s, " ");
		if (!argus.argus)
			return (ft_putstr_fd("Error\n", 2), free(argus.argus), 1);
		init(&argus);
	}
}
