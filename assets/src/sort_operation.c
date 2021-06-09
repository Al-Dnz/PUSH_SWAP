/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:22:41 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/09 16:13:22 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	sa/sb/ss
*/

void	swap_list(t_list *li, int verbose, t_state *state)
{
	t_reg	*last_seq;
	void	*tmp;

	if (li == NULL || li->next == NULL)
		return ;
	tmp = li->content;
	li->content = li->next->content;
	li->next->content = tmp;
	ft_del(tmp);
	last_seq = register_last(state->seq);
	if (verbose == 1 && last_seq && last_seq->n == 2)
		last_seq->n = 3;
	else if (verbose == 2 && last_seq && last_seq->n == 1)
		last_seq->n = 3;
	else if (verbose == 1 || verbose == 2)
		register_add_back(&state->seq, register_new(verbose));
}

void	double_swap_list(t_list *li_a, t_list *li_b,
		int verbose, t_state *state)
{
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
	t_list	*new;
	t_reg	*last_seq;
	void	*tmp;

	if (*li == NULL || ft_lstsize(*li) < 2)
		return ;
	tmp = ft_lstshift(li);
	new = ft_lstnew(tmp);
	ft_lstadd_front(li, new);
	ft_del(tmp);
	last_seq = register_last(state->seq);
	if (verbose == 1 && last_seq && last_seq->n == 7)
		last_seq->n = 8;
	else if (verbose == 2 && last_seq && last_seq->n == 6)
		last_seq->n = 8;
	else if (verbose == 1 || verbose == 2)
		register_add_back(&state->seq, register_new(verbose + 5));
}

void	double_shift_up(t_list **li_a, t_list **li_b,
		int verbose, t_state *state)
{
	shift_up(li_a, 0, state);
	shift_up(li_b, 0, state);
	if (verbose == 1)
		register_add_back(&state->seq, register_new(8));
}
