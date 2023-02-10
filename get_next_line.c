/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:48 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/10 11:26:15 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*line;
	
	line = ft_strdup("");
	read(fd,line,20);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
