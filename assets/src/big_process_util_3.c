/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process_util_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:21:36 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/15 13:21:38 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_3_last_order(t_list *li_b, t_tb_2 tb)
{
	int			n;
	static int	arr[3] = {0, 0, 0};

	n = 0;
	if (li_b == NULL || tb.ch_max == NULL
		|| tb.prelast == NULL || tb.preprelast == NULL)
		return (0);
	while (li_b)
	{
		if ((int)li_b->content == (int)tb.preprelast->content)
			arr[0] = ++n;
		if ((int)li_b->content == (int)tb.prelast->content)
			arr[1] = ++n ;
		if ((int)li_b->content == (int)tb.ch_max->content)
			arr[2] = ++n ;
		li_b = li_b->next;
	}
	if (n != 3)
		return (0);
	if (tb.sens == 0 && arr[2] == 3 && arr[1] == 2 && arr[0] == 1)
		return (1);
	if (tb.sens == 1 && arr[2] == 1 && arr[1] == 2 && arr[0] == 3)
		return (1);
	return (0);
}

void	sort_3_head(t_list **li, int verbose, t_state *state)
{
	state->a = (int)(*li)->content;
	state->b = (int)(*li)->next->content;
	state->c = (int)(*li)->next->next->content;
	if (state->a > state->b && state->b < state->c && state->c > state->a)
		swap_list(*li, verbose, state);
	else if (state->b > state->a && state->b > state->c)
	{
		shift_down(li, verbose, state);
		swap_list(*li, verbose, state);
		shift_up(li, verbose, state);
		if (state->a > state->c)
			swap_list(*li, verbose, state);
	}
	else if (state->a > state->b && state->a > state->c)
	{
		swap_list(*li, verbose, state);
		shift_down(li, verbose, state);
		swap_list(*li, verbose, state);
		shift_up(li, verbose, state);
		if (state->b > state->c)
			swap_list(*li, verbose, state);
	}
}

void	set_toolbox(t_tb_2 *toolbox)
{
	toolbox->temp = NULL;
	toolbox->ch_min = NULL;
	toolbox->ch_max = NULL;
	toolbox->prelast = NULL;
	toolbox->preprelast = NULL;
}

void	main_process(t_state *state, t_reg *ledger)
{
	t_tb_2	toolbox;

	set_toolbox(&toolbox);
	while (ledger)
	{
		lst_cpy(&toolbox.temp, state->li_b, ledger->n);
		list_merge_sort(&toolbox.temp);
		toolbox.reminder = 0;
		toolbox.sens = 0;
		while (toolbox.temp)
		{
			init_loop(state, &toolbox);
			temp_loop(state, &toolbox);
			transfer_top(&state->li_b, &state->li_a, 2, state);
			finalize_loop(state, &toolbox);
		}
		ft_lstclear(&toolbox.temp, ft_del);
		li_a_reamenagement(state, &toolbox);
		ledger = ledger->next;
	}
}
