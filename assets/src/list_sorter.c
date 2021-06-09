/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:07:23 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/09 15:20:13 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*sorted_merge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if ((int)a->content <= (int)b->content)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void	front_backsplit(t_list *source, t_list **front_ref, t_list **back_ref)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	list_merge_sort(t_list **head_ref)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	front_backsplit(head, &a, &b);
	list_merge_sort(&a);
	list_merge_sort(&b);
	*head_ref = sorted_merge(a, b);
}
