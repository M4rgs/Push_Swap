/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:49:13 by taha              #+#    #+#             */
/*   Updated: 2025/02/09 00:28:28 by taha             ###   ########.fr       */
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
	char	*argus;
	char	*s;
}	t_argus;

char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);
#endif