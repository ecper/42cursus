/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:58:47 by hauchida          #+#    #+#             */
/*   Updated: 2024/11/26 15:35:01 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	// t_list	*next_lst;

	if (!lst || !f)
		return ;
	// next_lst = lst;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
