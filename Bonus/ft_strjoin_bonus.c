/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 03:03:00 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 20:39:59 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

static int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlenn(src));
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlenn(src));
}

static int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	i;
	int	destlen;
	int	srclen;
	int	ff;

	srclen = ft_strlenn(src);
	if (dst == NULL && dstsize == 0)
		return (srclen);
	destlen = ft_strlenn(dst);
	ff = destlen;
	if (dstsize <= destlen)
		return (srclen + dstsize);
	i = 0;
	while (i + 1 + destlen < dstsize && src[i])
	{
		dst[ff] = src[i];
		i++;
		ff++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		lent;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	lent = ft_strlenn(s1) + ft_strlenn(s2) + 1;
	p = malloc(lent);
	if (!p)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(p, s1, lent);
	ft_strlcat(p, s2, lent);
	free(s1);
	return (p);
}
