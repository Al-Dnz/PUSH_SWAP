/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:38:37 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/09 16:41:20 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	treat_min(t_list **li_b, t_list **li_a, t_list *li_min, t_state *state)
{
	int	sens;

	sens = optimized_shift(*li_b, li_min);
	while ((int)(*li_b)->content != (int)li_min->content)
	{
		if (sens == 0)
			shift_down(li_b, 2, state);
		else
			shift_up(li_b, 2, state);
	}
	transfer_top(li_b, li_a, 2, state);
	shift_down(li_a, 1, state);
}

void	treat_max(t_list **li_b, t_list **li_a, t_list *li_max, t_state *state)
{
	int	sens;

	sens = optimized_shift(*li_b, li_max);
	while ((int)(*li_b)->content != (int)li_max->content)
	{
		if (sens == 0)
			shift_down(li_b, 2, state);
		else
			shift_up(li_b, 2, state);
	}
	transfer_top(li_b, li_a, 2, state);
}

void	process_100(t_state *state)
{
	int		reminder;
	int		sens;
	t_reg	*ledger;
	t_list	*ch_min;
	t_list	*ch_max;
	t_list	*temp;

	ledger = NULL;
	brut_sort(&state->li_a, &state->li_b, &ledger, state);
	process_3(state);
	temp = NULL;
	ch_min = NULL;
	ch_max = NULL;
	while (ledger)
	{
		lst_cpy(&temp, state->li_b, ledger->n);
		list_merge_sort(&temp);
		reminder = 0;
		sens = 0;
		while (temp)
		{
			ch_min = temp;
			ch_max = ft_lstlast(temp);
			sens = optimized_shift(state->li_b, ch_max);
			while ((int)(state->li_b)->content != (int)ch_max->content)
			{
				if ((int)(state->li_b)->content == (int)ch_min->content)
				{
					reminder++;
					transfer_top(&state->li_b, &state->li_a, 2, state);
					shift_down(&state->li_a, 1, state);
					temp = temp->next;
				}
				else if (sens == 0)
					shift_down(&state->li_b, 2, state);
				else
					shift_up(&state->li_b, 2, state);
			}
			transfer_top(&state->li_b, &state->li_a, 2, state);
			ft_lstshift(&temp);
		}
		while (reminder--)
			shift_up(&state->li_a, 1, state);
		ledger = ledger->next;
	}
}
