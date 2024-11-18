/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-mou <isel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:27:13 by isel-mou          #+#    #+#             */
/*   Updated: 2024/11/18 21:23:53 by isel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *joint)
{
	size_t	i;

	if (!joint)
		return (0);
	i = 0;
	while (joint[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *joint, char *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	string = malloc(ft_strlen(joint) + ft_strlen(s2) + 1);
	if (!string)
		return (free(joint), NULL);
	i = 0;
	if (joint)
	{
		while (joint[i])
		{
			string[i] = joint[i];
			i++;
		}
		free(joint);
	}
	j = 0;
	while (s2[j])
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

char	*ft_strdup(char *joint)
{
	char	*new_joint;
	size_t	i;

	new_joint = malloc(ft_strlen(joint) + 1);
	if (!new_joint)
		return (NULL);
	i = 0;
	while (joint[i++])
		new_joint[i - 1] = joint[i - 1];
	new_joint[i - 1] = '\0';
	return (new_joint);
}

int	ft_strchr(const char *joint, int c)
{
	int	i;

	i = 0;
	if (!joint)
		return (-1);
	while (joint[i++])
		if (joint[i - 1] == c)
			return (i - 1);
	return (-1);
}

char	*ft_substr(char *joint, unsigned int start, size_t len)
{
	size_t	joint_len;
	size_t	final;
	char	*sub;
	size_t	i;

	if (!joint)
		return (NULL);
	joint_len = ft_strlen(joint);
	if (start >= joint_len)
		return (malloc(1));
	final = joint_len - start;
	if (final > len)
		final = len;
	sub = malloc(final + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i++ < final && joint[start + i - 1]) 
		sub[i - 1] = joint[start + i - 1];
	sub[i - 1] = '\0';
	return (sub);
}
