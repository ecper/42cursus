/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:12:35 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 18:53:14 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_bits(int n)
{
	int	i;

	i = sizeof(int) * 8 - 1;
	while (i >= 0)
	{
		if ((n >> i) & 1)
			break ;
		i--;
	}
	return (i + 1);
}

int	get_max_bits(t_list *lst)
{
	int		max;
	t_list	*tmp;

	tmp = lst;
	max = 0;
	while (tmp)
	{
		if (max < *(int *)tmp->content)
			max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (count_bits(max));
}

int	get_max_index(t_list *lst)
{
	int		max;
	int		max_index;
	int		i;
	t_list	*tmp;

	i = 0;
	max_index = 0;
	tmp = lst;
	max = *(int *)tmp->content;
	while (tmp)
	{
		if (max < *(int *)tmp->content)
		{
			max_index = i;
			max = *(int *)tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_index);
}

int	get_min_index(t_list *lst)
{
	int		min;
	int		min_index;
	int		i;
	t_list	*tmp;

	i = 0;
	min_index = 0;
	tmp = lst;
	min = *(int *)tmp->content;
	while (tmp)
	{
		if (min > *(int *)tmp->content)
		{
			min_index = i;
			min = *(int *)tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}
