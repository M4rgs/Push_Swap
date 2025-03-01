/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:21:05 by taha              #+#    #+#             */
/*   Updated: 2025/02/22 21:34:00 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}


int	ft_atoi(char *s, t_argus *argus)
{
	int		i;
	int		signe;
	long	resu;

	i = 0;
	signe = 1;
	resu = 0;
	while (s[i] == 32)
		i++;
	if ((s[i] == '-' || s[i] == '+') && s[i + 1] != '\0')
	{
		if (s[i] == '-')
			signe *= -1;
		i++;
	}
	while (s[i])
	{
		resu = resu * 10 + (s[i] - 48);
		if ((resu * signe > 2147483647 || resu * signe < -2147483648) || (s[i] < '0' || s[i] > '9'))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_argus(argus);
			exit(1);
		}
		i++;
	}
	return (resu * signe);
}
/*int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		sign = 44 - str[i++];
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign > 2147483647 || result * sign < -2147483648)
			|| (str[i] < '0' || str[i] > '9'))
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
		i++;
	}
	return ((result * sign));
}*/
