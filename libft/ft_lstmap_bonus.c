/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:59:00 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/26 15:43:09 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_lst_first;

	if (!lst || !f || !del)
		return (NULL);
	new_lst_first = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&new_lst_first, del);
			break ;
		}
		ft_lstadd_back(&new_lst_first, new_lst);
		lst = lst->next;
	}
	return (new_lst_first);
}

