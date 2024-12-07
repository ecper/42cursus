/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:52:35 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/01 20:00:02 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_issplit(char s, char c)
{
	if (s == c)
	{
		return (1);
	}
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count_flag;
	int	count;

	i = 0;
	count_flag = 1;
	count = 0;
	while (str[i])
	{
		if (count_flag && !ft_issplit(str[i], c))
		{
			count++;
			count_flag = 0;
		}
		if (ft_issplit(str[i], c))
			count_flag = 1;
		i++;
	}
	return (count);
}

static char	check_free(char **dest, char *substr, int put_words)
{
	int	i;

	i = 0;
	if (!substr)
	{
		while (i < put_words)
			free(dest[i]);
		return (0);
	}
	dest[put_words] = substr;
	return (1);
}

static int	do_split(char **dest, char const *s, char c, size_t s_len)
{
	size_t	i;
	int		len;
	int		put_words;

	i = 0;
	len = 0;
	put_words = 0;
	while (i <= s_len)
	{
		if (len && (ft_issplit(s[i], c) || !s[i]))
		{
			if (!check_free(dest, ft_substr(&s[i - len], 0, len), put_words))
				return (0);
			put_words++;
			len = 0;
		}
		if (!ft_issplit(s[i], c))
			len++;
		i++;
	}
	dest[put_words] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	s_len;

	dest = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	s_len = ft_strlen(s);
	if (!dest)
		return (NULL);
	if (!do_split(dest, s, c, s_len))
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}
