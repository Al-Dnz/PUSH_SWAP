/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:22:41 by adenhez           #+#    #+#             */
/*   Updated: 2021/05/24 21:21:30 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	sa/sb/ss
*/

void	swap_list(t_list *li, int verbose)
{
	g_accumulator++;
	void	*tmp;

	if (li == NULL || li->next == NULL)
		return ;
	tmp = li->content;
	li->content = li->next->content;
	li->next->content = tmp;
	ft_del(tmp);
	if (verbose == 1)
		ft_putstr_fd("sa\n", 1);
	if (verbose == 2)
		ft_putstr_fd("sb\n", 1);
}

void	double_swap_list(t_list *li_a, t_list *li_b, int verbose)
{
	g_accumulator++;
	swap_list(li_a, 0);
	swap_list(li_b, 0);
	if (verbose == 1)
		ft_putstr_fd("ss\n", 1);
}

/*
**	ra/rb/rr
*/

void	shift_up(t_list **li, int verbose)
{
	g_accumulator++;
	t_list	*new;
	void	*tmp;

	if (*li == NULL || ft_lstsize(*li) < 2)
		return ;
	tmp = ft_lstshift(li);
	new = ft_lstnew(tmp);
	ft_lstadd_front(li, new);
	ft_del(tmp);
	if (verbose == 1)
		ft_putstr_fd("ra\n", 1);
	if (verbose == 2)
		ft_putstr_fd("rb\n", 1);
}

void	double_shift_up(t_list **li_a, t_list **li_b, int verbose)
{
	g_accumulator++;
	shift_up(li_a, 0);
	shift_up(li_b, 0);
	if (verbose == 1)
		ft_putstr_fd("rr\n", 1);
}

/*
**	rra/rrb/rrr
*/

void	shift_down(t_list **li, int verbose)
{
	g_accumulator++;
	t_list	*new;
	void	*tmp;

	if (*li == NULL || ft_lstsize(*li) < 2)
		return ;
	tmp = ft_lstpop(li);
	new = ft_lstnew(tmp);
	ft_lstadd_back(li, new);
	ft_del(tmp);
	if (verbose == 1)
		ft_putstr_fd("rra\n", 1);
	if (verbose == 2)
		ft_putstr_fd("rrb\n", 1);
}

void	double_shift_down(t_list **li_a, t_list **li_b, int verbose)
{
	g_accumulator++;
	shift_down(li_a, 0);
	shift_down(li_b, 0);
	if (verbose == 1)
		ft_putstr_fd("rrr\n", 1);
}

/*
**	 pa/pb
*/

void	transfer_top(t_list **li_a, t_list **li_b, int verbose)
{
	g_accumulator++;
	void	*tmp;

	if (*li_a == NULL)
		return ;
	tmp = ft_lstpop(li_a);
	ft_lstadd_front(li_b, ft_lstnew(tmp));
	ft_del(tmp);
	if (verbose == 1)
		ft_putstr_fd("pa\n", 1);
	if (verbose == 2)
		ft_putstr_fd("pb\n", 1);
}
