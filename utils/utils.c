/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:48:39 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 17:14:42 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	n;

	n = 0;
	while ((s1[n] != '\0' || s2[n] != '\0') && s1[n] == s2[n])
		n++;
	return (s1[n] - s2[n]);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	trimlen;
	int		a;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	a = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimlen = end - start;
	str = (char *)malloc(trimlen + 1);
	if (!str)
		return (NULL);
	while (start < end)
		str[a++] = s1[start++];
	str[a] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	if (n == 0)
		return (0);
	a = 0;
	while (s1[a] && s2[a] && a < n)
	{
		if ((unsigned char)s1[a] != (unsigned char)s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	if (a < n)
		return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	return (0);
}

int	ft_isdigit(char *str)
{
	int	i;
	int	count_space;

	i = 0;
	count_space = 0;
	while (str[i])
	{
		if (str[i] == 32)
		{
			count_space++;
			i++;
			if (str[i] == '\0')
				break ;
			if (str[i] == 32)
				return (1);
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		if (count_space > 2)
			return (1);
		i++;
	}
	return (0);
}

char	ft_isdigit_char(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
