/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:31:12 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/09 00:17:47 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_argus
{
	int		a_len;
	int		b_len;
	char	**argus;
	char	*s;
	int		median;
	int		howmany;
	int		*stack_a;
	int		*stack_b;
	char	**instructs;
}	t_argus;

char	**ft_split(t_argus *argus, const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *s, t_argus *argus);
void	s_convert(t_argus *argus);
int		s_check_repeat(t_argus *argus);
void	ft_free_argus(t_argus *argus);
char	*ft_strjoin(char *s1, char *s2);
int		is_sorted(int *arr, int s);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	sa(t_argus *argus);
void	ra(t_argus *argus);
void	rra(t_argus *argus);
void	pa(t_argus *argus);
void	sb(t_argus *argus);
void	rb(t_argus *argus);
void	rrb(t_argus *argus);
void	pb(t_argus *argus);
void	rr(t_argus *argus);
void	rrr(t_argus *argus);
void	ss(t_argus *argus);
void	ft_checker(t_argus *argus);
#endif