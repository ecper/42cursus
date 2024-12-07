/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:29:17 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/16 02:38:49 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_buffer(t_next_line *data)
{
	free(data->buffer);
	data->buffer_index = 0;
	data->bytes_read = 0;
	data->buffer = NULL;
}

static char	*free_dest_and_dup(t_next_line *data)
{
	char	*tmp;

	tmp = ft_strdup(data->dest);
	free(data->dest);
	data->dest_index = 0;
	data->dest = NULL;
	return (tmp);
}

static int	read_file(t_next_line *data, int fd)
{
	if ((!BUFFER_SIZE || fd < 0))
		return (0);
	if (!data->bytes_read)
	{
		data->buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		data->bytes_read = read(fd, data->buffer, BUFFER_SIZE);
		if (data->bytes_read < 0)
		{
			free_buffer(data);
			return (0);
		}
		data->buffer[data->bytes_read] = '\0';
	}
	return (1);
}

static void	start_put_char(t_next_line *data)
{
	while (data->bytes_read > 0)
	{
		data->dest = ft_putstr(data->dest, data->buffer[data->buffer_index]);
		data->dest_index++;
		data->bytes_read--;
		if (data->buffer[data->buffer_index] == '\n')
			break ;
		data->buffer_index++;
	}
}

char	*get_next_line(int fd)
{
	static t_next_line	data;

	if (!read_file(&data, fd))
		return (NULL);
	if (data.buffer[0] == '\0')
	{
		free(data.buffer);
		if (data.dest_index)
			return (free_dest_and_dup(&data));
		return (NULL);
	}
	start_put_char(&data);
	if (data.buffer[data.buffer_index] == '\n')
	{
		data.buffer_index++;
		if (!data.bytes_read)
			free_buffer(&data);
		return (free_dest_and_dup(&data));
	}
	if (!data.bytes_read)
	{
		free_buffer(&data);
		return (get_next_line(fd));
	}
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDWR);

	// int i;
	char *s;

	// i = 0;
	// s = get_next_line(fd);
	// printf("test: %s", s);
	// free(s);
	// s = NULL;
	// s = get_next_line(fd);
	// printf("test: %s", s);
	// // free(s);
	// // s = NULL;
	// s = get_next_line(fd);
	// printf("test: %s", s);
	// // free(s);
	// // s = NULL;
	// s = get_next_line(fd);
	// printf("test: %s", s);

	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	while (s)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	close(fd);
};