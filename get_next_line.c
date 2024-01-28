/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:04:15 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/26 13:43:47 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*new_lines(char *rd_lines)
{
	char	*line_new;
	int		i;
	int		j;

	i = 0;
	while (rd_lines[i] && rd_lines[i] != '\n')
		i++;
	if (!rd_lines[i])
	{
		free(rd_lines);
		return (NULL);
	}
	line_new = malloc(ft_strlen(rd_lines) - i + 1);
	if (!line_new)
		return (NULL);
	i++;
	j = 0;
	while (rd_lines[i])
	{
		line_new[j++] = rd_lines[i++];
	}
	line_new[j] = '\0';
	free(rd_lines);
	return (line_new);
}

char	*get_lines(char *rd_lines)
{
	char	*lines;
	int		i;

	lines = NULL;
	i = 0;
	if (!rd_lines[i])
		return (NULL);
	lines = allocat_lines(rd_lines, lines);
	if (!lines)
		return (NULL);
	i = 0;
	while (rd_lines[i] && rd_lines[i] != '\n')
	{
		lines[i] = rd_lines[i];
		i++;
	}
	if (rd_lines[i] == '\n')
	{
		lines[i] = '\n';
		lines[i + 1] = '\0';
	}
	else
		lines[i] = '\0';
	return (lines);
}

void	*ft_free(char *rd_lines, char *str, int nb, char *buffer)
{
	if (nb < 0)
	{
		free(buffer);
		free(rd_lines);
		return (NULL);
	}
	if (!rd_lines)
	{
		free(str);
		free(buffer);
		return (NULL);
	}
	return (NULL);
}

char	*read_lines(int fd, char *rd_lines)
{
	char	*buffer;
	char	*str;
	int		nb;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nb = 1;
	while (!ft_strchr(rd_lines, '\n') && nb != 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb < 0)
			return (ft_free(rd_lines, str, nb, buffer));
		buffer[nb] = '\0';
		str = rd_lines;
		rd_lines = ft_strjoin(rd_lines, buffer);
		if (!rd_lines)
			return (ft_free(rd_lines, str, nb, buffer));
		free(str);
	}
	free(buffer);
	buffer = NULL;
	return (rd_lines);
}

char	*get_next_line(int fd)
{
	static char		*rd_lines;
	char			*lines;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (!rd_lines)
	{
		rd_lines = ft_strjoin("", "");
		if (!rd_lines)
			return (NULL);
	}
	rd_lines = read_lines(fd, rd_lines);
	if (!rd_lines)
		return (NULL);
	lines = get_lines(rd_lines);
	rd_lines = new_lines(rd_lines);
	return (lines);
}

/*#include <stdio.h>
int main()
{
	int fd = open("text.txt", O_RDWR, 777);
	if(fd < 0)
	return -1;

	char *str;
	int i = 0;
	while(i < 4)
	{
		str = get_next_line(fd);
		printf("%d->%s", i, str);
		free(str);
		i++;
	}

	system("leaks -q a.out");
	return (0);
}*/
