/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:39:45 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/20 10:11:55 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_handle_free(char **ptr)
{
	if (*ptr)
	{
		free (*ptr);
		*ptr = NULL;
	}
	ptr = NULL;
}

int	ft_handle_newline(char **remain, char **ptr)
{
	size_t	newline_index;

	if (ft_strchr(*ptr, '\n'))
	{
		newline_index = ft_strchr(*ptr, '\n') - *ptr;
		*remain = ft_strdup(*ptr + newline_index + 1);
		if (*remain && **remain == '\0')
			ft_handle_free(remain);
		if (newline_index == 0)
			*ptr = ft_strdup("");
		else
			ft_bzero(*ptr + newline_index, 1);
		return (1);
	}
	return (0);
}

int	ft_handle_read(char **remain, char **ptr, char **buffer)
{
	char	*temp;

	temp = NULL;
	if (*remain)
	{
		*ptr = ft_strdup(*remain);
		ft_handle_free(remain);
	}
	if (!(*ptr))
		*ptr = ft_strdup(*buffer);
	else
	{
		temp = ft_strdup(*ptr);
		ft_handle_free(ptr);
		*ptr = ft_strjoin(temp, *buffer);
		ft_handle_free(&temp);
	}
	return (ft_handle_newline(remain, ptr));
}

char	*ft_handle_empty_or_eof(char **ptr, char **remain, ssize_t reading)
{
	if (*ptr && **ptr == '\0' && *remain == NULL && reading == 0)
	{
		ft_handle_free(ptr);
		return (NULL);
	}
	if (*ptr && **ptr == '\0')
	{
		ft_handle_free(ptr);
		return (ft_strdup(""));
	}
	return (*ptr);
}

char	*get_next_line(int fd)
{
	ssize_t		reading;
	char		*buffer;
	char		*ptr;
	static char	*remain;

	reading = 1;
	ptr = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading < 0)
			return (ft_handle_free(&buffer), ft_handle_free(&remain), NULL);
		buffer[reading] = '\0';
		if (ft_handle_read(&remain, &ptr, &buffer))
			break ;
	}
	ft_handle_free(&buffer);
	return (ft_handle_empty_or_eof(&ptr, &remain, reading));
}
