/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:00:27 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 20:54:00 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate_base(t_list **lst, t_list **lst2)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		exit_error(lst, lst2);
	tmp = ft_lstlast(*lst);
	new = ft_lstnew(tmp->content);
	if (!new)
		exit_error(lst, lst2);
	ft_lstadd_front(lst, new);
	tmp->prev->next = NULL;
	ft_lstdelone(tmp, ft_contentdelone);
}

void	rra(t_list **a, t_list **b)
{
	rrotate_base(a, b);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b, t_list **a)
{
	rrotate_base(b, a);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate_base(a, b);
	rrotate_base(b, a);
	write(1, "rrr\n", 4);
}
