/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:38:37 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/15 12:57:18 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*pre_last(t_list *li)
{
	if (li == NULL)
		return (NULL);
	while (li && li->next && li->next->next)
		li = li->next;
	return (li);
}

t_list	*pre_pre_last(t_list *li)
{
	if (li == NULL)
		return (NULL);
	while (li && li->next && li->next->next && li->next->next->next)
		li = li->next;
	return (li);
}

void	process_100(t_state *state)
{
	t_reg	*ledger;

	ledger = NULL;
	brut_sort(&state->li_a, &state->li_b, &ledger, state);
	process_3(state);
	main_process(state, ledger);
	register_clear(&ledger);
}
