/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soaoki <soaoki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:22:04 by soaoki            #+#    #+#             */
/*   Updated: 2025/01/31 20:22:07 by soaoki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_trim_white(const char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (str[start]
		&& (str[start] == ' ' || str[start] == '\n' || str[start] == '\t'))
			start++;
	while (end > start
		&& (str[end] == ' ' || str[end] == '\n' || str[end] == '\t'))
		end--;
	return (ft_substr(str, start, end - start + 1));
}

int	color_atoi(char *color_code)
{
	unsigned int	result;
	int				i;
	char			*str;

	str = ft_trim_white(color_code);
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
	{
		free(str);
		return (ATOI_ERROR);
	}
	result = 0;
	i = 0;
	while (str[i])
	{	
		result = result * 10 + (str[i++] - '0');
		if (0 > result || result > 255)
		{
			free(str);
			return (ATOI_ERROR);
		}
	}
	return (free(str), (int)result);
}

int	count_strarray(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	present_info(t_config *config)
{
	if (config->ceil.appear && config->floor.appear && config->path_ea.appear
		&&config->path_no.appear && config->path_so.appear
		&& config->path_we.appear)
		return (1);
	return (0);
}

int	get_maxarray_index(char **stringarray)
{
	int	i;
	int	len;
	int	max_len;

	i = 0;
	max_len = 0;
	while (stringarray[i] != NULL)
	{
		len = ft_strlen(stringarray[i ++]);
		if (len > max_len)
			max_len = len;
	}
	return (max_len);
}
