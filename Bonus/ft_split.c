/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:30:36 by tamounir          #+#    #+#             */
/*   Updated: 2025/03/07 20:39:57 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			result++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (result);
}

static char	*allo_words(const char *s, char c)
{
	size_t	len;
	char	*result;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		result[len] = s[len];
		len++;
	}
	result[len] = '\0';
	return (result);
}

static char	**ft_free(char **words, size_t index)
{
	size_t	i;

	i = 0;
	while (index > i)
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char	**ft_split(t_argus *argus, const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	argus->howmany = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (argus->howmany + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < argus->howmany)
	{
		while (s[i] && s[i] == c)
			i++;
		result[j] = allo_words(&s[i], c);
		if (!result[j])
			return (ft_free(result, j));
		while (s[i] && s[i] != c)
			i++;
	}
	result[argus->howmany] = NULL;
	return (result);
}
