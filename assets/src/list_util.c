/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:21:23 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/17 17:32:04 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	lst_is_sort(t_list *li)
{
	int		sens;

	if (ft_lstsize(li) <= 1)
		return (1);
	while (li->next && (int)li->content == (int)li->next->content)
		li = li->next;
	if (li->next == NULL)
		return (1);
	sens = (int)li->next->content > (int)li->content;
	while (li && li->next)
	{
		if (sens && (int)li->next->content < (int)li->content)
			return (0);
		if (!sens && (int)li->next->content > (int)li->content)
			return (0);
		li = li->next;
	}
	if (sens == 0)
		return (-1);
	else
		return (1);
}

int	lst_cmp(t_list *li_a, t_list *li_b)
{
	if (ft_lstsize(li_a) != ft_lstsize(li_b))
		return (0);
	while (li_a && li_b)
	{
		if ((int)li_a->content != (int)li_b->content)
			return (0);
		li_b = li_b->next;
		li_a = li_a->next;
	}
	return (1);
}

t_list	*list_min(t_list *li)
{
	t_list	*res;
	t_list	*tmp;

	res = li;
	while (li)
	{
		tmp = li;
		while (tmp)
		{
			if ((int)res->content > (int)tmp->content)
				res = tmp;
			tmp = tmp->next;
		}
		li = li->next;
	}
	return (res);
}

t_list	*list_max(t_list *li)
{
	t_list	*res;
	t_list	*tmp;

	res = li;
	while (li)
	{
		tmp = li;
		while (tmp)
		{
			if ((int)res->content < (int)tmp->content)
				res = tmp;
			tmp = tmp->next;
		}
		li = li->next;
	}
	return (res);
}

t_list	*lst_cpy(t_list *li, int size)
{
	t_list	*temp;
	t_list	*lst;

	temp = NULL;
	lst = NULL;
	while (li && size--)
	{
		lst = ft_lstnew(li->content);
		ft_lstadd_back(&temp, lst);
		li = li->next;
	}
	return (temp);
}
