/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:12 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/08 02:38:16 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_argus
{
	int		a_len;
	int		b_len;
	char	**argus;
	char	*s;
	int		median;
	int		*stack_a;
	int		*stack_b;
}	t_argus;

char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *s, t_argus *argus);
void	s_convert(t_argus *argus);
int		s_check_repeat(t_argus *argus);
void	ft_free_argus(t_argus *argus);
char	*ft_strjoin(char *s1, char *s2);
void	start_sorting(t_argus *argus);
int		is_sorted(int *arr, int s);
int		get_median(int *stick, t_argus *argus, int s);
void	two_sort(t_argus *argus, int s);
void	three_sort(t_argus *argus);
void	two_or_three_sort(t_argus *argus, int s);
int		sort_three_b(t_argus *argus, int s);
void	five_sort(t_argus *argus, int s);
int		sorting_a(t_argus *argus, int s);
int		sorting_b(t_argus *argus, int s);
void	sa(t_argus *argus);
void	ra(t_argus *argus);
void	rra(t_argus *argus);
void	pa(t_argus *argus);
void	sb(t_argus *argus);
void	rb(t_argus *argus);
void	rrb(t_argus *argus);
void	pb(t_argus *argus);
int		push_push_b(t_argus *argus, int s);
int		push_push_a(t_argus *argus, int s);
#endif