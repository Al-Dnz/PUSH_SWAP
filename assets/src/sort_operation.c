/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:22:41 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/06 16:02:11 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	sa/sb/ss
*/

void	swap_list(t_list *li, int verbose, t_state *state)
{
	g_accumulator++;
	void	*tmp;

	if (li == NULL || li->next == NULL)
		return ;
	tmp = li->content;
	li->content = li->next->content;
	li->next->content = tmp;
	ft_del(tmp);

	if (verbose == 1 && state->seq && state->seq->n == 2)
		register_last(state->seq)->n = 3;
	else if (verbose == 2  && state->seq && state->seq->n == 1)
		register_last(state->seq)->n = 3;
	else if (verbose == 1 || verbose == 2)
		register_add_back(&state->seq, register_new(verbose));
}

void	double_swap_list(t_list *li_a, t_list *li_b, int verbose, t_state *state)
{
	g_accumulator++;
	swap_list(li_a, 0, state);
	swap_list(li_b, 0, state);
	if (verbose == 1)
		register_add_back(&state->seq, register_new(3));
}

/*
**	ra/rb/rr
*/

void	shift_up(t_list **li, int verbose, t_state *state)
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
	if (verbose == 1 && state->seq  && state->seq->n == 7)
		register_last(state->seq)->n = 8;
		//ft_putstr_fd("ra\n", 1);
	else if (verbose == 2  && state->seq && state->seq->n == 6)
		register_last(state->seq)->n = 8;
	else if (verbose == 1 || verbose == 2)
		register_add_back(&state->seq, register_new(verbose + 5));
		//ft_putstr_fd("rb\n", 1);
}

void	double_shift_up(t_list **li_a, t_list **li_b, int verbose, t_state *state)
{
	g_accumulator++;
	shift_up(li_a, 0, state);
	shift_up(li_b, 0, state);
	if (verbose == 1)
		register_add_back(&state->seq, register_new(8));
		//ft_putstr_fd("rr\n", 1);
}

/*
**	rra/rrb/rrr
*/

void	shift_down(t_list **li, int verbose, t_state *state)
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
	if (verbose == 1   && state->seq && state->seq->n == 10)
		register_last(state->seq)->n = 11;
		//ft_putstr_fd("rra\n", 1);
	else if (verbose == 2  && state->seq && state->seq->n == 9)
		register_last(state->seq)->n = 11;
		//ft_putstr_fd("rrb\n", 1);
	else if (verbose == 1 || verbose == 2)
		register_add_back(&state->seq, register_new(verbose + 8));
}

void	double_shift_down(t_list **li_a, t_list **li_b, int verbose, t_state *state)
{
	g_accumulator++;
	shift_down(li_a, 0, state);
	shift_down(li_b, 0, state);
	if (verbose == 1)
		register_add_back(&state->seq, register_new(11));
		//ft_putstr_fd("rrr\n", 1);
}

/*
**	 pa/pb
*/

void	transfer_top(t_list **li_a, t_list **li_b, int verbose, t_state *state)
{
	g_accumulator++;
	void	*tmp;

	if (*li_a == NULL)
		return ;
	tmp = ft_lstpop(li_a);
	ft_lstadd_front(li_b, ft_lstnew(tmp));
	ft_del(tmp);
	if (verbose == 1)
		register_add_back(&state->seq,register_new(4));
		//ft_putstr_fd("pa\n", 1);
	if (verbose == 2)
		register_add_back(&state->seq,register_new(5));
		//ft_putstr_fd("pb\n", 1);
}
