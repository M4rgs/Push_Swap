/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:49:13 by taha              #+#    #+#             */
/*   Updated: 2025/02/17 05:50:29 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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
int		ft_atoi(char *str);
void	s_convert(t_argus *argus);
int		s_check_repeat(t_argus *argus);
void	ft_free_argus(t_argus *argus);
char	*ft_strjoin(char *s1, char *s2);
void	start_sorting(t_argus *argus);
int		is_sorted(t_argus *argus, int s);
int		push(t_argus *argus, int s, int fl);
void	two_sort(t_argus *argus, int s);
void	two_or_three_sort(t_argus *argus, int s);
void	five_sort(t_argus *argus, int s);
int		get_median(t_argus *argus, int s);
void	sa(t_argus *argus);
void	ra(t_argus *argus);
void	rra(t_argus *argus);
void	pa(t_argus *argus);
void	sb(t_argus *argus);
void	rb(t_argus *argus);
void	rrb(t_argus *argus);
void	pb(t_argus *argus);
#endif