/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:35:48 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 19:47:59 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	size = ft_lstsize(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((*(int *)((*a)->content) >> i) & 1)
				ra(a, b);
			else if (j != size - 1)
				pb(a, b);
			j++;
		}
		while (ft_lstsize(*b) > 0)
			pa(a, b);
		i++;
	}
}

static void	three_sort(t_list **lst)
{
	int	max_index;

	max_index = get_max_index(*lst);
	if (max_index == 2)
		sa(*lst, NULL);
	else if (max_index == 1)
		rra(lst, NULL);
	else if (max_index == 0)
		ra(lst, NULL);
	if (is_valid_sort(*lst))
		sa(*lst, NULL);
}

static void	search_min_and_push(t_list **a, t_list **b, int count, int i)
{
	int	min_index;

	if (i == 2)
		return ;
	min_index = get_min_index(*a);
	if (min_index > 2)
	{
		while (min_index < count - i)
		{
			rra(a, b);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			ra(a, b);
			min_index--;
		}
	}
	pb(a, b);
	search_min_and_push(a, b, count, i + 1);
}

static void	four_or_five_sort(t_list **a, t_list **b, int count)
{
	search_min_and_push(a, b, count, 0);
	three_sort(a);
	pa(a, b);
	pa(a, b);
}

void	lets_sort(t_list **a, t_list **b, int count)
{
	if (count == 1)
		return ;
	if (count == 2)
		sa(*a, *b);
	else if (count == 3)
		three_sort(a);
	else if (count == 4)
		four_or_five_sort(a, b, 4);
	else if (count == 5)
		four_or_five_sort(a, b, 5);
	else
		radix_sort(a, b);
}
