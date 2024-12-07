/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:58:08 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 20:53:49 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_base(t_list **lst, t_list **lst2)
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		exit_error(lst, lst2);
	new = ft_lstnew((*lst)->content);
	if (!new)
		exit_error(lst, lst2);
	tmp = (*lst);
	ft_lstadd_back(lst, new);
	*lst = (*lst)->next;
	ft_lstdelone(tmp, ft_contentdelone);
}

void	ra(t_list **a, t_list **b)
{
	rotate_base(a, b);
	write(1, "ra\n", 3);
}

void	rb(t_list **b, t_list **a)
{
	rotate_base(b, a);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate_base(a, b);
	rotate_base(b, a);
	write(1, "rr\n", 3);
}
