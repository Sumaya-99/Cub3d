/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:44:33 by suhelal           #+#    #+#             */
/*   Updated: 2024/09/27 11:52:29 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_words(char const *s, char c)
{
	int	counter;
	int	a;
	int	still_word;

	a = 0;
	counter = 0;
	while (s[a])
	{
		still_word = 0;
		while (s[a] == c)
			a++;
		while (s[a] != c && s[a])
		{
			if (still_word == 0)
			{
				counter++;
				still_word = 1;
			}
			a++;
		}
	}
	return (counter);
}

void	ft_free_word(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free (spl[i]);
		i++;
	}
	free (spl);
}

char	*get_word(char const *s, char c)
{
	int	a;

	a = 0;
	while (s[a] != c && s[a])
		a++;
	return (ft_substr(s, 0, a));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		a;
	int		b;
	int		size;

	if (!s)
		return (NULL);
	a = 0;
	b = 0;
	size = count_words(s, c) + 1;
	str = malloc(sizeof(char *) * size);
	if (!str)
		return (NULL);
	while (s[a] && b < size - 1)
	{
		while (s[a] && s[a] == c)
			a++;
		str[b++] = get_word((s + a), c);
		if (!str[b - 1])
			return (ft_free_word(str), NULL);
		while (s[a] && s[a] != c)
			a++;
	}
	str[b] = NULL;
	return (str);
}
