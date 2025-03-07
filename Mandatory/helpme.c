/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 01:34:19 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/05 23:23:44 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *arr, int s)
{
	int	i;

	i = 1;
	while (i < s)
	{
		if (arr[i - 1] > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	push(t_argus *argus, int s, int fl)
{
	if (fl == 1)
		pb(argus);
	s -= 1;
	return (s);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	get_median(int *stick, t_argus *argus, int s)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * s);
	if (!tmp)
	{
		ft_free_argus(argus);
		free(tmp);
		return (0);
	}
	i = 0;
	j = 0;
	while (i < s)
		tmp[j++] = stick[i++];
	bubble_sort(tmp, s);
	argus->median = tmp[s / 2];
	free(tmp);
	return (1);
}
