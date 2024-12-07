/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:00:12 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 21:15:51 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	success(t_list **a, t_list **b)
{
	if (a != NULL && *a != NULL)
		ft_lstclear(a, ft_contentdelone);
	if (b != NULL && *b != NULL)
		ft_lstclear(b, ft_contentdelone);
}

void	exit_error(t_list **a, t_list **b)
{
	success(a, b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	success_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_all(t_list **a, t_list **b, char **argv, int arg_status)
{
	if (arg_status == 2)
		success_split(argv);
	exit_error(a, b);
}
