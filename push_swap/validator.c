/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:08:41 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 16:19:05 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_sort(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		if (*(int *)lst->content > *(int *)lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	is_valid_duplicate(t_list *lst)
{
	int		compare;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		compare = *(int *)tmp1->content;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (*(int *)tmp2->content == compare)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

int	is_valid_isdigits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}
