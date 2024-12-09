/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amnalnaq <amnalnaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:55:37 by suhelal           #+#    #+#             */
/*   Updated: 2024/10/11 15:30:00 by amnalnaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	len_withot_space(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (len >= 0 && str[len] == ' ')
		len--;
	return (len);
}

int	get_height(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int	get_width(char **str)
{
	size_t	length;
	int		i;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > length)
			length = ft_strlen(str[i]);
		i++;
	}
	return (length);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (size != 0 && count > UINT32_MAX / size)
		return (NULL);
	a = malloc (size * count);
	if (!a)
		return (0);
	ft_bzero (a, size * count);
	return (a);
}

void	free_void(void **text)
{
	size_t	i;

	i = 0;
	while (text[i])
	{
		free(text[i]);
		i++;
	}
	if (text)
	{
		free(text);
		text = NULL;
	}
}
