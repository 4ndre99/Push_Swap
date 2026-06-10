/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-arau <ade-arau@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:39:30 by marcooli          #+#    #+#             */
/*   Updated: 2026/06/10 15:36:40 by ade-arau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	str_len;
	char	*dup;

	str_len = 0;
	while (str[str_len])
		str_len++;
	dup = malloc(str_len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	subs_count(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			k++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (k);
}

int	fill(char **split, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			split[j] = ft_substr(s, start, i - start);
			if (!split[j])
				return (j);
			j++;
		}
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;

	if (!s)
		return (NULL);
	split = malloc((subs_count(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	j = fill(split, s, c);
	if (j >= 0)
	{
		j--;
		while (j >= 0)
			free(split[j--]);
		free(split);
		return (NULL);
	}
	return (split);
}
