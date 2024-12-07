/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:54:10 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 20:53:30 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_base(t_list **take, t_list **push)
{
	t_list	*new;
	t_list	*tmp;

	if (!take || !*take)
		return ;
	new = ft_lstnew((*take)->content);
	if (!new)
		exit_error(take, push);
	ft_lstadd_front(push, new);
	tmp = (*take)->next;
	ft_lstdelone(*take, ft_contentdelone);
	*take = tmp;
}

void	pa(t_list **a, t_list **b)
{
	push_base(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push_base(a, b);
	write(1, "pb\n", 3);
}
