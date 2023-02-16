/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:48 by rdolzi            #+#    #+#             */
/*   Updated: 2023/02/16 16:42:58 by rdolzi           ###   ########.fr       */
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
	
	len = 1;
	while (!ft_strchr(stack, '\n') && len > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0 )
			return (NULL);
		buffer[len] = '\0';
//		printf("Buffer: %s |len:%d\n ", buffer, len);
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
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n')
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
	return (line);
}

//rimuove la la prima linea(tutti gli elementi fino a \n)
char	*ft_clean(char *stack)
{
	int	i;
	int j;
	int k;
	char	*clean_stack;
	printf("|stack:%s|\n",stack);
	i = 0;
	while (stack[i] != '\n')
		i++;
	j = (int)ft_strlen(stack);
	clean_stack = (char *)malloc(sizeof(char) * ( j - i));
	if (!clean_stack)
		return (NULL);
	k = 0;
	while (j > i)
		clean_stack[k++] = stack[i++];
	clean_stack[k] = '\0';
	printf("\nclean:%s|\n", clean_stack);
	return (clean_stack);
}


char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;
	
	stack = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	stack = ft_read(fd, stack);
	if (!stack)
		return (NULL);
	line = extract_line(stack);
	if (!line)
		return (NULL);
	stack = ft_clean(stack);
	return (line); //stack
}
/*
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf(">line:%s\n", str);
	free(str);
	//close(fd);
	
	str = get_next_line(fd);
	printf(">line:%s\n",str);
	free(str);
		str = get_next_line(fd);
	printf("%s",str);
	free(str);
		str = get_next_line(fd);
	printf(">line:%s\n",str);
	free(str);
}*/
