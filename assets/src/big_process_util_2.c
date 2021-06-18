/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_process_util_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:21:42 by adenhez           #+#    #+#             */
/*   Updated: 2021/06/18 09:57:59 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	tourniquet(t_state *state, t_tb_2 *toolbox)
{
	if (toolbox->sens == 0)
		shift_down(&state->li_b, 2, state);
	else if (toolbox->sens == 1)
		shift_up(&state->li_b, 2, state);
}

void	temp_loop(t_state *state, t_tb_2 *tb)
{
	while ((int)(state->li_b)->content != (int)tb->ch_max->content && tb->temp)
	{
		if ((int)(state->li_b)->content == (int)tb->temp->content
			&& ft_lstsize(tb->temp) > 2)
		{
			tb->reminder++;
			transfer_top(&state->li_b, &state->li_a, 2, state);
			shift_down(&state->li_a, 1, state);
			ft_lstpop(&tb->temp);
		}
		if ((int)(state->li_b)->content == (int)tb->prelast->content)
		{
			if (tb->remind_swap == 0)
				tb->remind_swap = 1;
			transfer_top(&state->li_b, &state->li_a, 2, state);
		}
		else if ((int)(state->li_b)->content
			== (int)tb->preprelast->content && tb->preprelast_and_prelast)
		{
			tb->remind_swap = 2;
			transfer_top(&state->li_b, &state->li_a, 2, state);
		}
		else
			tourniquet(state, tb);
	}
}

void	finalize_loop(t_state *state, t_tb_2 *toolbox)
{
	if (toolbox->remind_swap > 0)
	{
		sort_3_head(&state->li_a, 1, state);
		ft_lstshift(&toolbox->temp);
	}
	if (toolbox->remind_swap == 2)
		ft_lstshift(&toolbox->temp);
	ft_lstshift(&toolbox->temp);
}

void	li_a_reamenagement(t_state *state, t_tb_2 *toolbox)
{
	while (toolbox->reminder--)
		shift_up(&state->li_a, 1, state);
}

void	init_loop(t_state *state, t_tb_2 *toolbox)
{
	toolbox->ch_min = toolbox->temp;
	toolbox->tmp = toolbox->temp;
	toolbox->preprelast = pre_pre_last(toolbox->temp);
	toolbox->prelast = pre_last(toolbox->temp);
	toolbox->ch_max = ft_lstlast(toolbox->temp);
	toolbox->sens = optimized_shift(state->li_b, toolbox->ch_max);
	toolbox->remind_swap = 0;
	toolbox->preprelast_and_prelast
		= is_3_last_order(state->li_b, *toolbox);
}
