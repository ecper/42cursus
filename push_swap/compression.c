/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hauchida <hauchida@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:06:44 by hauchida          #+#    #+#             */
/*   Updated: 2024/12/04 21:15:42 by hauchida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

static t_list	*find_content(t_list *lst, int search_elem)
{
	while (lst)
	{
		if (*(int *)lst->content == search_elem)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static void	input_value(int *arr, int size, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && i < size)
	{
		arr[i] = *(int *)(lst->content);
		lst = lst->next;
		i++;
	}
}

void	compression(t_list **lst)
{
	t_list	*tmp;
	int		size;
	int		i;
	int		*comp_content;

	size = ft_lstsize(*lst);
	comp_content = (int *)malloc(sizeof(int) * (size));
	if (!comp_content)
		exit_error(lst, NULL);
	tmp = *lst;
	i = 0;
	input_value(comp_content, size, *lst);
	sort(comp_content, size);
	i = 0;
	while (i < size)
	{
		tmp = find_content(*lst, comp_content[i]);
		*(int *)tmp->content = i;
		i++;
	}
	free(comp_content);
}
