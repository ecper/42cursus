/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:49:00 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 20:54:17 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_base(t_list *lst, t_list *lst2)
{
	int	tmp;

	if (!lst)
		exit_error(&lst, &lst2);
	if (ft_lstsize(lst) <= 1)
		return ;
	tmp = *(int *)(lst->content);
	*(int *)(lst->content) = *(int *)lst->next->content;
	*(int *)(lst->next->content) = tmp;
}

void	sa(t_list *a, t_list *b)
{
	swap_base(a, b);
	write(1, "sa\n", 3);
}

void	sb(t_list *b, t_list *a)
{
	swap_base(b, a);
	write(1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	swap_base(a, b);
	swap_base(b, a);
	write(1, "ss\n", 3);
}
