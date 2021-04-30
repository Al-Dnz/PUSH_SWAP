/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:22:41 by adenhez           #+#    #+#             */
/*   Updated: 2021/04/30 22:28:26 by adenhez          ###   ########.fr       */
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

/*
**	sa/sb/ss
*/

void	swap_list(t_list *li)
{
	void	*tmp;

	if (li == NULL || li->next == NULL)
		return ;
	tmp = li->content;
	li->content = li->next->content;
	li->next->content = tmp;
	ft_del(tmp);
}

/*
**	ra/rb/rr
*/

void	shift_up(t_list **li)
{
	t_list	*new;
	void	*tmp;

	if (*li == NULL || ft_lstsize(*li) < 2)
		return ;
	tmp = ft_lstshift(*li);
	new = ft_lstnew(tmp);
	ft_lstadd_front(li, new);
	ft_del(tmp);
}

/*
**	rra/rrb/rrr
*/

void	shift_down(t_list **li)
{
	t_list	*new;
	void	*tmp;

	if (*li == NULL || ft_lstsize(*li) < 2)
		return ;
	tmp = ft_lstpop(li);
	new = ft_lstnew(tmp);
	ft_lstadd_back(li, new);
	ft_del(tmp);
}

/*
**	 pa/pb
*/

void	transfer_top(t_list **li_a, t_list **li_b)
{
	void	*tmp;

	if (*li_a == NULL)
		return ;
	tmp = ft_lstpop(li_a);
	ft_lstadd_front(li_b, ft_lstnew(tmp));
	ft_del(tmp);
}
