/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:48 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/14 18:02:20 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



// utilizza read per leggere il file e salva in backup (grandezza BUFFER_SIZE)
	//leggere buffer volte fino a che non troviamo non raggiunge \n o EOF
	//salvare buffer in stack e continuare a leggere
	// || len != 0 ? 
char	*ft_read(int fd, char *stack)
{
	char	*buffer;
	int		len;

	while (!ft_strchr(stack, '\n'))
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

// lo stack contiene lo \n ma può contenere anche char successivi
// extract_line estrae la linea dallo stack ( \n incluso ) 
// e aggiunge il null byte
char	*extract_line(char *stack)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stack[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
/*
//rimuove la la prima linea(tutti gli elementi fino a \n)
void	ft_clean(char *stack)
{
}*/


char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	stack = malloc(1);
	if (!stack)
		return (NULL);
	stack[0] = '\0';
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	stack = ft_read(fd, stack);
	if (!stack)
		return (NULL);
	line = extract_line(stack);
	if (!line)
		return (NULL);/*
	ft_clean(stack);*/
	return (line); //stack
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
		str = get_next_line(fd);
	printf("%s",str);
	free(str);
		str = get_next_line(fd);
	printf("%s",str);
	free(str);
}
