/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:11:56 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/14 12:57:15 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*find_median(t_list *li)
{
	t_list	*temp;
	t_list	*res;
	int		size;
	int		i;

	size = ft_lstsize(li);
	i = 0;
	temp = NULL;
	lst_cpy(&temp, li, size);
	list_merge_sort(&temp);
	while (i++ <= size / 2)
		temp = temp->next;
	res = ft_lstnew(NULL);
	res->content = temp->content;
	ft_lstclear(&temp, ft_del);
	return (res);
}

int	optimized_shift(t_list *li, t_list *target_lst)
{
	int	before;
	int	after;

	before = 0;
	after = 0;
	while ((int)li->content != (int)target_lst->content)
	{
		before++;
		li = li->next;
	}
	if (li)
		li = li->next;
	while (li)
	{
		after++;
		li = li->next;
	}
	if (before == 0)
		return (-1);
	else if (before <= after)
		return (0);
	else
		return (1);
}

int	dist_to_lst(t_list *li, t_list *list)
{
	int	dist;

	dist = 0;
	while (li)
	{
		if ((int)li->content == (int)list->content)
			return (dist);
		dist++;
		li = li->next;
	}
	if (ft_lstsize(li) - dist + 1 < dist)
		return (ft_lstsize(li) - dist + 1);
	else
		return (dist);
}

void	bring_back(t_list **li_a, t_list **li_b, t_state *state)
{
	while (*li_b != NULL)
	{
		g_accumulator++;
		transfer_top(li_b, li_a, 2, state);
	}
}
