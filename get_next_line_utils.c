/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:40:04 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/19 15:11:05 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = (char *)malloc (s1len + s2len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2len)
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_free(s1, s2);
	return (str);
}
