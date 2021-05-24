/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:21:23 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/24 14:55:19 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_list(t_list *li)
{
	while (li != NULL)
	{
		ft_putstr_fd("[", 1);
		ft_putnbr_fd((int)li->content, 1);
		ft_putstr_fd("]->", 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

void	visual_list(t_list *li)
{
	int	n;
	while (li != NULL)
	{
		n  = (int)li->content;
		while (n--)
			ft_putchar_fd('_', 1);
		ft_putchar_fd('\n', 1);
		li = li->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

int	lst_is_sort(t_list *li)
{
	int		sens;

	if (ft_lstsize(li) <= 1)
		return (1);
	while (li->next && (int)li->content == (int)li->next->content)
		li = li->next;
	if (li->next == NULL)
		return (1);
	sens = (int)li->next->content > (int)li->content ? 1 : 0;
	while (li && li->next)
	{
		
		if (sens && (int)li->next->content < (int)li->content)
			return (0);
		if (!sens && (int)li->next->content > (int)li->content)
			return (0);
		/*
		if ((int)li->next->content < (int)li->content)
			return (0);
		*/
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
	t_list *res;
	t_list *tmp;

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
	/*
	if (res != NULL)
		res->next = NULL;
	*/
	return (res);
}

t_list	*list_max(t_list *li)
{
	t_list *res;
	t_list *tmp;

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

t_list	*chunk_min(t_list *li, int size)
{
	t_list *res;
	t_list *tmp;

	res = li;
	while (li && size--)
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
	/*
	if (res != NULL)
		res->next = NULL;
	*/
	return (res);
}

t_list	*chunk_max(t_list *li, int size)
{
	t_list *res;
	t_list *tmp;

	res = li;
	while (li && size--)
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

void	lst_cpy(t_list **dest, t_list *li, int size)
{
	t_list *temp;

	while (size--) 
	{
		temp = ft_lstnew(li->content);
		ft_lstadd_back(dest, temp);
		li = li->next;
	}
}
