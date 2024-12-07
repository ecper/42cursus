/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:29:12 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/06 00:45:58 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_next_line
{
	char	*buffer;
	char	*dest;
	int		bytes_read;
	int		buffer_index;
	int		dest_index;

}			t_next_line;

char		*ft_strdup(const char *src);
char		*ft_putstr(char const *s1, char s2);
char		*get_next_line(int fd);
#endif