/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:48 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/19 14:37:08 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// utilizza read per leggere il file e salva in backup (grandezza BUFFER_SIZE)
//legge buffer volte fino a che non troviamo non raggiunge \n o EOF
//salvando il risultato in stack
char	*ft_read(int fd, char *stack)
{
	char	*buffer;
	int		len;

	len = 1;
	while (!ft_strchr(stack, '\n') && len != 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0 )
		{
			free(stack);
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	return (stack);
}
// extract_line estrae la linea dallo stack ( \n incluso, se presente ) 
// e aggiunge il null byte
// lo stack può presentarsi in due casi:
// 1. contiene il char \n e forse   char successivi
// 2. può non contenere alcun \n ( caso in cui il file non ne abbia alcuno)

char	*extract_line(char *stack)
{
	size_t	i;
	char	*line;
	size_t	j;

	if (!stack[0])
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	if (stack[i] == '\n')
		j = 2;
	else
		j = 1;
	line = (char *)malloc(sizeof(char) * (i + j));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i])
	{
		line[i] = stack[i];
		i++;
	}
	if (j == 2)
	{	
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	i = 0;
	if (!line[0])
	{
		free(stack);
		free(line);
		return (NULL);
	}
	return (line);
}

//rimuove la la prima linea(tutti gli elementi fino a \n)
char	*ft_clean(char *stack)
{
	int		i;
	int		j;
	int		k;
	int		barbatrucco;
	char	*clean_stack;

	i = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	if (stack[i] == '\n')
		barbatrucco = 0;
	else
		barbatrucco = 1;
	j = (int)ft_strlen(stack);
	clean_stack = (char *)malloc(sizeof(char) * (j - i + barbatrucco));
	if (!clean_stack)
		return (NULL);
	k = 0;
	j--;
	while (j > i)
	{
		i++;
		clean_stack[k] = stack[i];
		k++;
	}
	clean_stack[k] = '\0';
	if (!clean_stack[0])
	{
		free(clean_stack);
		free(stack);
		return (NULL);
	}
	free(stack);
	return (clean_stack);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;

	if (!stack)
		stack = ft_strdup("");
	stack = ft_read(fd, stack);
	if (!stack)
		return (NULL);
	line = extract_line(stack);
	if (!line)
		return (NULL);
	stack = ft_clean(stack);
	return (line);
}

/*
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf(">line:%s\n", str);
	free(str);
	
	str = get_next_line(fd);
	printf(">line:%s\n",str);
	free(str);
		str = get_next_line(fd);
	printf("%s",str);
	free(str);
		str = get_next_line(fd);
	printf(">line:%s\n",str);
	free(str);
	close(fd);
		str = get_next_line(fd);
	printf(">line:%s\n",str);
	free(str);
}*/
