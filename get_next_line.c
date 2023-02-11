/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:48 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/11 15:01:09 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// utilizza read per leggere il file e salva in backup (grandezza BUFFER_SIZE)
// continua a leggere finche non raggiunge \n o EOF
char	*ft_read(int fd, char *stack)
{
}

// estrae la linea dallo stack
char	*extract_line(char *stack)
{
}

//rimuove la la prima linea(tutti gli elementi fino a \n)
char	*ft_clean(char *stack)
{
}


char	*get_next_line(int fd)
{
	char	*line;
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stack = ft_read();
	if (!stack)
		return (NULL);
	line = extract_line(stack);
	if (!line)
		return (NULL);
	stack = ft_clean(stack);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
