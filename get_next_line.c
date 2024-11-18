/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:18:59 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/18 19:45:46 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **joint)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		*joint = ft_strjoin(*joint, buffer);
		if (ft_strchr(*joint, '\n') >= 0)
			return (*joint);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(*joint), *joint = NULL, NULL);
	return (*joint);
}

char	*extract_line(char **joint)
{
	char	*line;
	int		nl_index;
	char	*temp;

	if (!joint || !*joint)
		return (free(*joint), *joint = NULL, NULL);
	nl_index = ft_strchr(*joint, '\n');
	if (nl_index >= 0)
	{
		line = ft_substr(*joint, 0, nl_index + 1);
		temp = ft_strdup(*joint + nl_index + 1);
		free(*joint);
		*joint = temp;
		if (!line || (*joint && !**joint))
			return (free(*joint), *joint = NULL, line);
		return (line);
	}
	return (line = ft_strdup(*joint), free(*joint), *joint = NULL, line);
}

char	*get_next_line(int fd)
{
	static char	*joint;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(joint), joint = NULL, NULL);
	joint = read_line(fd, &joint);
	return (extract_line(&joint));
}
