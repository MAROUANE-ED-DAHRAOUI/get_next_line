/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-dahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:04:45 by med-dahr          #+#    #+#             */
/*   Updated: 2024/01/27 18:05:06 by med-dahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX
#  define MAX 10240
# endif

char	*allocat_lines(char *rd_lines, char *lines);
void	*ft_free(char *rd_lines, char *str, int nb, char *buffer);
char	*get_next_line(int fd);
char	*read_lines(int fd, char *rd_lines);
char	*get_lines(char *rd_lines);
char	*new_lines(char *rd_lines);
size_t	ft_strlen(char const *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);

#endif
