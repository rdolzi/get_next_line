/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:48 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/12 18:12:10 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// utilizza read per leggere il file e salva in backup (grandezza BUFFER_SIZE)
	//leggere buffer volte fino a che non troviamo non raggiunge \n o EOF
	//salvare buffer in stack e continuare a leggere
char	*ft_read(int fd, char *stack)
{
	char	*buffer;
	int		len;

	while (len != 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);

		len = read(fd, buffer, BUFFER_SIZE);
		buffer[len + 1] = '\0';
		stack = ft_strjoin(stack, buffer);
		free(buffer);
	}
	return (stack);
}
/*
// estrae la linea dallo stack
char	*extract_line(char *stack)
{
}

//rimuove la la prima linea(tutti gli elementi fino a \n)
void	ft_clean(char *stack)
{
}*/


char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	stack = "";
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stack = ft_read(fd, stack);
	if (!stack)
		return (NULL);/*
	line = extract_line(stack);
	if (!line)
		return (NULL);
	ft_clean(stack);*/
	return (stack);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
