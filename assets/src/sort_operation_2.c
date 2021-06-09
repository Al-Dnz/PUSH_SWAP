/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:22:41 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/09 16:15:12 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	rra/rrb/rrr
*/

void	shift_down(t_list **li, int verbose, t_state *state)
{
	t_list	*new;
	t_reg	*last_seq;
	void	*tmp;

	if (*li == NULL || ft_lstsize(*li) < 2)
		return ;
	tmp = ft_lstpop(li);
	new = ft_lstnew(tmp);
	ft_lstadd_back(li, new);
	ft_del(tmp);
	last_seq = register_last(state->seq);
	if (verbose == 1 && last_seq && last_seq->n == 10)
		last_seq->n = 11;
	else if (verbose == 2 && last_seq && last_seq->n == 9)
		last_seq->n = 11;
	else if (verbose == 1 || verbose == 2)
		register_add_back(&state->seq, register_new(verbose + 8));
}

void	double_shift_down(t_list **li_a, t_list **li_b,
		int verbose, t_state *state)
{
	shift_down(li_a, 0, state);
	shift_down(li_b, 0, state);
	if (verbose == 1)
		register_add_back(&state->seq, register_new(11));
}

/*
**	 pa/pb
*/

void	transfer_top(t_list **li_a, t_list **li_b, int verbose, t_state *state)
{
	void	*tmp;

	if (*li_a == NULL)
		return ;
	tmp = ft_lstpop(li_a);
	ft_lstadd_front(li_b, ft_lstnew(tmp));
	ft_del(tmp);
	if (verbose == 1)
		register_add_back(&state->seq, register_new(4));
	if (verbose == 2)
		register_add_back(&state->seq, register_new(5));
}
