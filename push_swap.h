/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:49:13 by taha              #+#    #+#             */
/*   Updated: 2025/02/16 23:27:51 by tamounir         ###   ########.fr       */
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
	int		*stack_a;
}	t_argus;

char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
void	s_convert(t_argus *argus);
int		s_check_repeat(t_argus *argus);
void	ft_free_argus(t_argus *argus);
char	*ft_strjoin(char *s1, char *s2);
void	start_sorting(t_argus *argus);
void	two_sort(t_argus *argus, int s);
void	sa(t_argus *argus);
void	ra(t_argus *argus);
void	rra(t_argus *argus);
#endif